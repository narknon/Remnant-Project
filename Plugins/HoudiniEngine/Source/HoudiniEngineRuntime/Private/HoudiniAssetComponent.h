/*
* Copyright (c) <2017> Side Effects Software Inc.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
*
*/

#pragma once

#include "HAPI.h"
#include "HoudiniGeoPartObject.h"
#include "HoudiniRuntimeSettings.h"
#include "HoudiniCookHandler.h"

#include "CoreMinimal.h"
#include "Landscape.h"
#include "TimerManager.h"
#include "Components/PrimitiveComponent.h"
#if WITH_EDITOR
#include "Factories/Factory.h"
#endif
#include "PhysicsEngine/BodySetup.h"
#include "HoudiniAssetComponent.generated.h"

class UBlueprint;
class UStaticMesh;
class UHoudiniAsset;
class UObjectProperty;
class USplineComponent;
class UInstancedStaticMeshComponent;
class UPhysicalMaterial;
class UHoudiniAssetInput;
class AHoudiniAssetActor;
class UHoudiniAssetHandle;
class UStaticMeshComponent;
class UHoudiniAssetParameter;
class UHoudiniHandleComponent;
class UHoudiniSplineComponent;
class UHoudiniAssetInstanceInput;
class UHoudiniAssetInstanceInputField;
class UHoudiniAssetComponentMaterials;
class UFoliageType_InstancedStaticMesh;

struct FTransform;
struct FPropertyChangedEvent;
struct FWalkableSlopeOverride;


namespace EHoudiniAssetComponentState
{
    /** This enumeration represents a state of component when it is serialized. **/

    enum Enum
    {
        /** Invalid type corresponds to state when component has been created, but is in invalid state. It had no **/
        /** Houdini asset assigned. Typically this will be the case when component instance is a default class    **/
        /** object or belongs to an actor instance which is a default class object also.                          **/
        Invalid,

        /** None type corresponds to state when component has been created, but corresponding Houdini asset has not **/
        /** been instantiated.                                                                                      **/
        None,

        /** This type corresponds to a state when component has been created, corresponding Houdini asset has been **/
        /** instantiated, and component has no pending asynchronous cook request.                                  **/
        Instantiated,

        /** This type corresponds to a state when component has been created, corresponding Houdini asset has been **/
        /** instantiated, and component has a pending asynchronous cook in progress.                               **/
        BeingCooked
    };
}


UCLASS( ClassGroup = (Rendering, Common), hidecategories = (Object,Activation,"Components|Activation"),
    ShowCategories = (Mobility), editinlinenew )
class HOUDINIENGINERUNTIME_API UHoudiniAssetComponent : public UPrimitiveComponent, public IHoudiniCookHandler
{
    friend class AHoudiniAssetActor;
    friend struct FHoudiniEngineUtils;
    friend class FHoudiniMeshSceneProxy;
    friend class UHoudiniHandleComponent;
    friend class UHoudiniSplineComponent;
    
#if WITH_EDITOR

    friend class FHoudiniAssetComponentDetails;
    friend class FHoudiniAssetTypeActions;

#endif

    GENERATED_UCLASS_BODY()

    virtual ~UHoudiniAssetComponent();

    /** Static mesh generation properties.**/
    public:

        /** If true, the physics triangle mesh will use double sided faces when doing scene queries. */
        UPROPERTY( EditAnywhere,
            Category = HoudiniGeneratedStaticMeshSettings,
            meta = ( DisplayName = "Double Sided Geometry" ) )
        uint32 bGeneratedDoubleSidedGeometry : 1;

        /** Physical material to use for simple collision on this body. Encodes information about density, friction etc. */
        UPROPERTY( EditAnywhere,
            Category = HoudiniGeneratedStaticMeshSettings,
            meta = ( DisplayName = "Simple Collision Physical Material" ) )
        UPhysicalMaterial * GeneratedPhysMaterial;

    /** Default properties of the body instance, copied into objects on instantiation, was URB_BodyInstance */
    UPROPERTY(EditAnywhere, Category = HoudiniGeneratedStaticMeshSettings, meta = ( FullyExpand = "true" ))
    struct FBodyInstance DefaultBodyInstance;

        /** Collision Trace behavior - by default, it will keep simple(convex)/complex(per-poly) separate. */
        UPROPERTY( EditAnywhere,
            Category = HoudiniGeneratedStaticMeshSettings,
            meta = ( DisplayName = "Collision Complexity" ) )
        TEnumAsByte< enum ECollisionTraceFlag > GeneratedCollisionTraceFlag;

