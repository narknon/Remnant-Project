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

#include "HoudiniApi.h"
#include "HoudiniRuntimeSettings.h"
#include "HoudiniEngineRuntimePrivatePCH.h"
#include "HoudiniEngineUtils.h"

#include "Internationalization/Internationalization.h"
#define LOCTEXT_NAMESPACE HOUDINI_LOCTEXT_NAMESPACE 

UHoudiniRuntimeSettings::UHoudiniRuntimeSettings( const FObjectInitializer & ObjectInitializer )
: Super( ObjectInitializer )
{
    /** Session options. **/
    SessionType = HRSST_NamedPipe;
    ServerHost = HAPI_UNREAL_SESSION_SERVER_HOST;
    ServerPort = HAPI_UNREAL_SESSION_SERVER_PORT;
    ServerPipeName = HAPI_UNREAL_SESSION_SERVER_PIPENAME;
    bStartAutomaticServer = HAPI_UNREAL_SESSION_SERVER_AUTOSTART;
    AutomaticServerTimeout = HAPI_UNREAL_SESSION_SERVER_TIMEOUT;

#if PLATFORM_LINUX
    // Since 4.17, Linux has library conflict, so we need to create an out-of-process session by default
    // We default to a named pipe, but TCP Sockets should work fine too.
    SessionType = HRSST_Socket;
    bStartAutomaticServer = true;
#endif

    /** Instantiation options. **/
    bShowMultiAssetDialog = true;

    /** Cooking options. **/
    bPauseCookingOnStart = false;
    bEnableCooking = true;
    bUploadTransformsToHoudiniEngine = true;
    bTransformChangeTriggersCooks = false;
    bDisplaySlateCookingNotifications = true;
    bCookCurvesOnMouseRelease = false;

    TemporaryCookFolder = LOCTEXT("Temp", "/Game/HoudiniEngine/Temp");

    /** Parameter options. **/
    bTreatRampParametersAsMultiparms = false;

    /** Collision generation. **/
    CollisionGroupNamePrefix = TEXT( HAPI_UNREAL_GROUP_GEOMETRY_COLLISION );
    RenderedCollisionGroupNamePrefix = TEXT(HAPI_UNREAL_GROUP_GEOMETRY_RENDERED_COLLISION );
    UCXCollisionGroupNamePrefix = TEXT( HAPI_UNREAL_GROUP_GEOMETRY_COLLISION_UCX );
    UCXRenderedCollisionGroupNamePrefix = TEXT( HAPI_UNREAL_GROUP_GEOMETRY_RENDERED_COLLISION_UCX );
    SimpleCollisionGroupNamePrefix = TEXT( HAPI_UNREAL_GROUP_GEOMETRY_SIMPLE_COLLISION );
    SimpleRenderedCollisionGroupNamePrefix = TEXT( HAPI_UNREAL_GROUP_GEOMETRY_SIMPLE_RENDERED_COLLISION );

    /** Geometry marshalling. **/
    MarshallingAttributeMaterial = TEXT( HAPI_UNREAL_ATTRIB_MATERIAL );
    MarshallingAttributeMaterialHole = TEXT( HAPI_UNREAL_ATTRIB_MATERIAL_HOLE );
    MarshallingAttributeInstanceOverride = TEXT( HAPI_UNREAL_ATTRIB_INSTANCE_OVERRIDE );
    MarshallingAttributeFaceSmoothingMask = TEXT( HAPI_UNREAL_ATTRIB_FACE_SMOOTHING_MASK );
    MarshallingAttributeLightmapResolution = TEXT( HAPI_UNREAL_ATTRIB_LIGHTMAP_RESOLUTION );
    MarshallingAttributeGeneratedMeshName = TEXT( HAPI_UNREAL_ATTRIB_GENERATED_MESH_NAME );
    MarshallingAttributeInputMeshName = TEXT( HAPI_UNREAL_ATTRIB_INPUT_MESH_NAME );
    MarshallingAttributeInputSourceFile = TEXT( HAPI_UNREAL_ATTRIB_INPUT_SOURCE_FILE );
    MarshallingSplineResolution = HAPI_UNREAL_PARAM_SPLINE_RESOLUTION_DEFAULT;
    MarshallingLandscapesUseDefaultUnrealScaling = false;
    MarshallingLandscapesUseFullResolution = true;
    MarshallingLandscapesForceMinMaxValues = false;
    MarshallingLandscapesForcedMinValue = -2000.0f;
    MarshallingLandscapesForcedMaxValue = 4553.0f;

    /** Geometry scaling. **/
    GeneratedGeometryScaleFactor = HAPI_UNREAL_SCALE_FACTOR_POSITION;
    TransformScaleFactor = HAPI_UNREAL_SCALE_FACTOR_TRANSLATION;
    ImportAxis = HRSAI_Unreal;

    /** Generated StaticMesh settings. **/
    bDoubleSidedGeometry = false;
    PhysMaterial = nullptr;
    DefaultBodyInstance.SetCollisionProfileName("BlockAll");
    CollisionTraceFlag = CTF_UseDefault;
    LightMapResolution = 32;
    LpvBiasMultiplier = 1.0f;
    LightMapCoordinateIndex = 1;
    bUseMaximumStreamingTexelRatio = false;
    StreamingDistanceMultiplier = 1.0f;
    GeneratedDistanceFieldResolutionScale = 0.0f;

    /** Static Mesh build settings. **/
    bUseFullPrecisionUVs = false;
    SrcLightmapIndex = 0;
    DstLightmapIndex = 1;
    MinLightmapResolution = 64;
    bRemoveDegenerates = true;
    GenerateLightmapUVsFlag = HRSRF_OnlyIfMissing;
    RecomputeNormalsFlag = HRSRF_OnlyIfMissing;
    RecomputeTangentsFlag = HRSRF_OnlyIfMissing;
    bUseMikkTSpace = true;
    bBuildAdjacencyBuffer = false;

    /** Custom Houdini location. **/
    bUseCustomHoudiniLocation = false;
    CustomHoudiniLocation.Path = TEXT( "" );

    // Placement Mode Tools
    bHidePlacementModeHoudiniTools = false;

    /** Arguments for HAPI_Initialize */
    CookingThreadStackSize = -1;
}

