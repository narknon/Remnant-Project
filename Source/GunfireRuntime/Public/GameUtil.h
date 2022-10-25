#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "Camera/CameraTypes.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "ELevelContextFallback.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "ObjectArraySortPredicateDelegate.h"
#include "UObject/NoExportTypes.h"
#include "CachedMaterialState.h"
#include "UObject/NoExportTypes.h"
#include "EPlatform.h"
#include "Components/SceneComponent.h"
#include "ELocalizationLanguage.h"
#include "EBuildType.h"
#include "ActorQueryResult.h"
#include "ActorQueryFilter.h"
#include "GameUtil.generated.h"

class ULevel;
class UForceFeedbackEffect;
class AActor;
class UCurveFloat;
class USceneComponent;
class ACharacter;
class USkeletalMeshComponent;
class APlayerController;
class UPoseableMeshComponent;
class ULevelStreaming;
class USkinnedMeshComponent;
class UCameraShake;
class APawn;
class UBehaviorTree;
class UAdvancedDecalComponent;
class UShapeComponent;
class UMaterialInterface;
class UPrimitiveComponent;
class APlayerState;
class ALevelScriptActor;
class UGameViewportClientGunfire;
class UActorComponent;
class UWorld;
class APlayerStart;
class ACharacterGunfire;
class UDamageTypeGunfire;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UGameUtil : public UObject {
    GENERATED_BODY()
public:
    UGameUtil();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FRotator UE4ToAutodeskRotation(const FRotator& Rotation);
    
    UFUNCTION(BlueprintCallable)
    static void TransferPoseToSkeletalMesh(USkeletalMeshComponent* Source, USkeletalMeshComponent* Target);
    
    UFUNCTION(BlueprintCallable)
    static void TransferPoseToPoseableMesh(USkeletalMeshComponent* Source, UPoseableMeshComponent* Target);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool TestLineOfSightFromLocation(FVector Origin, AActor* to, const TArray<AActor*>& IgnoredActors);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool TestLineOfSight(AActor* from, AActor* to, const TArray<AActor*>& IgnoredActors);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static bool SweepCharacter(UObject* WorldContextObject, ACharacter* Character, const FVector& Start, const FVector& End, const TArray<AActor*>& IgnoredActors, const TArray<TEnumAsByte<ECollisionChannel>>& IgnoreChannels, const TArray<TEnumAsByte<ECollisionChannel>>& OverlapChannels, const TArray<TEnumAsByte<ECollisionChannel>>& BlockChannels, FHitResult& Hit, float RadiusOverride, float HalfHeightOverride, FVector SweepOffset, bool bMoveCharacter);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
    static bool StuckCheckForClass(UObject* WorldContextObject, FVector FeetLocation, TSubclassOf<ACharacter> CharacterClass, const TArray<AActor*>& IgnoredActors, float RadiusOverride);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
    static bool StuckCheck(UObject* WorldContextObject, FVector FeetLocation, const ACharacter* Character, const TArray<AActor*>& IgnoredActors, float RadiusOverride);
    