        /** Resolution of lightmap. */
        UPROPERTY( EditAnywhere,
            Category = HoudiniGeneratedStaticMeshSettings,
            meta = ( DisplayName = "Light Map Resolution", FixedIncrement = "4.0" ) )
        int32 GeneratedLightMapResolution;
        
        /** Bias multiplier for Light Propagation Volume lighting. */
        UPROPERTY( EditAnywhere, BlueprintReadOnly,
            Category = HoudiniGeneratedStaticMeshSettings,
            meta = ( DisplayName = "Lpv Bias Multiplier", UIMin = "0.0", UIMax = "3.0" ) )
        float GeneratedLpvBiasMultiplier;

        /** Mesh distance field resolution, setting it to 0 will prevent the mesh distance field generation while editing the asset **/
        UPROPERTY(EditAnywhere,
            Category = HoudiniGeneratedStaticMeshSettings,
            meta = (DisplayName = "Distance Field Resolution Scale", UIMin = "0.0", UIMax = "100.0"))
            float GeneratedDistanceFieldResolutionScale;

        /** Custom walkable slope setting for generated mesh's body. */
        UPROPERTY( EditAnywhere, AdvancedDisplay,
            Category = HoudiniGeneratedStaticMeshSettings,
            meta = ( DisplayName = "Walkable Slope Override" ) )
        FWalkableSlopeOverride GeneratedWalkableSlopeOverride;

        /** The light map coordinate index. */
        UPROPERTY( EditAnywhere, AdvancedDisplay,
            Category = HoudiniGeneratedStaticMeshSettings,
            meta = ( DisplayName = "Light map coordinate index" ) )
        int32 GeneratedLightMapCoordinateIndex;

        /** True if mesh should use a less-conservative method of mip LOD texture factor computation. */
        UPROPERTY( EditAnywhere, AdvancedDisplay,
            Category = HoudiniGeneratedStaticMeshSettings,
            meta = ( DisplayName = "Use Maximum Streaming Texel Ratio" ) )
        uint32 bGeneratedUseMaximumStreamingTexelRatio : 1;

        /** Allows artists to adjust the distance where textures using UV 0 are streamed in/out. */
        UPROPERTY( EditAnywhere, AdvancedDisplay,
            Category = HoudiniGeneratedStaticMeshSettings,
            meta = ( DisplayName = "Streaming Distance Multiplier" ) )
        float GeneratedStreamingDistanceMultiplier;

        /** Default settings when using this mesh for instanced foliage. */
        UPROPERTY( EditAnywhere, AdvancedDisplay, Instanced,
            Category = HoudiniGeneratedStaticMeshSettings,
            meta = ( DisplayName = "Foliage Default Settings" ) )
        UFoliageType_InstancedStaticMesh * GeneratedFoliageDefaultSettings;

        /** Array of user data stored with the asset. */
        UPROPERTY( EditAnywhere, AdvancedDisplay, Instanced,
            Category = HoudiniGeneratedStaticMeshSettings,
            meta = ( DisplayName = "Asset User Data" ) )
        TArray<UAssetUserData*> GeneratedAssetUserData;

public:

        /** Change the Houdini Asset used by this component. **/
        virtual void SetHoudiniAsset( UHoudiniAsset * NewHoudiniAsset );

        /** Returns true if this component has any sockets */
        virtual bool HasAnySockets() const;

        /** Get a list of sockets this component contains   */
        virtual void QuerySupportedSockets( TArray< FComponentSocketDescription >& OutSockets ) const;

        /** Returns true if this component has the desired socket */
        virtual bool DoesSocketExist( FName SocketName ) const;

        /** Returns the transform for the desired socket */
        virtual FTransform GetSocketTransform( FName InSocketName, ERelativeTransformSpace TransformSpace ) const;

        /** Assign generation parameters to static mesh. **/
        void SetStaticMeshGenerationParameters( class UStaticMesh * StaticMesh ) const override;

#if WITH_EDITOR

        /** Start cooking / instantiation ticking. **/
        void StartHoudiniTicking();

        /** Return true if this component has no cooking or instantiation in progress. **/
        bool IsInstantiatingOrCooking() const;

        /** Return true if this component's asset has been instantiated, but not cooked. **/
        bool HasBeenInstantiatedButNotCooked() const;

        /** Ticking function to check cooking / instatiation status. **/
        void TickHoudiniComponent();