UHoudiniRuntimeSettings::~UHoudiniRuntimeSettings()
{}

UProperty *
UHoudiniRuntimeSettings::LocateProperty( const FString & PropertyName ) const
{
    for ( TFieldIterator< UProperty > PropIt( GetClass() ); PropIt; ++PropIt )
    {
        UProperty * Property = *PropIt;

        if ( Property->GetNameCPP() == PropertyName )
            return Property;
    }

    return nullptr;
}

void
UHoudiniRuntimeSettings::SetPropertyReadOnly( const FString & PropertyName, bool bReadOnly )
{
    UProperty * Property = LocateProperty( PropertyName );
    if ( Property )
    {
        if ( bReadOnly )
            Property->SetPropertyFlags( CPF_EditConst );
        else
            Property->ClearPropertyFlags( CPF_EditConst );
    }
}

void
UHoudiniRuntimeSettings::PostInitProperties()
{
    Super::PostInitProperties();

    // Set Collision generation options as read only
    {
        if ( UProperty* Property = LocateProperty( TEXT( "CollisionGroupNamePrefix" ) ) )
            Property->SetPropertyFlags( CPF_EditConst );

        if ( UProperty* Property = LocateProperty( TEXT( "RenderedCollisionGroupNamePrefix" ) ) )
            Property->SetPropertyFlags( CPF_EditConst );

        if ( UProperty* Property = LocateProperty(TEXT("UCXCollisionGroupNamePrefix" ) ) )
            Property->SetPropertyFlags(CPF_EditConst);

        if ( UProperty* Property = LocateProperty(TEXT("UCXRenderedCollisionGroupNamePrefix" ) ) )
            Property->SetPropertyFlags(CPF_EditConst);

        if ( UProperty* Property = LocateProperty(TEXT("SimpleCollisionGroupNamePrefix" ) ) )
            Property->SetPropertyFlags(CPF_EditConst);

        if ( UProperty* Property = LocateProperty(TEXT("SimpleRenderedCollisionGroupNamePrefix" ) ) )
            Property->SetPropertyFlags(CPF_EditConst);
    }

    // Set marshalling attributes options as read only
    {
        if (UProperty* Property = LocateProperty(TEXT("MarshallingAttributeMaterial")))
            Property->SetPropertyFlags(CPF_EditConst);

        if (UProperty* Property = LocateProperty(TEXT("MarshallingAttributeMaterialHole")))
            Property->SetPropertyFlags(CPF_EditConst);

        if (UProperty* Property = LocateProperty(TEXT("MarshallingAttributeInstanceOverride")))
            Property->SetPropertyFlags(CPF_EditConst);

        if (UProperty* Property = LocateProperty(TEXT("MarshallingAttributeFaceSmoothingMask")))
            Property->SetPropertyFlags(CPF_EditConst);

        if (UProperty* Property = LocateProperty(TEXT("MarshallingAttributeLightmapResolution")))
            Property->SetPropertyFlags(CPF_EditConst);

        if (UProperty* Property = LocateProperty(TEXT("MarshallingAttributeGeneratedMeshName")))
            Property->SetPropertyFlags(CPF_EditConst);

        if (UProperty* Property = LocateProperty(TEXT("MarshallingAttributeInputMeshName")))
            Property->SetPropertyFlags(CPF_EditConst);
    }

    // Set Cook Folder as read-only
    {
        if ( UProperty* Property = LocateProperty( TEXT( "TemporaryCookFolder" ) ) )
            Property->SetPropertyFlags( CPF_EditConst );
    }

    // Set Landscape forced min/max as read only when not overriden
    if ( !MarshallingLandscapesForceMinMaxValues )
    {
        if ( UProperty* Property = LocateProperty( TEXT( "MarshallingLandscapesForcedMinValue" ) ) )
            Property->SetPropertyFlags( CPF_EditConst );
        if ( UProperty* Property = LocateProperty( TEXT( "MarshallingLandscapesForcedMaxValue" ) ) )
            Property->SetPropertyFlags( CPF_EditConst );
    }

    // Disable UI elements depending on current session type.
#if WITH_EDITOR

    UpdateSessionUi();

#endif // WITH_EDITOR

    SetPropertyReadOnly( TEXT( "CustomHoudiniLocation" ), !bUseCustomHoudiniLocation );
}