    UFUNCTION(BlueprintCallable)
    static void StreamInTextures(const FVector& Position);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static void StopForceFeedback(const UObject* WorldContextObject, UForceFeedbackEffect* ForceFeedbackEffect, FName Tag, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static void StopCameraShake(const UObject* WorldContextObject, TSubclassOf<UCameraShake> CameraShake, bool bSkipBlendOut, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static APawn* SpawnAIEx(UObject* WorldContextObject, TSubclassOf<APawn> PawnClass, UBehaviorTree* BehaviorTree, FVector Location, FRotator Rotation, bool bNoCollisionFail, ELevelContextFallback LevelContextFallback, AActor* LevelContext);
    
    UFUNCTION(BlueprintCallable)
    static UAdvancedDecalComponent* SpawnAdvancedDecalAttached(UMaterialInterface* DecalMaterial, FVector DecalSize, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, TEnumAsByte<EAttachLocation::Type> LocationType, float LifeSpan, UCurveFloat* EmissiveCurve, UCurveFloat* OpacityCurve, bool bSetLifespan);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static UAdvancedDecalComponent* SpawnAdvancedDecalAtLocation(const UObject* WorldContextObject, UMaterialInterface* DecalMaterial, FVector DecalSize, FVector Location, FRotator Rotation, float LifeSpan, UCurveFloat* EmissiveCurve, UCurveFloat* OpacityCurve, bool bSetLifespan);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static AActor* SpawnActorEx(UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, const FTransform& SpawnTransform, ESpawnActorCollisionHandlingMethod CollisionHandling, AActor* Owner, APawn* Instigator, bool Transient, ELevelContextFallback LevelContextFallback, AActor* LevelContext, ULevel* OverrideLevel);
    
    UFUNCTION(BlueprintCallable)
    static void SortObjectArray(UPARAM(Ref) TArray<UObject*>& Objects, const FObjectArraySortPredicate& Predicate);
    
    UFUNCTION(BlueprintCallable)
    static void SortIntArray(UPARAM(Ref) TArray<int32>& IntArray);
    
    UFUNCTION(BlueprintCallable)
    static void SortFloatArray(UPARAM(Ref) TArray<float>& FloatArray);
    
    UFUNCTION(BlueprintCallable)
    static void SortActorArrayByDistance(FVector Location, UPARAM(Ref) TArray<AActor*>& ActorArray);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static bool SnapToNavMesh(UObject* WorldContextObject, const FVector& Position, float Radius, FVector& SnappedPosition);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
    static bool SnapToGround(UObject* WorldContextObject, const FVector& Position, FVector& SnappedPosition, float Offset, float CastDistance, bool TraceComplex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool SnapCharacterToGround(ACharacter* Character, const FVector& Position, const TArray<AActor*>& IgnoredActors, float Offset, float CastDistance);
    
    UFUNCTION(BlueprintCallable)
    static void ShowRandomMesh(AActor* Actor, FName Slot, bool AllowNone);
    
    UFUNCTION(BlueprintCallable)
    static void ShowComponents(TArray<USceneComponent*> Components);
    
    UFUNCTION(BlueprintCallable)
    static bool ShouldAsyncLoad();
    
    UFUNCTION(BlueprintCallable)
    static void SetVisible(AActor* Actor, bool Visible);
    
    UFUNCTION(BlueprintCallable)
    static void SetVisibilityFlag(AActor* Actor, bool Active);
    
    UFUNCTION(BlueprintCallable)
    static void SetTickableWhenPaused(AActor* Actor, bool TickWhenPaused);
    
    UFUNCTION(BlueprintCallable)
    static void SetRenderCustomDepthForActor(AActor* Actor, bool bEnabled, uint8 Index, bool bPropagateToInventory);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaterialVectorParam(AActor* Actor, UMaterialInterface* Material, const FName& ParamName, FLinearColor Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetMaterialScalarParam(AActor* Actor, UMaterialInterface* Material, const FName& ParamName, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetComponentMaterialVectorParamForAll(UPrimitiveComponent* Component, const FName& ParamName, FLinearColor Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetComponentMaterialVectorParam(UPrimitiveComponent* Component, UMaterialInterface* Material, const FName& ParamName, FLinearColor Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetComponentMaterialScalarParamForAll(UPrimitiveComponent* Component, const FName& ParamName, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetComponentMaterialScalarParam(UPrimitiveComponent* Component, UMaterialInterface* Material, const FName& ParamName, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetAllMaterialsTo(AActor* Actor, UMaterialInterface* Material, UPARAM(Ref) TArray<FCachedMaterialState>& CachedMaterialStates, bool RecurseChildren);
    
    UFUNCTION(BlueprintCallable)
    static void SetActorsVisible(TArray<AActor*> Actors, bool Visible);
    
    UFUNCTION(BlueprintCallable)
    static void SetActive(AActor* Actor, bool Active);
    
    UFUNCTION(BlueprintCallable)
    static void ResetCachedMaterials(const TArray<FCachedMaterialState>& MaterialStates);
    
    UFUNCTION(BlueprintCallable)
    static void ResetActorDynamics(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveTag(AActor* Actor, FName Tag);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static void RemoveLevelInstanceByName(UObject* WorldContextObject, const FString& UniqueInstanceName);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static void RemoveLevelInstance(UObject* WorldContextObject, ULevelStreaming* LevelInstance);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static void PlayForceFeedback(const UObject* WorldContextObject, UForceFeedbackEffect* ForceFeedbackEffect, bool bLooping, bool bIgnoreTimeDilation, FName Tag, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static void PlayCameraShake(const UObject* WorldContextObject, TSubclassOf<UCameraShake> CameraShake, float Scale, TEnumAsByte<ECameraAnimPlaySpace::Type> PlaySpace, FRotator UserPlaySpaceRot, int32 PlayerIndex);
    
    UFUNCTION(BlueprintCallable)
    static UObject* LoadSoftReference(const TSoftObjectPtr<UObject>& SoftObjRef);
    
    UFUNCTION(BlueprintCallable)
    static UClass* LoadSoftClassReference(const TSoftClassPtr<UObject>& SoftClsRef);
    
    UFUNCTION(BlueprintCallable)
    static UObject* LoadObjectFromPath(FName Path);
    
    UFUNCTION(BlueprintCallable)
    static void LoadFileToString(const FString& File, FString& Contents, bool& bSuccessful);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static bool LineTraceByChannelWithContext(UObject* WorldContextObject, const FVector& Start, const FVector& End, TEnumAsByte<ECollisionChannel> TraceChannel, bool TraceComplex, FHitResult& Hit);
    
    UFUNCTION(BlueprintCallable)
    static void LatentDestroyActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static bool IsVisible(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsUsingTouchController();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsUsingKeyboardAndMouse();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsUsingGamepad();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSwimmingUnderwater(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSwimmingOnSurface(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSwimming(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static bool IsStereoEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsSoftDestroyed(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
    static bool IsSingleplayerGame(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static bool IsShippingBuild();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
    static bool IsPlayingCinematic(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static bool IsLocallyControlled(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsInWater(const ACharacter* Character);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsInEditor();
    
    UFUNCTION(BlueprintCallable)
    static bool IsHMDWorn();
    
    UFUNCTION(BlueprintCallable)
    static bool IsHDREnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsChildOfSoftClasses(AActor* Actor, const TArray<TSoftClassPtr<AActor>>& Classes);
    
    UFUNCTION(BlueprintCallable)
    static void InvokeEvent(UObject* Object, FName EventName);
    
    UFUNCTION(BlueprintCallable)
    static TArray<USceneComponent*> HideVisibleComponents(AActor* Actor, TSubclassOf<USceneComponent> ComponentClass, bool RecurseChildren);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasAnyRootMotion(ACharacter* Character);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasAnyRenderedSlaveMeshes(const USkinnedMeshComponent* Mesh);
    
    UFUNCTION(BlueprintCallable)
    static bool GetWaterSubmergeDepth(AActor* Actor, float& OutSubmergeDepth);
    
    UFUNCTION(BlueprintCallable)
    static FColor GetUniqueColor(int32 ColorIndex);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetScriptStack();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetPropertyValueAsFloat(UObject* Object, FName PropertyName, float& Value);
    
    UFUNCTION(BlueprintCallable)
    static FName GetPrefix(const FName& Name);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static TArray<APlayerState*> GetPlayerStates(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static TArray<APlayerController*> GetPlayerControllers(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static APlayerController* GetPlayerControllerForActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    static EPlatform GetPlatformSubType();
    
    UFUNCTION(BlueprintCallable)
    static EPlatform GetPlatform();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static ACharacter* GetOwningCharacter(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UObject* GetOwner(UObject* Object);
    
    UFUNCTION(BlueprintCallable)
    static bool GetObjectPath(UObject* Object, FString& Path);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
    static int32 GetNumConnectedPlayers(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static bool GetNodeTransform(const AActor* Actor, const FName& NodeName, FTransform& Transform, TEnumAsByte<ERelativeTransformSpace> TransformSpace);
    
    UFUNCTION(BlueprintCallable)
    static ELocalizationLanguage GetLocalizationLanguage();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static ALevelScriptActor* GetLevelScriptActor(ULevel* Level);
    
    UFUNCTION(BlueprintCallable)
    static FString GetLevelPathName(ULevel* Level);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static ULevelStreaming* GetLevelInstance(UObject* WorldContextObject, const FString& UniqueInstanceName);
    
    UFUNCTION(BlueprintCallable)
    static ULevel* GetLevelForActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta = (WorldContext = "WorldContextObject"))
    static UGameViewportClientGunfire* GetGameViewport(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintPure)
    static int64 GetFrameCounter();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetCurrentPlatformVRam();
    
    UFUNCTION(BlueprintCallable)
    static UActorComponent* GetComponentByTag(AActor* Actor, const FName& Tag);
    
    UFUNCTION(BlueprintCallable)
    static UActorComponent* GetComponentByName(AActor* Actor, const FName& NodeName);
    
    UFUNCTION(BlueprintCallable)
    static bool GetClosestUnblockedPointBetweenActors(const AActor* Target, const AActor* Source, TEnumAsByte<ECollisionChannel> TraceChannel, TEnumAsByte<ECollisionChannel> CollisionChannel, FVector& OutClosestPoint);
    
    UFUNCTION(BlueprintCallable)
    static float GetClosestPointInActor(const AActor* Actor, const FVector& Point, TEnumAsByte<ECollisionChannel> TraceChannel, FVector& OutClosestPoint);
    
    UFUNCTION(BlueprintCallable)
    static FString GetCleanLevelStreamingName(const UWorld* World, const ULevelStreaming* Level, bool AppendBaseName);
    
    UFUNCTION(BlueprintCallable)
    static FString GetCleanLevelPackageName(const UWorld* World, const FString& LevelPackagePath, bool AppendBaseName);
    
    UFUNCTION(BlueprintCallable)
    static EBuildType GetBuildType();
    
    UFUNCTION(BlueprintCallable)
    static int32 GetBuildNumber();
    
    UFUNCTION(BlueprintCallable)
    static bool GetBoneTransform(const USkeletalMeshComponent* SkeletalMesh, FName BoneName, FTransform& Transform, TEnumAsByte<ERelativeTransformSpace> TransformSpace);
    
    UFUNCTION(BlueprintCallable)
    static bool GetBoneRefTransform(const USkeletalMeshComponent* SkeletalMesh, FName BoneName, FTransform& Transform);
    
    UFUNCTION(BlueprintCallable)
    static AActor* GetBestWaterBounds(AActor* Actor, bool bConstrainToFluidFilled);
    
    UFUNCTION(BlueprintCallable)
    static bool GetAttachSocketName(USceneComponent* Mesh, FName& OutSocketName);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static void GetActorsWithTagEx(const UObject* WorldContextObject, FName Tag, TArray<AActor*>& OutResults);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static void GetActorsInRangeEx(const UObject* WorldContextObject, const FVector& Position, float MinRange, float MaxRange, UClass* FilterClass, const FActorQueryFilter& Filter, TArray<FActorQueryResult>& OutResults);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static void GetActorsInRange(const UObject* WorldContextObject, const FVector& Position, float MinRange, float MaxRange, UClass* FilterClass, const FActorQueryFilter& Filter, TArray<AActor*>& OutResults);
    
    UFUNCTION(BlueprintCallable)
    static void GetActorBoundsSafe(AActor* Actor, bool bOnlyCollidingComponents, FVector& Origin, FVector& Extents);
    
    UFUNCTION(BlueprintCallable)
    static void ForceGarbageCollection();
    
    UFUNCTION(BlueprintCallable)
    static AActor* FinishSpawningDeferredActor(AActor* Actor, const FTransform& SpawnTransform);
    
    UFUNCTION(BlueprintCallable)
    static bool FindTeleportPositionNear(AActor* Actor, float Distance, FVector& OutPosition, bool InFOVOnly);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static APlayerStart* FindPlayerStart(UObject* WorldContextObject, const FName& PlayerStartTag);
    
    UFUNCTION(BlueprintCallable)
    static void EnableStereo(bool bEnable);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static void DrawDebugArrow(const UObject* WorldContextObject, const FVector& LineStart, const FVector& LineEnd, const FVector& ArrowAxis, const FRotator& BasisRotation, const FLinearColor& Color, const float Thickness, const float Duration, const float ArrowSize);
    
    UFUNCTION(BlueprintCallable)
    static bool DoesPathIntersectWithBounds(const ACharacterGunfire* Character, const FVector& Origin, const FVector& Extents);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static bool DoesGameHaveFocus(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static void DebugDrawShapeWithOrientation(const UObject* WorldContextObject, const UShapeComponent* Shape, const FColor& Color, FVector Location, FRotator Rotation, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static void DebugDrawShape(const UObject* WorldContextObject, const UShapeComponent* Shape, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static void DebugDrawCollision(const UObject* WorldContextObject, const UPrimitiveComponent* Primitive, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness);
    
    UFUNCTION(BlueprintCallable)
    static void CustomError(AActor* ErrorContext, const FString& Message);
    
    UFUNCTION(BlueprintCallable)
    static bool CheckInputAction(const APlayerController* PlayerController, const FName& ActionName);
    
    UFUNCTION(BlueprintCallable)
    static void CenterViewportCursor(const APlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static FVector CalculateTraversableTeleportLocation(UObject* WorldContextObject, ACharacter* Character, FVector AimStart, FVector AimEnd, float AimObstacleTolerance, float GroundDistance, float CliffTolerance, bool bConstrainToLedges, float ProbeDistance, float StuckCheckHeightOffset, float FlatSurfaceDistance, bool bDebugDraw);
    
    UFUNCTION(BlueprintCallable)
    static void ApplyLinearImpulseToActorAtLocation(AActor* Actor, TSubclassOf<UDamageTypeGunfire> DType, const FVector& Direction, const FVector& Location);
    
    UFUNCTION(BlueprintCallable)
    static void ApplyLinearImpulseToActor(AActor* Actor, TSubclassOf<UDamageTypeGunfire> DType, const FVector& Direction);
    
    UFUNCTION(BlueprintCallable)
    static void AddTag(AActor* Actor, FName Tag);
    
    UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject"))
    static ULevelStreaming* AddLevelInstance(UObject* WorldContextObject, const FString& UniqueInstanceName, const FString& PackageNameToLoad, const FTransform& LevelTransform, bool BlockOnLoad, bool ShouldBeLoaded, bool ShouldBeVisible, TSubclassOf<ULevelStreaming> LevelStreamingOverride);
    
    UFUNCTION(BlueprintCallable)
    static UActorComponent* AddComponent(AActor* Actor, TSubclassOf<UActorComponent> ComponentClass, FName Name, FName AttachSocketName, USceneComponent* AttachParent, EAttachmentRule AttachRule, bool bWeldSimulatedBodies, FVector RelativeLocation, FRotator RelativeRotation, bool bSkipAttachment);
    
    UFUNCTION(BlueprintCallable)
    static void ActivateSceneComponents(AActor* Actor, FName Slot, FName Tag, bool ActivateChildren, bool UseVisibility);
    
    UFUNCTION(BlueprintCallable)
    static void ActivateSceneComponent(USceneComponent* SceneComponent, bool Active, bool ActivateChildren, bool UseVisibility);
    
};