        /** Ticking function to check whether UI update can be performed. This is necessary so that widget which has **/
        /** captured the mouse does not lose it. **/
        void TickHoudiniUIUpdate();

        /** Refresh editor's detail panel and update properties. **/
        void UpdateEditorProperties( bool bConditionalUpdate );

        /** Callback used by parameters to notify component about their changes. **/
        void NotifyParameterChanged( UHoudiniAssetParameter * HoudiniAssetParameter );

        /** Notification used by spline visualizer to notify main Houdini asset component about spline change. **/
        void NotifyHoudiniSplineChanged( UHoudiniSplineComponent * HoudiniSplineComponent );

        /** Used by Blueprint baking; create temporary actor and necessary components to bake a blueprint. **/
        AActor * CloneComponentsAndCreateActor();

        /** Return true if cooking is enabled for this component. **/
        bool IsCookingEnabled() const;

        /** Start asset instantiation task. **/
        void StartTaskAssetInstantiation( bool bLoadedComponent = false, bool bStartTicking = false );

        /** Start manual asset cooking task. **/
        void StartTaskAssetCookingManual();

        /** Start manual asset rebuild task. **/
        void StartTaskAssetRebuildManual();
#endif

        /** Used to differentiate native components from dynamic ones. **/
        void SetNative( bool InbIsNativeComponent );

        /** Return id of a Houdini asset. **/
        UFUNCTION( BlueprintCallable, Category = HoudiniAsset )
        int32 GetAssetId() const;

        /** Set id of a Houdini asset. **/
        void SetAssetId( HAPI_NodeId InAssetId );

        /** Return true if asset id is valid. **/
        bool HasValidAssetId() const;

        /** Returns true if the asset is valid for cook/bake **/
        bool IsComponentValid() const;

        /** Invalidates the assets, causing it to be reinstantiated upon recook **/
        void NotifyAssetNeedsToBeReinstantiated();

        /** Return current referenced Houdini asset. **/
        UHoudiniAsset * GetHoudiniAsset() const;

        /** Return owner Houdini actor. **/
        AHoudiniAssetActor * GetHoudiniAssetActorOwner() const;

        /** Return true if this component contains Houdini logo geometry. **/
        bool ContainsHoudiniLogoGeometry() const;

        /** Return all static meshes used by this component. For both instanced and uinstanced components. **/
        void GetAllUsedStaticMeshes( TArray< UStaticMesh * > & UsedStaticMeshes );

        /** Return all the UStaticMeshComponent & UInstancedStataicMeshComponent owned by the actor, along with their associated parts */
        TMap<const UStaticMeshComponent *, FHoudiniGeoPartObject> CollectAllStaticMeshComponents() const;

        /** Return all the UHoudiniInstancedActorComponents that have content */
        TMap<const class UHoudiniInstancedActorComponent *, FHoudiniGeoPartObject> CollectAllInstancedActorComponents() const;

        /** Return all the UHoudiniMeshSplitInstancerComponent that have content */
        TMap<const class UHoudiniMeshSplitInstancerComponent *, FHoudiniGeoPartObject> CollectAllMeshSplitInstancerComponents() const;

        /** Returns all the instance input field for this asset **/
        const TArray< UHoudiniAssetInstanceInputField * > GetAllInstanceInputFields() const;

        /** Return true if global setting scale factors are different from the ones used for this component. **/
        bool CheckGlobalSettingScaleFactors() const;

    public:

        /** Locate static mesh by geo part object name. By default will use substring matching. **/
        bool LocateStaticMeshes(
            const FString & ObjectName,
            TMap< FString, TArray< FHoudiniGeoPartObject > > & InOutObjectsToInstance,
            bool bSubstring = true ) const;

        /** Locate static mesh by geo part object id. **/
        bool LocateStaticMeshes( int32 ObjectToInstanceId, TArray< FHoudiniGeoPartObject > & InOutObjectsToInstance ) const;

        /** Locate static mesh for a given geo part. **/
        UStaticMesh * LocateStaticMesh( const FHoudiniGeoPartObject & HoudiniGeoPartObject, const bool& ExactSearch = true ) const;

        FORCEINLINE const TMap< FHoudiniGeoPartObject, UStaticMesh * >& GetStaticMeshes() const { return StaticMeshes; }

        /** Locate static mesh component for given static mesh. **/
        UStaticMeshComponent * LocateStaticMeshComponent( const UStaticMesh * StaticMesh ) const;