#if WITH_EDITOR

void
UHoudiniRuntimeSettings::PostEditChangeProperty( struct FPropertyChangedEvent & PropertyChangedEvent )
{
    Super::PostEditChangeProperty( PropertyChangedEvent );

    UProperty * Property = PropertyChangedEvent.MemberProperty;
    UProperty * LookupProperty = nullptr;

    if ( !Property )
        return;

    if ( Property->GetName() == TEXT( "GeneratedGeometryScaleFactor" ) )
        GeneratedGeometryScaleFactor = FMath::Clamp( GeneratedGeometryScaleFactor, KINDA_SMALL_NUMBER, 10000.0f );
    else if ( Property->GetName() == TEXT( "TransformScaleFactor" ) )
        GeneratedGeometryScaleFactor = FMath::Clamp( GeneratedGeometryScaleFactor, KINDA_SMALL_NUMBER, 10000.0f );
    else if ( Property->GetName() == TEXT( "SessionType" ) )
        UpdateSessionUi();
    else if ( Property->GetName() == TEXT( "bUseCustomHoudiniLocation" ) )
        SetPropertyReadOnly( TEXT( "CustomHoudiniLocation" ), !bUseCustomHoudiniLocation );
    else if ( Property->GetName() == TEXT( "CustomHoudiniLocation" ) )
    {
        FString LibHAPIName = FHoudiniEngineUtils::HoudiniGetLibHAPIName();
        FString & CustomHoudiniLocationPath = CustomHoudiniLocation.Path;
        FString LibHAPICustomPath = FString::Printf( TEXT( "%s/%s" ), *CustomHoudiniLocationPath, *LibHAPIName );

        // If path does not point to libHAPI location, we need to let user know.
        if ( !FPaths::FileExists( LibHAPICustomPath ) )
        {
            FString MessageString = FString::Printf(
                TEXT( "%s was not found in %s" ), *LibHAPIName, *CustomHoudiniLocationPath );

            FPlatformMisc::MessageBoxExt(
                EAppMsgType::Ok, *MessageString,
                TEXT( "Invalid Custom Location Specified, resetting." ) );

            CustomHoudiniLocationPath = TEXT( "" );
        }
    }
    else if (Property->GetName() == TEXT("MarshallingSplineResolution"))
        MarshallingSplineResolution = FMath::Clamp(MarshallingSplineResolution, 0.0f, 10000.0f);

    if ( Property->GetName() == TEXT( "MarshallingLandscapesForceMinMaxValues" ) )
    {
        // Set Landscape forced min/max as read only when not overriden
        if ( !MarshallingLandscapesForceMinMaxValues )
        {
            if ( UProperty* MinProperty = LocateProperty( TEXT( "MarshallingLandscapesForcedMinValue") ) )
                MinProperty->SetPropertyFlags( CPF_EditConst );
            if ( UProperty* MaxProperty = LocateProperty( TEXT( "MarshallingLandscapesForcedMaxValue" ) ) )
                MaxProperty->SetPropertyFlags( CPF_EditConst );
        }
        else
        {
            if ( UProperty* MinProperty = LocateProperty( TEXT( "MarshallingLandscapesForcedMinValue") ) )
                MinProperty->ClearPropertyFlags( CPF_EditConst );
            if ( UProperty* MaxProperty = LocateProperty( TEXT( "MarshallingLandscapesForcedMaxValue" ) ) )
                MaxProperty->ClearPropertyFlags( CPF_EditConst );
        }
    }

    /*
    if ( Property->GetName() == TEXT( "bEnableCooking" ) )
    {
        // Cooking is disabled, we need to disable transform change triggers cooks option is as well.
        if ( bEnableCooking )
        {
            LookupProperty = LocateProperty( TEXT( "bUploadTransformsToHoudiniEngine" ) );
            if ( LookupProperty )
                LookupProperty->ClearPropertyFlags( CPF_EditConst );

            LookupProperty = LocateProperty( TEXT( "bTransformChangeTriggersCooks" ) );
            if ( LookupProperty )
                LookupProperty->ClearPropertyFlags( CPF_EditConst );
        }
        else
        {
            LookupProperty = LocateProperty( TEXT( "bUploadTransformsToHoudiniEngine" ) );
            if ( LookupProperty )
                LookupProperty->SetPropertyFlags( CPF_EditConst );

            LookupProperty = LocateProperty( TEXT( "bTransformChangeTriggersCooks" ) );
            if ( LookupProperty )
                LookupProperty->SetPropertyFlags( CPF_EditConst );
        }
    }
    else if ( Property->GetName() == TEXT( "bUploadTransformsToHoudiniEngine" ) )
    {
        // If upload of transformations is disabled, then there's no sense in cooking asset on transformation change.
        if ( bUploadTransformsToHoudiniEngine )
        {
            LookupProperty = LocateProperty( TEXT( "bTransformChangeTriggersCooks" ) );
            if ( LookupProperty )
                LookupProperty->ClearPropertyFlags( CPF_EditConst );
        }
        else
        {
            LookupProperty = LocateProperty( TEXT( "bTransformChangeTriggersCooks" ) );
            if ( LookupProperty )
                LookupProperty->SetPropertyFlags( CPF_EditConst );
        }
    }
    */
}

void
UHoudiniRuntimeSettings::SetMeshBuildSettings( FMeshBuildSettings & MeshBuildSettings, FRawMesh & RawMesh ) const
{
    MeshBuildSettings.bRemoveDegenerates = bRemoveDegenerates;
    MeshBuildSettings.bUseMikkTSpace = bUseMikkTSpace;
    MeshBuildSettings.bBuildAdjacencyBuffer = bBuildAdjacencyBuffer;
    MeshBuildSettings.MinLightmapResolution = MinLightmapResolution;
    MeshBuildSettings.bUseFullPrecisionUVs = bUseFullPrecisionUVs;
    MeshBuildSettings.SrcLightmapIndex = SrcLightmapIndex;
    MeshBuildSettings.DstLightmapIndex = DstLightmapIndex;

    // Recomputing normals.
    switch ( RecomputeNormalsFlag )
    {
        case HRSRF_Always:
        {
            MeshBuildSettings.bRecomputeNormals = true;
            break;
        }

        case HRSRF_OnlyIfMissing:
        {
            MeshBuildSettings.bRecomputeNormals = ( 0 == RawMesh.WedgeTangentZ.Num() );
            break;
        }

        case HRSRF_Nothing:
        default:
        {
            MeshBuildSettings.bRecomputeNormals = false;
            break;
        }
    }

    // Recomputing tangents.
    switch ( RecomputeTangentsFlag )
    {
        case HRSRF_Always:
        {
            MeshBuildSettings.bRecomputeTangents = true;
            break;
        }

        case HRSRF_OnlyIfMissing:
        {
            MeshBuildSettings.bRecomputeTangents = ( 0 == RawMesh.WedgeTangentX.Num() || 0 == RawMesh.WedgeTangentY.Num() );
            break;
        }

        case HRSRF_Nothing:
        default:
        {
            MeshBuildSettings.bRecomputeTangents = false;
            break;
        }
    }

    // Lightmap UV generation.
    bool bHasLightmapUVSet = FHoudiniEngineUtils::CountUVSets( RawMesh ) > 1;

    switch ( GenerateLightmapUVsFlag )
    {
        case HRSRF_Always:
        {
            MeshBuildSettings.bGenerateLightmapUVs = true;
            break;
        }

        case HRSRF_OnlyIfMissing:
        {
            MeshBuildSettings.bGenerateLightmapUVs = !bHasLightmapUVSet;
            break;
        }

        case HRSRF_Nothing:
        default:
        {
            MeshBuildSettings.bGenerateLightmapUVs = false;
            break;
        }
    }
}