        /** Locate instanced static mesh components for given static mesh. **/
        bool LocateInstancedStaticMeshComponents( const UStaticMesh * StaticMesh, TArray< UInstancedStaticMeshComponent * > & Components ) const;

        /** Locate geo part object for given static mesh. Reverse map search. **/
        FHoudiniGeoPartObject LocateGeoPartObject( UStaticMesh * StaticMesh ) const;

        /** Locate spline component for a given geo part. **/
        UHoudiniSplineComponent * LocateSplineComponent(const FHoudiniGeoPartObject & HoudiniGeoPartObject) const;

        /** Return true if this component is in playmode. **/
        bool IsPIEActive() const;

        /** Return component GUID. **/
        const FGuid& GetComponentGuid() const;

        /** If given material has been replaced for a given geo part object, return it. Otherwise return null. **/
        class UMaterialInterface * GetReplacementMaterial(
            const FHoudiniGeoPartObject & HoudiniGeoPartObject, 
            const FString & MaterialName );

        /** If given material has been replaced for a given geo part object, return its name by reference. **/
        bool GetReplacementMaterialShopName(
            const FHoudiniGeoPartObject & HoudiniGeoPartObject, 
            class UMaterialInterface * MaterialInterface, FString & MaterialName);

        /** Given a shop name return material assignment. **/
        class UMaterialInterface * GetAssignmentMaterial( const FString & MaterialName ) override;

        /** Clear the assignment material cache */
        void ClearAssignmentMaterials() override;

        /** Add a material for the given shop name */
        void AddAssignmentMaterial( const FString& MaterialName, class UMaterialInterface* MaterialInterface ) override;

        /** Material Change **/
        virtual void SetMaterial(int32 ElementIndex, class UMaterialInterface* Material) override;

        /** Perform material replacement. **/
        bool ReplaceMaterial(
            const FHoudiniGeoPartObject & HoudiniGeoPartObject, class UMaterialInterface * NewMaterialInterface,
            class UMaterialInterface * OldMaterialInterface, int32 MaterialIndex );

        /** Remove material replacement. **/
        void RemoveReplacementMaterial( const FHoudiniGeoPartObject & HoudiniGeoPartObject, const FString & MaterialName );

        /** Handle the creation/update of material instance via attributes **/
        bool CreateOrUpdateMaterialInstances();

        /** Collect all Substance parameters. **/
        void CollectSubstanceParameters( TMap< FString, UHoudiniAssetParameter * > & SubstanceParameters ) const;

        /** Collect all parameters of a given type. **/
        void CollectAllParametersOfType( UClass * ParameterClass, TMap< FString, UHoudiniAssetParameter * > & ClassParameters ) const;

        /** Locate parameter by name. **/
        UHoudiniAssetParameter * FindParameter( const FString & ParameterName ) const;

        FORCEINLINE const TArray< UHoudiniAssetInput* >& GetInputs() const { return Inputs; }

        /** Returns an array containing all the inputs (including the object path parameters)**/
        void GetInputs(TArray< UHoudiniAssetInput* >& AllInputs, bool IncludeObjectPathParameter = true );

        /** Returns the path to the baking folder */
        FText GetBakeFolder() const;

        /** Sets a new bake folder */
        void SetBakeFolder( const FString& Folder );

        /** Returns the path to the temporary cooking folder */
        FText GetTempCookFolder() const;

        FString GetBakingBaseName( const FHoudiniGeoPartObject& GeoPartObject ) const override;

        /** Is the asset still waiting for upstream asset to finish instantiating **/
        bool UpdateWaitingForUpstreamAssetsToInstantiate( bool bNotifyUpstreamAsset = false );

        /** Updates the HAC's mobility depending on its children's mobility **/
        void UpdateMobility();

    /** UObject methods. **/
    public:

#if WITH_EDITOR

        virtual void PostEditChangeProperty( FPropertyChangedEvent & PropertyChangedEvent ) override;
        virtual void PostEditUndo() override;
        virtual void PostEditImport() override;
        virtual void PostLoad() override;
        virtual void PostInitProperties() override;
    /** UActorComponent methods. **/
    protected:

        virtual void OnComponentCreated() override;
        virtual void OnComponentDestroyed(bool bDestroyingHierarchy) override;
        virtual void OnRegister() override;
#endif
        virtual void Serialize( FArchive & Ar ) override;
        static void AddReferencedObjects( UObject * InThis, FReferenceCollector & Collector );

    /** USceneComponent methods. **/
    private:

        virtual FBoxSphereBounds CalcBounds( const FTransform & LocalToWorld ) const override;
#if WITH_EDITOR
        virtual void OnUpdateTransform( EUpdateTransformFlags UpdateTransformFlags, ETeleportType Teleport ) override;
#endif

    private:

        /** Update rendering information. **/
        void UpdateRenderingInformation();

        /** Re-attach components after loading or copying. **/
        void PostLoadReattachComponents();

#if WITH_EDITOR

        /** Called after each cook. **/
        void PostCook( bool bCookError = false );

        /** Check ourselves over and fix up any errors */
        void SanitizePostLoad();

        /** Remove all attached components. **/
        void RemoveAllAttachedComponents();

        /** If we are being copied from a component, transfer necessary state. **/
        void OnComponentClipboardCopy( UHoudiniAssetComponent * HoudiniAssetComponent );

        /** Delegate for asset post import. **/
        void OnAssetPostImport( UFactory * Factory, UObject * Object );

        /** Delegate to handle drag and drop events. **/
        void OnApplyObjectToActor( UObject * ObjectToApply, AActor * ActorToApplyTo );

        /** Delegate to handle asset actor movement */
        void OnActorMoved( AActor* Actor );

        /** Subscribe to Editor events. **/
        void SubscribeEditorDelegates();

        /** Unsubscribe from Editor events. **/
        void UnsubscribeEditorDelegates();

        /** Stop cooking / instantiation ticking. **/
        void StopHoudiniTicking();

        /** Start UI update ticking. **/
        void StartHoudiniUIUpdateTicking();

        /** Stop UI update ticking. **/
        void StopHoudiniUIUpdateTicking();

        /** Assign actor label based on asset instance name. **/
        void AssignUniqueActorLabel();

        /** Reset all Houdini related information, the asset, cooking trackers, generated geometry, related state, etc. **/
        void ResetHoudiniResources();

        /** Start manual asset reset task. **/
        void StartTaskAssetResetManual();

        /** Start asset deletion task. **/
        void StartTaskAssetDeletion();

        /** Start asset cooking task. **/
        void StartTaskAssetCooking( bool bStartTicking = false );

        /** Create default preset buffer. **/
        void CreateDefaultPreset();

        /** Create curves. **/
        void CreateCurves( const TArray< FHoudiniGeoPartObject > & Curves );

        /** Create new parameters and attempt to reuse existing ones. **/
        void CreateParameters();

        /** Create handles.**/
        bool CreateHandles();

        /** Create all landscapes in the GeoPartObject array **/
        bool CreateAllLandscapes( const TArray< FHoudiniGeoPartObject > & FoundVolumes );

        /** Updates the materials for a newly created landscape **/
        void UpdateLandscapeMaterialsAssignementsAndReplacements(ALandscapeProxy* Landscape, FHoudiniGeoPartObject Heightfield );

        /** Unmark all changed parameters. **/
        void UnmarkChangedParameters();

        /** Upload changed parameters back to HAPI. **/
        void UploadChangedParameters();

        /** If parameters were loaded, they need to be updated with proper ids after HAPI instantiation. **/
        void UpdateLoadedParameters();

        /** Create inputs. Number of inputs for asset does not change. **/
        void CreateInputs();

        /** If inputs were loaded, they need to be updated and assigned geos need to be connected. **/
        void UpdateLoadedInputs( const bool& ForceRefresh );

        /** If curves were loaded, their points need to be uploaded. **/
        void UploadLoadedCurves();

        /** Refreshes editables nodes after loading the level **/
        bool RefreshEditableNodesAfterLoad();

        /** Find an instance input for the given geo part */
        UHoudiniAssetInstanceInput* LocateInstanceInput( const FHoudiniGeoPartObject& GeoPart ) const;

        /** Create instance inputs. **/
        void CreateInstanceInputs( const TArray< FHoudiniGeoPartObject > & Instancers );

        /** Duplicate all parameters. Used during copying. **/
        void DuplicateParameters( UHoudiniAssetComponent * DuplicatedHoudiniComponent );

        /** Duplicate all handles. Used during copying. **/
        void DuplicateHandles( UHoudiniAssetComponent * DuplicatedHoudiniComponent );

        /** Duplicate inputs. Used during copying. **/
        void DuplicateInputs( UHoudiniAssetComponent * DuplicatedHoudiniComponent );

        /** Duplicate instance inputs. Used during copying. **/
        void DuplicateInstanceInputs( UHoudiniAssetComponent * DuplicatedHoudiniComponent, const TMap<UObject*, UObject*>& ReplacementMap );

        /** Helper called when world transform changes */
        void CheckedUploadTransform();

        /** Per-part overrides for baking file name */
        void SetBakingBaseNameOverride( const FHoudiniGeoPartObject& GeoPartObject, const FString& BaseName );
        bool RemoveBakingBaseNameOverride( const FHoudiniGeoPartObject& GeoPartObject );

        /** Apply the preset input for HoudiniTools**/
        void ApplyHoudiniToolInputPreset();
#endif

        /** Clear all spline related resources. **/
        void ClearCurves();

        /** Clear all parameters. **/
        void ClearParameters();

        /** Clear handles. **/
        void ClearHandles();

        /** Clear all inputs. **/
        void ClearInputs();

        /** Clear all instance inputs. **/
        void ClearInstanceInputs();

        /** Inform downstream assets that we are dieing. **/
        void ClearDownstreamAssets();

        /** Clear cooked content temp files **/
        void ClearCookTempFile();

        /** Delete Static mesh resources. This will free static meshes and corresponding components. **/
        void ReleaseObjectGeoPartResources(
            TMap< FHoudiniGeoPartObject, UStaticMesh * > & StaticMeshMap, 
            bool bDeletePackages = false );

        /** Return true if given object is referenced locally only, by objects generated and owned by this component. **/
        bool IsObjectReferencedLocally( UStaticMesh * StaticMesh, FReferencerInformationList & Referencers ) const;

    public:

        /** Clear all landscapes **/
        void ClearLandscapes();

        /** Add to the list of dependent downstream assets that have this asset as an asset input. **/
        void AddDownstreamAsset( UHoudiniAssetComponent * InDownstreamAssetComponent, int32 InInputIndex );

        /** Remove from the list of dependent downstream assets that have this asset as an asset input. **/
        void RemoveDownstreamAsset( UHoudiniAssetComponent * InDownstreamAssetComponent, int32 InInputIndex );

        /** Create Static mesh resources. This will create necessary components for each mesh and update maps. **/
        void CreateObjectGeoPartResources( TMap< FHoudiniGeoPartObject, UStaticMesh * > & StaticMeshMap );

        /** Delete Static mesh resources. This will free static meshes and corresponding components. **/
        void ReleaseObjectGeoPartResources( bool bDeletePackages = false );

        /** Check all the attached StaticMeshComponents to delete invalid ones **/
        void CleanUpAttachedStaticMeshComponents();

        /** Create Static mesh resource which corresponds to Houdini logo. **/
        void CreateStaticMeshHoudiniLogoResource( TMap< FHoudiniGeoPartObject, UStaticMesh * > & StaticMesDhMap );

        /** Serialize inputs. **/
        void SerializeInputs( FArchive & Ar );

        /** Serialize instance inputs. **/
        void SerializeInstanceInputs( FArchive & Ar );

        /** Serialize parameters. **/
        void SerializeParameters( FArchive & Ar );

        /** Used to perform post loading initialization on instance inputs. **/
        void PostLoadInitializeInstanceInputs();

        /** Used to perform post loading initialization of parameters. **/
        void PostLoadInitializeParameters();

        /** Remove static mesh and associated component and deallocate corresponding resources. **/
        void RemoveStaticMeshComponent( UStaticMesh * StaticMesh );

        /** Returns the AABB for the asset component and its inputs **/
        FBox GetAssetBounds( UHoudiniAssetInput* IgnoreInput = nullptr, const bool& bIgnoreGeneratedLandscape = false) const;

        /** Return true if this Houdini asset component has a landscape **/
        bool HasLandscape() const { return ( LandscapeComponents.Num() > 0 ); }

        /** Returns true if the landscape actor has been created by this asset **/
        bool HasLandscapeActor(ALandscapeProxy* LandscapeActor) const;

        /** Returns a pointer to the landscape component map **/
        TMap< FHoudiniGeoPartObject, TWeakObjectPtr<ALandscapeProxy> > * GetLandscapeComponents();

        /** Set the preset Input for HoudiniTools **/
        void SetHoudiniToolInputPresets( const TMap< UObject*, int32 >& InPresets );

        /** Replaces references to a landscape actor by the newly generated one **/
        bool ReplaceLandscapeInInputs(ALandscapeProxy* Old, ALandscapeProxy* New );