void
UHoudiniRuntimeSettings::UpdateSessionUi()
{
    SetPropertyReadOnly( TEXT( "ServerHost" ), true );
    SetPropertyReadOnly( TEXT( "ServerPort" ), true );
    SetPropertyReadOnly( TEXT( "ServerPipeName" ), true );
    SetPropertyReadOnly( TEXT( "bStartAutomaticServer" ), true );
    SetPropertyReadOnly( TEXT( "AutomaticServerTimeout" ), true );

    bool bServerType = false;

    switch ( SessionType )
    {
        case HRSST_Socket:
        {
            SetPropertyReadOnly( TEXT( "ServerHost" ), false);
            SetPropertyReadOnly( TEXT( "ServerPort" ), false);
            bServerType = true;
            break;
        }

        case HRSST_NamedPipe:
        {
            SetPropertyReadOnly( TEXT( "ServerPipeName" ), false);
            bServerType = true;
            break;
        }

        default:
            break;
    }

    if ( bServerType )
    {
        SetPropertyReadOnly( TEXT( "bStartAutomaticServer" ), false );
        SetPropertyReadOnly( TEXT( "AutomaticServerTimeout" ), false );
    }
}

#endif // WITH_EDITOR

bool
UHoudiniRuntimeSettings::GetSettingsValue( const FString & PropertyName, std::string & PropertyValue )
{
    FString PropertyString = TEXT( "" );
    if ( UHoudiniRuntimeSettings::GetSettingsValue( PropertyName, PropertyString ) )
    {
        FHoudiniEngineUtils::ConvertUnrealString( PropertyString, PropertyValue );
        return true;
    }

    return false;
}

bool
UHoudiniRuntimeSettings::GetSettingsValue( const FString & PropertyName, FString & PropertyValue )
{
    const UHoudiniRuntimeSettings * HoudiniRuntimeSettings = GetDefault< UHoudiniRuntimeSettings >();
    if ( HoudiniRuntimeSettings )
    {
        UStrProperty * Property = Cast< UStrProperty >( HoudiniRuntimeSettings->LocateProperty( PropertyName ) );
        if ( Property )
        {
            const void * ValueRaw = Property->ContainerPtrToValuePtr< void >( HoudiniRuntimeSettings );
            FString RetrievedPropertyValue = Property->GetPropertyValue( ValueRaw );

            if ( !RetrievedPropertyValue.IsEmpty() )
            {
                PropertyValue = RetrievedPropertyValue;
                return true;
            }
        }
    }

    return false;
}

#undef LOCTEXT_NAMESPACE