        /** From UPrimitiveComponent Interface. **/
        virtual FPrimitiveSceneProxy* CreateSceneProxy() override;

    private:

        /** This flag is used when Houdini engine is not initialized to display a popup message once. **/
        static bool bDisplayEngineNotInitialized;

        /** This flag is used when Hapi version mismatch is detected (between defined and running versions. **/
        static bool bDisplayEngineHapiVersionMismatch;

    public:

        /** Houdini Asset associated with this component. **/
        UHoudiniAsset * HoudiniAsset;

        /** Indicates a manual recook has been asked by the user **/
        bool bManualRecookRequested;

        /** Transient cache of last baked parts */
        TMap<FHoudiniGeoPartObject, TWeakObjectPtr<class UPackage> > BakedStaticMeshPackagesForParts;
        /** Transient cache of last baked materials and textures */
        TMap<FString, TWeakObjectPtr<class UPackage> > BakedMaterialPackagesForIds;

        /** Cache of the temp cook content packages created by the asset for its meshes                             **/
        TMap<FHoudiniGeoPartObject, TWeakObjectPtr<class UPackage> > CookedTemporaryStaticMeshPackages;
        /** Cache of the temp cook content packages created by the asset for its materials/textures                 **/
        TMap<FString, TWeakObjectPtr<class UPackage> > CookedTemporaryPackages;
        /** Cache of the temp cook content packages created by the asset for its Landscape layers                   **/
        /** As packages are unique their are used as the key (we can have multiple package for the same geopartobj  **/
        TMap< TWeakObjectPtr<class UPackage> , FHoudiniGeoPartObject > CookedTemporaryLandscapeLayers;

        /** Indicates that the details panels doesn't need a "full" update to avoid breaking parameter selection    **/
        /** (default behavior is true)                                                                              **/
        bool bEditorPropertiesNeedFullUpdate;

    protected:

        /** Previous asset, if it has been changed through transaction. **/
        UHoudiniAsset * PreviousTransactionHoudiniAsset;

        /** Parameters for this component's asset, indexed by parameter id. **/
        TMap< HAPI_ParmId, UHoudiniAssetParameter * > Parameters;

        /** Parameters for this component's asset, indexed by name for fast look up. **/
        TMap< FString, UHoudiniAssetParameter * > ParameterByName;

        /** Inputs for this component's asset. **/
        TArray< UHoudiniAssetInput * > Inputs;

        /** Instance inputs for this component's asset **/
        TArray< UHoudiniAssetInstanceInput * > InstanceInputs;

        /** List of dependent downstream asset connections that have this asset as an asset input. **/
        TMap< UHoudiniAssetComponent * , TSet< int32 > > DownstreamAssetConnections;

        /** Map of HAPI objects and corresponding static meshes. Also map of static meshes and corresponding components. **/
        TMap< FHoudiniGeoPartObject, UStaticMesh * > StaticMeshes;
        TMap< UStaticMesh *, UStaticMeshComponent * > StaticMeshComponents;

        /** Map of asset handle components. **/
        typedef TMap< FString, UHoudiniHandleComponent * > FHandleComponentMap;
        FHandleComponentMap HandleComponents;

        /** Map of curve / spline components. **/
        TMap< FHoudiniGeoPartObject, TWeakObjectPtr<UHoudiniSplineComponent> > SplineComponents;

        /** Map of Landscape / Heightfield components. **/
        TMap< FHoudiniGeoPartObject, TWeakObjectPtr<ALandscapeProxy> > LandscapeComponents;

        /** Material assignments. **/
        UHoudiniAssetComponentMaterials * HoudiniAssetComponentMaterials;

        /** Buffer to hold preset data for serialization purposes. Used only during serialization. **/
        TArray< char > PresetBuffer;

        /** Buffer to hold default preset for reset purposes. **/
        TArray< char > DefaultPresetBuffer;

        /** The output folder for baking actions */
        UPROPERTY()
        FText BakeFolder;

        /** The temporary output folder for cooking actions */
        UPROPERTY()
        FText TempCookFolder;

        /** overrides for baking names per part */
        TMap< FHoudiniGeoPartObject, FString > BakeNameOverrides;

        /** list of the modified uproperties per geopartobject **/
        //TMap< FHoudiniGeoPartObject, TArray< UPropertyAttribute > > ModifedUProperties;

#if WITH_EDITOR

        /** Notification used by this component. **/
        TWeakPtr< class SNotificationItem > NotificationPtr;

        /** Component from which this component has been copied. **/
        TWeakObjectPtr<UHoudiniAssetComponent> CopiedHoudiniComponent;

#endif

        /** Unique GUID created by component. **/
        FGuid ComponentGUID;

        /** GUID used to track asynchronous cooking requests. **/
        FGuid HapiGUID;

        /** Delegate handle returned by editor asset post import delegate. **/
        FDelegateHandle DelegateHandleAssetPostImport;

        /** Delegate to handle editor viewport drag and drop events. **/
        FDelegateHandle DelegateHandleApplyObjectToActor;

        /** Timer handle, this timer is used for cooking. **/
        FTimerHandle TimerHandleCooking;

        /** Timer delegate, we use it for ticking during cooking or instantiation. **/
        FTimerDelegate TimerDelegateCooking;

        /** Timer handle, this timer is used for UI updates. **/
        FTimerHandle TimerHandleUIUpdate;

        /** Timer delegate, we use it for checking if details panel update can be performed. **/
        FTimerDelegate TimerDelegateUIUpdate;

        /** Id of corresponding Houdini asset. **/
        HAPI_NodeId AssetId;

        /** Scale factor used for generated geometry of this component. **/
        float GeneratedGeometryScaleFactor;

        /** Scale factor used for geo transforms of this component. **/
        float TransformScaleFactor;

        /** Import axis. **/
        EHoudiniRuntimeSettingsAxisImport ImportAxis;

        /** Used to delay notification updates for HAPI asynchronous work. **/
        double HapiNotificationStarted;

        /** Number of times this asset has been cooked. **/
        int32 AssetCookCount;

        /** Indicates the asset is being istantiated to avoid instantiating it twice on load **/
        bool bAssetIsBeingInstantiated;

        /** Indicates that new asset's mesh must rebuild the Navigation System to update the NavMesh properly **/
        bool bNeedToUpdateNavigationSystem;

        /** Map used to preset the asset's inputs for Houdini Tools, maps a UObject to an Input number **/
        TMap<UObject*, int32> HoudiniToolInputPreset;

        /** Flags used by Houdini component. **/
        union
        {
            struct
            {
                /** Enables cooking for this Houdini Asset. **/
                uint32 bEnableCooking : 1;

                /** Enables uploading of transformation changes back to Houdini Engine. **/
                uint32 bUploadTransformsToHoudiniEngine : 1;

                /** Enables cooking upon transformation changes. **/
                uint32 bTransformChangeTriggersCooks : 1;

                /** Is set to true when this component contains Houdini logo geometry. **/
                uint32 bContainsHoudiniLogoGeometry : 1;

                /** Is set to true when this component is native and false is when it is dynamic. **/
                uint32 bIsNativeComponent : 1;

                /** Is set to true when this component belongs to a preview actor. **/
                uint32 bIsPreviewComponent : 1;

                /** Is set to true if this component has been loaded. **/
                uint32 bLoadedComponent : 1;

                /** Unused **/
                uint32 bIsPlayModeActive_Unused : 1;

                /** unused flag **/
                uint32 bTimeCookInPlaymode_Unused : 1;

                /** Is set to true when Houdini materials are used. **/
                uint32 bUseHoudiniMaterials : 1;

                /** Is set to true when cooking this asset will trigger cooks of downstream connected assets. **/
                uint32 bCookingTriggersDownstreamCooks : 1;

                /** Is set to true after the asset is fully loaded and registered **/
                uint32 bFullyLoaded : 1;
            };

            uint32 HoudiniAssetComponentFlagsPacked;
        };

        /** Transient flags used by Houdini component. **/
        union
        {
            struct
            {
                /** Is set to true when component has been created as result of copying / import. **/
                uint32 bComponentCopyImported : 1;

                /** Is set when asset is changed during transaction. **/
                uint32 bTransactionAssetChange : 1;

                /** Is set to true when we are waiting for upstream input assets to instantiate. **/
                uint32 bWaitingForUpstreamAssetsToInstantiate : 1;

                /** Is set to true when one of the parameters has been modified. This will trigger recook. **/
                uint32 bParametersChanged : 1;

                /** Is set to true when the asset needs cooking after a parameter/transform change wasn't cooked. **/
                uint32 bComponentNeedsCook : 1;

                /** Is set to true when component is loaded and requires instantiation. **/
                uint32 bLoadedComponentRequiresInstantiation : 1;
            };

            uint32 HoudiniAssetComponentTransientFlagsPacked;
        };
};
