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
* Produced by:
*      Mykola Konyk
*      Side Effects Software Inc
*      123 Front Street West, Suite 1401
*      Toronto, Ontario
*      Canada   M5J 2M2
*      416-504-9876
*
*/

#include "HoudiniApi.h"
#include "HoudiniGeoPartObject.h"
#include "HoudiniEngineRuntimePrivatePCH.h"
#include "HoudiniEngineUtils.h"
#include "HoudiniEngine.h"
#include "HoudiniPluginSerializationVersion.h"
#include "HoudiniEngineString.h"

uint32
GetTypeHash( const FHoudiniGeoPartObject & HoudiniGeoPartObject )
{
    return HoudiniGeoPartObject.GetTypeHash();
}

FArchive &
operator<<( FArchive & Ar, FHoudiniGeoPartObject & HoudiniGeoPartObject )
{
    HoudiniGeoPartObject.Serialize( Ar );
    return Ar;
}

bool
FHoudiniGeoPartObjectSortPredicate::operator()( const FHoudiniGeoPartObject & A, const FHoudiniGeoPartObject & B ) const
{
    if ( !A.IsValid() || !B.IsValid() )
        return false;

    if ( A.ObjectId == B.ObjectId )
    {
        if ( A.GeoId == B.GeoId )
        {
            if ( A.PartId == B.PartId )
                return A.SplitId < B.SplitId;
            else
                return A.PartId < B.PartId;
        }
        else
        {
            return A.GeoId < B.GeoId;
        }
    }
    
    return A.ObjectId < B.ObjectId;
}

FHoudiniGeoPartObject::FHoudiniGeoPartObject()
    : TransformMatrix( FMatrix::Identity )
    , ObjectName( TEXT("Empty" ) )
    , PartName( TEXT( "Empty" ) )
    , SplitName( TEXT( "" ) )
    , InstancerMaterialName( TEXT( "" ) )
    , InstancerAttributeMaterialName( TEXT( "" ) )
    , AssetId( -1 )
    , ObjectId( -1 )
    , GeoId( -1 )
    , PartId( -1 )
    , SplitId( 0 )
    , bIsVisible( true )
    , bIsInstancer( false )
    , bIsCurve( false )
    , bIsEditable( false )
    , bHasGeoChanged( false )
    , bIsCollidable( false )
    , bIsRenderCollidable( false )
    , bIsLoaded( false )
    , bPlaceHolderFlags( 0 )
    , bIsTransacting( false )
    , bHasCustomName( false )
    , bIsBox( false )
    , bIsSphere( false )
    , bInstancerMaterialAvailable( false )
    , bIsVolume( false )
    , bInstancerAttributeMaterialAvailable( false )
    , bIsPackedPrimitiveInstancer( false )
    , bIsUCXCollisionGeo( false )
    , bIsSimpleCollisionGeo( false )
    , bHasCollisionBeenAdded( false )
    , bHasSocketBeenAdded( false )
    , UnusedFlagsSpace( 0u )
    , HoudiniGeoPartObjectVersion( VER_HOUDINI_PLUGIN_SERIALIZATION_VERSION_BASE )
{}

FHoudiniGeoPartObject::FHoudiniGeoPartObject(
    HAPI_NodeId InAssetId, HAPI_NodeId InObjectId, HAPI_NodeId InGeoId, HAPI_PartId InPartId )
    : TransformMatrix( FMatrix::Identity )
    , ObjectName( TEXT( "Empty" ) )
    , PartName( TEXT( "Empty" ) )
    , SplitName( TEXT( "" ) )
    , InstancerMaterialName( TEXT( "" ) )
    , AssetId( InAssetId )
    , ObjectId( InObjectId )
    , GeoId( InGeoId )
    , PartId( InPartId )
    , SplitId( 0 )
    , bIsVisible( true )
    , bIsInstancer( false )
    , bIsCurve( false )
    , bIsEditable( false )
    , bHasGeoChanged( false )
    , bIsCollidable( false )
    , bIsRenderCollidable( false )
    , bIsLoaded( false )
    , bPlaceHolderFlags( 0 )
    , bIsTransacting( false )
    , bHasCustomName( false )
    , bIsBox( false )
    , bIsSphere( false )
    , bInstancerMaterialAvailable( false )
    , bIsVolume( false )
    , bInstancerAttributeMaterialAvailable( false )
    , bIsPackedPrimitiveInstancer( false )
    , bIsUCXCollisionGeo( false )
    , bIsSimpleCollisionGeo( false )
    , bHasCollisionBeenAdded( false )
    , bHasSocketBeenAdded( false )
    , UnusedFlagsSpace( 0u )
    , HoudiniGeoPartObjectVersion( VER_HOUDINI_PLUGIN_SERIALIZATION_VERSION_BASE )
{}

FHoudiniGeoPartObject::FHoudiniGeoPartObject(
    const FTransform & InTransform, HAPI_NodeId InAssetId,
    const HAPI_ObjectInfo & ObjectInfo, const HAPI_GeoInfo & GeoInfo, const HAPI_PartInfo & PartInfo )
    : TransformMatrix( InTransform )
    , ObjectName( TEXT( "Empty" ) )
    , PartName( TEXT( "Empty" ) )
    , SplitName( TEXT( "" ) )
    , InstancerMaterialName( TEXT( "" ) )
    , AssetId( InAssetId )
    , ObjectId( ObjectInfo.nodeId )
    , GeoId( GeoInfo.nodeId )
    , PartId( PartInfo.id )
    , SplitId( 0 )
    , bIsVisible( ObjectInfo.isVisible )
    , bIsInstancer( ObjectInfo.isInstancer )
    , bIsCurve( PartInfo.type == HAPI_PARTTYPE_CURVE )
    , bIsEditable( GeoInfo.isEditable )
    , bHasGeoChanged( GeoInfo.hasGeoChanged )
    , bIsCollidable( false )
    , bIsRenderCollidable( false )
    , bIsLoaded( false )
    , bPlaceHolderFlags( 0 )
    , bIsTransacting( false )
    , bHasCustomName( false )
    , bIsBox( PartInfo.type == HAPI_PARTTYPE_BOX )
    , bIsSphere( PartInfo.type == HAPI_PARTTYPE_SPHERE )
    , bInstancerMaterialAvailable( false )
    , bIsVolume( PartInfo.type == HAPI_PARTTYPE_VOLUME )
    , bInstancerAttributeMaterialAvailable( false )
    , bIsPackedPrimitiveInstancer( PartInfo.type == HAPI_PARTTYPE_INSTANCER )
    , bIsUCXCollisionGeo( false )
    , bIsSimpleCollisionGeo( false )
    , bHasCollisionBeenAdded( false )
    , bHasSocketBeenAdded( false )
    , UnusedFlagsSpace( 0u )
    , HoudiniGeoPartObjectVersion( VER_HOUDINI_PLUGIN_SERIALIZATION_VERSION_BASE )
{}

FHoudiniGeoPartObject::FHoudiniGeoPartObject(
    const FTransform & InTransform, const FString & InObjectName,
    const FString & InPartName, HAPI_NodeId InAssetId,
    HAPI_NodeId InObjectId, HAPI_NodeId InGeoId,
    HAPI_PartId InPartId )
    : TransformMatrix( InTransform )
    , ObjectName( InObjectName )
    , PartName( InPartName )
    , SplitName( TEXT( "" ) )
    , InstancerMaterialName( TEXT( "" ) )
    , AssetId( InAssetId )
    , ObjectId( InObjectId )
    , GeoId( InGeoId )
    , PartId( InPartId )
    , SplitId( 0 )
    , bIsVisible( true )
    , bIsInstancer( false )
    , bIsCurve( false )
    , bIsEditable( false )
    , bHasGeoChanged( false )
    , bIsCollidable( false )
    , bIsRenderCollidable( false )
    , bIsLoaded( false )
    , bPlaceHolderFlags( 0 )
    , bIsTransacting( false )
    , bHasCustomName( false )
    , bIsBox( false )
    , bIsSphere( false )
    , bInstancerMaterialAvailable( false )
    , bIsVolume( false )
    , bInstancerAttributeMaterialAvailable( false )
    , bIsPackedPrimitiveInstancer( false )
    , bIsUCXCollisionGeo( false )
    , bIsSimpleCollisionGeo( false )
    , bHasCollisionBeenAdded( false )
    , bHasSocketBeenAdded( false )
    , UnusedFlagsSpace( 0u )
    , HoudiniGeoPartObjectVersion( VER_HOUDINI_PLUGIN_SERIALIZATION_VERSION_BASE )
{}

FHoudiniGeoPartObject::FHoudiniGeoPartObject( const FHoudiniGeoPartObject & GeoPartObject, bool bCopyLoaded )
    : TransformMatrix( GeoPartObject.TransformMatrix )
    , ObjectName( GeoPartObject.ObjectName )
    , PartName( GeoPartObject.PartName )
    , SplitName( GeoPartObject.SplitName )
    , InstancerMaterialName( GeoPartObject.InstancerMaterialName )
    , AssetId( GeoPartObject.AssetId )
    , ObjectId( GeoPartObject.ObjectId )
    , GeoId( GeoPartObject.GeoId )
    , PartId( GeoPartObject.PartId )
    , SplitId( GeoPartObject.SplitId )
    , bIsVisible( GeoPartObject.bIsVisible )
    , bIsInstancer( GeoPartObject.bIsInstancer )
    , bIsCurve( GeoPartObject.bIsCurve )
    , bIsEditable( GeoPartObject.bIsEditable )
    , bHasGeoChanged( GeoPartObject.bHasGeoChanged )
    , bIsCollidable( GeoPartObject.bIsCollidable )
    , bIsRenderCollidable( GeoPartObject.bIsRenderCollidable )
    , bIsLoaded( GeoPartObject.bIsLoaded )
    , bPlaceHolderFlags( GeoPartObject.bPlaceHolderFlags )
    , bIsTransacting( GeoPartObject.bIsTransacting )
    , bHasCustomName( GeoPartObject.bHasCustomName )
    , bIsBox( GeoPartObject.bIsBox )
    , bIsSphere( GeoPartObject.bIsSphere )
    , bInstancerMaterialAvailable( GeoPartObject.bInstancerMaterialAvailable )
    , bIsVolume( GeoPartObject.bIsVolume )
    , bInstancerAttributeMaterialAvailable( GeoPartObject.bInstancerAttributeMaterialAvailable )
    , bIsPackedPrimitiveInstancer( GeoPartObject.bIsPackedPrimitiveInstancer )
    , bIsUCXCollisionGeo( GeoPartObject.bIsUCXCollisionGeo )
    , bIsSimpleCollisionGeo( GeoPartObject.bIsSimpleCollisionGeo )
    , bHasCollisionBeenAdded( GeoPartObject.bHasCollisionBeenAdded )
    , bHasSocketBeenAdded( GeoPartObject.bHasSocketBeenAdded )
    , UnusedFlagsSpace( 0u )
    , HoudiniGeoPartObjectVersion( VER_HOUDINI_PLUGIN_SERIALIZATION_VERSION_BASE )
{
    if ( bCopyLoaded )
        bIsLoaded = true;
}

bool
FHoudiniGeoPartObject::IsVisible() const
{
    return bIsVisible;
}

bool
FHoudiniGeoPartObject::IsInstancer() const
{
    return bIsInstancer;
}

bool
FHoudiniGeoPartObject::IsCurve() const
{
    return bIsCurve;
}

bool
FHoudiniGeoPartObject::IsBox() const
{
    return bIsBox;
}

bool
FHoudiniGeoPartObject::IsSphere() const
{
    return bIsSphere;
}

bool
FHoudiniGeoPartObject::IsVolume() const
{
    return bIsVolume;
}

bool
FHoudiniGeoPartObject::IsEditable() const
{
    return bIsEditable;
}

bool
FHoudiniGeoPartObject::HasGeoChanged() const
{
    return bHasGeoChanged;
}

bool
FHoudiniGeoPartObject::IsCollidable() const
{
    return bIsCollidable;
}

bool
FHoudiniGeoPartObject::IsRenderCollidable() const
{
    return bIsRenderCollidable;
}

HAPI_NodeId
FHoudiniGeoPartObject::GetObjectId() const
{
    return ObjectId;
}

HAPI_NodeId
FHoudiniGeoPartObject::GetGeoId() const
{
    return GeoId;
}

HAPI_PartId
FHoudiniGeoPartObject::GetPartId() const
{
    return PartId;
}

const FString&
FHoudiniGeoPartObject::GetNodePath() const
{
    // query on first-use
    if ( NodePath.IsEmpty() )
    {
        FString NodePathTemp;
        if ( AssetId == GeoId )
        {
            // This is a SOP asset, just return the asset name in this case
            HAPI_AssetInfo AssetInfo;
            if ( FHoudiniApi::GetAssetInfo(
                FHoudiniEngine::Get().GetSession(), AssetId, &AssetInfo ) == HAPI_RESULT_SUCCESS )
            {
                HAPI_NodeInfo AssetNodeInfo;
                if ( FHoudiniApi::GetNodeInfo(
                    FHoudiniEngine::Get().GetSession(), AssetInfo.nodeId, &AssetNodeInfo ) == HAPI_RESULT_SUCCESS )
                {
                    FHoudiniEngineString AssetPathHEString( AssetNodeInfo.nameSH );
                    if ( AssetPathHEString.ToFString( NodePathTemp ) )
                    {
                        NodePath = FString::Printf( TEXT( "%s_%d" ), *NodePathTemp, PartId );
                    }
                }
            }
        }
        else
        {
            // This is an OBJ asset, return the path to this geo relative to the asset
            if ( FHoudiniEngineUtils::HapiGetNodePath( GeoId, AssetId, NodePathTemp ) )
            {
                NodePath = FString::Printf( TEXT( "%s_%d" ), *NodePathTemp, PartId );
            }
        }

        if ( NodePath.IsEmpty() )
        {
            NodePath = TEXT( "Empty" );
        }
    }
    return NodePath;
}

bool
FHoudiniGeoPartObject::operator==( const FHoudiniGeoPartObject & GeoPartObject ) const
{
    return (
        ObjectId == GeoPartObject.ObjectId &&
        GeoId == GeoPartObject.GeoId &&
        PartId == GeoPartObject.PartId &&
        SplitId == GeoPartObject.SplitId );
}

uint32
FHoudiniGeoPartObject::GetTypeHash() const
{
    int32 HashBuffer[ 4 ] = { ObjectId, GeoId, PartId, SplitId };
    return FCrc::MemCrc_DEPRECATED( (void *) &HashBuffer[ 0 ], sizeof( HashBuffer ) );
}

void
FHoudiniGeoPartObject::Serialize( FArchive & Ar )
{
    Ar.UsingCustomVersion( FHoudiniCustomSerializationVersion::GUID );

    HoudiniGeoPartObjectVersion = VER_HOUDINI_PLUGIN_SERIALIZATION_AUTOMATIC_VERSION;
    Ar << HoudiniGeoPartObjectVersion;

    Ar << TransformMatrix;

    Ar << ObjectName;
    Ar << PartName;
    Ar << SplitName;

    // Serialize instancer material.
    if ( HoudiniGeoPartObjectVersion >= VER_HOUDINI_ENGINE_GEOPARTOBJECT_INSTANCER_MATERIAL_NAME )
        Ar << InstancerMaterialName;

    // Serialize instancer attribute material.
    if ( HoudiniGeoPartObjectVersion >= VER_HOUDINI_ENGINE_GEOPARTOBJECT_INSTANCER_ATTRIBUTE_MATERIAL_NAME )
        Ar << InstancerAttributeMaterialName;

    Ar << AssetId;
    Ar << ObjectId;
    Ar << GeoId;

    // Node id values can change between saving and loading a level
    if ( Ar.IsLoading() && !Ar.IsTransacting() )
    {
        AssetId = -1;
        // Although Object and Geo ids are invalid, we don't -1 them so that our parts can
        // still be hashed into a map on the component.  This will be dropped after the next cook
        // anyway.
    }

    Ar << PartId;
    Ar << SplitId;

    Ar << HoudiniGeoPartObjectFlagsPacked;

    if ( HoudiniGeoPartObjectVersion < VER_HOUDINI_PLUGIN_SERIALIZATION_VERSION_BASE )
    {
        // Prior to this version the unused flags space was not zero-initialized, so 
        // zero them out now to prevent misinterpreting any 1s
        HoudiniGeoPartObjectFlagsPacked &= 0x3FFFF;
    }

    if ( HoudiniGeoPartObjectVersion >= VER_HOUDINI_PLUGIN_SERIALIZATION_VERSION_GEO_PART_NODE_PATH )
    {
        if ( Ar.IsSaving() && !Ar.IsTransacting() )
        {
            // If we are saving to level - make sure node path is present
            (void) GetNodePath();
            Ar << NodePath;
        }
        else
        {
            Ar << NodePath;
        }
    }

    if ( Ar.IsLoading() )
        bIsLoaded = true;

    if ( Ar.IsTransacting() )
        bIsTransacting = true;
}

bool
FHoudiniGeoPartObject::IsValid() const
{
    return ( ObjectId >= 0 && GeoId >= 0 && PartId >= 0 );
}

bool
FHoudiniGeoPartObject::CompareNames( const FHoudiniGeoPartObject & HoudiniGeoPartObject ) const
{
    return ( ObjectName == HoudiniGeoPartObject.ObjectName && PartName == HoudiniGeoPartObject.PartName );
}

bool
FHoudiniGeoPartObject::HasParameters() const
{
    return HasParameters(AssetId);
}

bool
FHoudiniGeoPartObject::HasParameters( HAPI_NodeId InAssetId ) const
{
    HAPI_NodeId NodeId = HapiGeoGetNodeId( InAssetId );
    if ( NodeId == -1 )
        return false;

    HAPI_NodeInfo NodeInfo;
    FHoudiniApi::GetNodeInfo( FHoudiniEngine::Get().GetSession(), NodeId, &NodeInfo );

    return NodeInfo.parmCount > 0;
}

bool FHoudiniGeoPartObject::IsPackedPrimitiveInstancer() const
{
    return bIsPackedPrimitiveInstancer;
}

bool FHoudiniGeoPartObject::IsAttributeInstancer() const
{
    return HapiCheckAttributeExistance(    HAPI_UNREAL_ATTRIB_INSTANCE, HAPI_ATTROWNER_POINT );
}

bool FHoudiniGeoPartObject::IsAttributeOverrideInstancer() const
{
    // Check if this is an attribute override instancer (on detail or point).
    return HapiCheckAttributeExistance( HAPI_UNREAL_ATTRIB_INSTANCE_OVERRIDE, HAPI_ATTROWNER_DETAIL) 
        | HapiCheckAttributeExistance( HAPI_UNREAL_ATTRIB_INSTANCE_OVERRIDE, HAPI_ATTROWNER_POINT );
}

bool
FHoudiniGeoPartObject::HasCustomName() const
{
    return bHasCustomName;
}

void
FHoudiniGeoPartObject::SetCustomName( const FString & CustomName )
{
    PartName = CustomName;
    bHasCustomName = true;
}

bool
FHoudiniGeoPartObject::UpdateCustomName()
{
    TArray< FString > GeneratedMeshNames;
    HAPI_AttributeInfo AttribGeneratedMeshName;
    FMemory::Memzero< HAPI_AttributeInfo >(AttribGeneratedMeshName);

    bHasCustomName = false;
    if ( FHoudiniEngineUtils::HapiGetAttributeDataAsString(
        AssetId, ObjectId, GeoId, PartId, HAPI_UNREAL_ATTRIB_GENERATED_MESH_NAME, AttribGeneratedMeshName, GeneratedMeshNames ) )
    {
        if ( GeneratedMeshNames.Num() > 0 )
            SetCustomName( GeneratedMeshNames[0] );
    }

    return HasCustomName();
}

bool
FHoudiniGeoPartObject::HapiCheckAttributeExistance(
    HAPI_NodeId OtherAssetId, const FString & AttributeName,
    HAPI_AttributeOwner AttributeOwner ) const
{
    std::string AttributeNameRaw = "";
    FHoudiniEngineUtils::ConvertUnrealString( AttributeName, AttributeNameRaw );

    return HapiCheckAttributeExistance( OtherAssetId, AttributeNameRaw, AttributeOwner );
}

bool
FHoudiniGeoPartObject::HapiCheckAttributeExistance(
    const FString& AttributeName, HAPI_AttributeOwner AttributeOwner ) const
{
    return HapiCheckAttributeExistance( AssetId, AttributeName, AttributeOwner );
}

bool
FHoudiniGeoPartObject::HapiCheckAttributeExistance(
    HAPI_NodeId OtherAssetId, const std::string & AttributeName,
    HAPI_AttributeOwner AttributeOwner ) const
{
    return HapiCheckAttributeExistance( AttributeName.c_str(), AttributeOwner );
}

bool
FHoudiniGeoPartObject::HapiCheckAttributeExistance(
    const std::string & AttributeName, HAPI_AttributeOwner AttributeOwner ) const
{
    return HapiCheckAttributeExistance( AssetId, AttributeName, AttributeOwner );
}

bool
FHoudiniGeoPartObject::HapiCheckAttributeExistance(
    HAPI_NodeId OtherAssetId, const char * AttributeName,
    HAPI_AttributeOwner AttributeOwner ) const
{
    HAPI_AttributeInfo AttributeInfo;
    FMemory::Memset< HAPI_AttributeInfo >( AttributeInfo, 0 );

    if ( FHoudiniApi::GetAttributeInfo(
        FHoudiniEngine::Get().GetSession(), GeoId, PartId, AttributeName,
        AttributeOwner, &AttributeInfo ) == HAPI_RESULT_SUCCESS )
    {
        return AttributeInfo.exists;
    }

    return false;
}

bool
FHoudiniGeoPartObject::HapiCheckAttributeExistance(
    const char * AttributeName, HAPI_AttributeOwner AttributeOwner ) const
{
    return HapiCheckAttributeExistance( AssetId, AttributeName, AttributeOwner );
}

bool
FHoudiniGeoPartObject::HapiGetInstanceTransforms( HAPI_NodeId OtherAssetId, TArray< FTransform > & AllTransforms ) const
{
    AllTransforms.Empty();
    int32 PointCount = HapiPartGetPointCount( OtherAssetId );

    if ( PointCount > 0 )
    {
        TArray< HAPI_Transform > InstanceTransforms;
        InstanceTransforms.SetNumZeroed( PointCount );

        if ( FHoudiniApi::GetInstanceTransformsOnPart(
            FHoudiniEngine::Get().GetSession(), GeoId, PartId, HAPI_SRT, &InstanceTransforms[ 0 ],
            0, PointCount) == HAPI_RESULT_SUCCESS )
        {
            for ( int32 PointIdx = 0; PointIdx < PointCount; ++PointIdx )
            {
                FTransform TempTransformMatrix;

                const HAPI_Transform & HapiInstanceTransform = InstanceTransforms[ PointIdx ];
                FHoudiniEngineUtils::TranslateHapiTransform( HapiInstanceTransform, TempTransformMatrix );

                AllTransforms.Add( TempTransformMatrix );
            }
        }
        else
        {
            return false;
        }
    }

    return true;
}

bool
FHoudiniGeoPartObject::HapiGetInstanceTransforms( TArray< FTransform > & AllTransforms ) const
{
    return HapiGetInstanceTransforms( AssetId, AllTransforms );
}

HAPI_NodeId
FHoudiniGeoPartObject::HapiObjectGetToInstanceId( HAPI_NodeId OtherAssetId ) const
{
    HAPI_NodeId ObjectToInstance = -1;
    HAPI_ObjectInfo ObjectInfo;

    if ( HapiObjectGetInfo( OtherAssetId, ObjectInfo ) )
        ObjectToInstance = ObjectInfo.objectToInstanceId;

    return ObjectToInstance;
}

HAPI_NodeId
FHoudiniGeoPartObject::HapiObjectGetToInstanceId() const
{
    return HapiObjectGetToInstanceId( AssetId );
}

bool
FHoudiniGeoPartObject::HapiObjectGetInfo( HAPI_ObjectInfo & ObjectInfo ) const
{
    return HapiObjectGetInfo( AssetId, ObjectInfo );
}

bool
FHoudiniGeoPartObject::HapiObjectGetInfo( HAPI_NodeId OtherAssetId, HAPI_ObjectInfo & ObjectInfo ) const
{
    FMemory::Memset< HAPI_ObjectInfo >( ObjectInfo, 0 );

    HAPI_Result Result = FHoudiniApi::GetObjectInfo(
        FHoudiniEngine::Get().GetSession(), ObjectId, &ObjectInfo );
    if ( Result != HAPI_RESULT_SUCCESS )
        return false;

    return true;
}

FHoudiniEngineString
FHoudiniGeoPartObject::HapiObjectGetName( HAPI_NodeId OtherAssetId ) const
{
    HAPI_StringHandle StringHandle = -1;
    HAPI_ObjectInfo ObjectInfo;

    if ( HapiObjectGetInfo( OtherAssetId, ObjectInfo ) )
        StringHandle = ObjectInfo.nameSH;

    return FHoudiniEngineString( StringHandle );
}

FHoudiniEngineString
FHoudiniGeoPartObject::HapiObjectGetName() const
{
    return HapiObjectGetName( AssetId );
}

FHoudiniEngineString
FHoudiniGeoPartObject::HapiObjectGetInstancePath( HAPI_NodeId OtherAssetId ) const
{
    HAPI_StringHandle StringHandle = -1;
    HAPI_ObjectInfo ObjectInfo;

    if ( HapiObjectGetInfo( OtherAssetId, ObjectInfo ) )
        StringHandle = ObjectInfo.objectInstancePathSH;

    return FHoudiniEngineString( StringHandle );
}

FHoudiniEngineString
FHoudiniGeoPartObject::HapiObjectGetInstancePath() const
{
    return HapiObjectGetInstancePath( AssetId );
}

bool
FHoudiniGeoPartObject::HapiObjectIsVisible( HAPI_NodeId OtherAssetId ) const
{
    bool bIsObjectVisible = false;
    HAPI_ObjectInfo ObjectInfo;

    if ( HapiObjectGetInfo( OtherAssetId, ObjectInfo ) )
        bIsObjectVisible = ObjectInfo.isVisible;

    return bIsObjectVisible;
}

bool
FHoudiniGeoPartObject::HapiObjectIsVisible() const
{
    return HapiObjectIsVisible( AssetId );
}

bool
FHoudiniGeoPartObject::HapiObjectIsInstancer( HAPI_NodeId OtherAssetId ) const
{
    bool bIsObjectInstancer = false;
    HAPI_ObjectInfo ObjectInfo;

    if ( HapiObjectGetInfo( OtherAssetId, ObjectInfo ) )
        bIsObjectInstancer = ObjectInfo.isInstancer;

    return bIsObjectInstancer;
}

bool
FHoudiniGeoPartObject::HapiObjectIsInstancer() const
{
    return HapiObjectIsInstancer( AssetId );
}

bool
FHoudiniGeoPartObject::HapiObjectHasTransformChanged( HAPI_NodeId OtherAssetId ) const
{
    bool bObjectTransformHasChanged = false;
    HAPI_ObjectInfo ObjectInfo;

    if ( HapiObjectGetInfo( OtherAssetId, ObjectInfo ) )
        bObjectTransformHasChanged = ObjectInfo.hasTransformChanged;

    return bObjectTransformHasChanged;
}

bool
FHoudiniGeoPartObject::HapiObjectHasTransformChanged() const
{
    return HapiObjectHasTransformChanged( AssetId );
}

bool
FHoudiniGeoPartObject::HapiObjectHaveGeosChanged( HAPI_NodeId OtherAssetId ) const
{
    bool bGeosChanged = false;
    HAPI_ObjectInfo ObjectInfo;

    if ( HapiObjectGetInfo( OtherAssetId, ObjectInfo ) )
        bGeosChanged = ObjectInfo.haveGeosChanged;

    return bGeosChanged;
}

bool
FHoudiniGeoPartObject::HapiObjectHaveGeosChanged() const
{
    return HapiObjectHaveGeosChanged( AssetId );
}

int32
FHoudiniGeoPartObject::HapiObjectGetGeoCount( HAPI_NodeId OtherAssetId ) const
{
    int32 GeoCount = 0;
    HAPI_ObjectInfo ObjectInfo;

    if ( HapiObjectGetInfo( OtherAssetId, ObjectInfo ) )
        GeoCount = ObjectInfo.geoCount;

    return GeoCount;
}


int32
FHoudiniGeoPartObject::HapiObjectGetGeoCount() const
{
    return HapiObjectGetGeoCount( AssetId );
}

HAPI_NodeId
FHoudiniGeoPartObject::HapiObjectGetNodeId() const
{
    HAPI_NodeId NodeId = -1;
    HAPI_ObjectInfo ObjectInfo;

    if (HapiObjectGetInfo(ObjectInfo))
        NodeId = ObjectInfo.nodeId;

    return NodeId;
}

HAPI_NodeId
FHoudiniGeoPartObject::HapiObjectGetNodeId( HAPI_NodeId OtherAssetId ) const
{
    HAPI_NodeId NodeId = -1;
    HAPI_ObjectInfo ObjectInfo;

    if ( HapiObjectGetInfo( OtherAssetId, ObjectInfo ) )
        NodeId = ObjectInfo.nodeId;

    return NodeId;
}

bool
FHoudiniGeoPartObject::HapiGeoGetInfo( HAPI_GeoInfo & GeoInfo ) const
{
    return HapiGeoGetInfo( AssetId, GeoInfo );
}

bool
FHoudiniGeoPartObject::HapiGeoGetInfo( HAPI_NodeId OtherAssetId, HAPI_GeoInfo & GeoInfo ) const
{
    FMemory::Memset< HAPI_GeoInfo >( GeoInfo, 0 );

    if ( FHoudiniApi::GetGeoInfo(
        FHoudiniEngine::Get().GetSession(),
        GeoId, &GeoInfo ) == HAPI_RESULT_SUCCESS )
    {
        return true;
    }

    return false;
}

HAPI_GeoType
FHoudiniGeoPartObject::HapiGeoGetType( HAPI_NodeId OtherAssetId ) const
{
    HAPI_GeoType GeoType = HAPI_GEOTYPE_INVALID;
    HAPI_GeoInfo GeoInfo;

    if ( HapiGeoGetInfo( OtherAssetId, GeoInfo ) )
        GeoType = GeoInfo.type;

    return GeoType;
}

HAPI_GeoType
FHoudiniGeoPartObject::HapiGeoGetType() const
{
    return HapiGeoGetType( AssetId );
}

FHoudiniEngineString
FHoudiniGeoPartObject::HapiGeoGetName( HAPI_NodeId OtherAssetId ) const
{
    HAPI_StringHandle StringHandle = -1;
    HAPI_GeoInfo GeoInfo;

    if ( HapiGeoGetInfo( OtherAssetId, GeoInfo ) )
        StringHandle = GeoInfo.nameSH;

    return FHoudiniEngineString( StringHandle );
}

FHoudiniEngineString
FHoudiniGeoPartObject::HapiGeoGetName() const
{
    return HapiGeoGetName( AssetId );
}

HAPI_NodeId
FHoudiniGeoPartObject::HapiGeoGetNodeId() const
{
    HAPI_NodeId NodeId = -1;
    HAPI_GeoInfo GeoInfo;

    if ( HapiGeoGetInfo( GeoInfo ) )
        NodeId = GeoInfo.nodeId;

    return NodeId;
}

HAPI_NodeId
FHoudiniGeoPartObject::HapiGeoGetNodeId( HAPI_NodeId OtherAssetId ) const
{
    HAPI_NodeId NodeId = -1;
    HAPI_GeoInfo GeoInfo;

    if ( HapiGeoGetInfo( OtherAssetId, GeoInfo ) )
        NodeId = GeoInfo.nodeId;

    return NodeId;
}

bool
FHoudiniGeoPartObject::HapiGeoIsEditable( HAPI_NodeId OtherAssetId ) const
{
    bool bLocalIsEditable = false;
    HAPI_GeoInfo GeoInfo;

    if ( HapiGeoGetInfo( OtherAssetId, GeoInfo ) )
        bLocalIsEditable = GeoInfo.isEditable;

    return bLocalIsEditable;
}

bool
FHoudiniGeoPartObject::HapiGeoIsEditable() const
{
    return HapiGeoIsEditable( AssetId );
}

bool
FHoudiniGeoPartObject::HapiGeoIsTemplated( HAPI_NodeId OtherAssetId ) const
{
    bool bIsTemplated = false;
    HAPI_GeoInfo GeoInfo;

    if ( HapiGeoGetInfo( OtherAssetId, GeoInfo ) )
        bIsTemplated = GeoInfo.isTemplated;

    return bIsTemplated;
}

bool
FHoudiniGeoPartObject::HapiGeoIsTemplated() const
{
    return HapiGeoIsTemplated( AssetId );
}

bool
FHoudiniGeoPartObject::HapiGeoIsDisplayGeo( HAPI_NodeId OtherAssetId ) const
{
    bool bIsDisplayGeo = false;
    HAPI_GeoInfo GeoInfo;

    if ( HapiGeoGetInfo( OtherAssetId, GeoInfo ) )
        bIsDisplayGeo = GeoInfo.isDisplayGeo;

    return bIsDisplayGeo;
}

bool
FHoudiniGeoPartObject::HapiGeoIsDisplayGeo() const
{
    return HapiGeoIsDisplayGeo( AssetId );
}

bool
FHoudiniGeoPartObject::HapiGeoHasChanged( HAPI_NodeId OtherAssetId ) const
{
    bool bGeoChanged = false;
    HAPI_GeoInfo GeoInfo;

    if ( HapiGeoGetInfo( OtherAssetId, GeoInfo ) )
        bGeoChanged = GeoInfo.hasGeoChanged;

    return bGeoChanged;
}

bool
FHoudiniGeoPartObject::HapiGeoHasChanged() const
{
    return HapiGeoHasChanged( AssetId );
}

bool
FHoudiniGeoPartObject::HapiGeoHasMaterialChanged( HAPI_NodeId OtherAssetId ) const
{
    bool bHasMaterialChanged = false;
    HAPI_GeoInfo GeoInfo;

    if ( HapiGeoGetInfo( OtherAssetId, GeoInfo ) )
        bHasMaterialChanged = GeoInfo.hasMaterialChanged;

    return bHasMaterialChanged;
}

bool
FHoudiniGeoPartObject::HapiGeoHasMaterialChanged() const
{
    return HapiGeoHasMaterialChanged( AssetId );
}

int32
FHoudiniGeoPartObject::HapiGeoGetPointGroupCount( HAPI_NodeId OtherAssetId ) const
{
    int32 PointGroupCount = 0;
    HAPI_GeoInfo GeoInfo;

    if ( HapiGeoGetInfo( OtherAssetId, GeoInfo ) )
        PointGroupCount = GeoInfo.pointGroupCount;

    return PointGroupCount;
}

int32
FHoudiniGeoPartObject::HapiGeoGetPointGroupCount() const
{
    return HapiGeoGetPointGroupCount( AssetId );
}

int32
FHoudiniGeoPartObject::HapiGeoGetPrimitiveGroupCount( HAPI_NodeId OtherAssetId ) const
{
    int32 PrimitiveGroupCount = 0;
    HAPI_GeoInfo GeoInfo;

    if ( HapiGeoGetInfo( OtherAssetId, GeoInfo ) )
        PrimitiveGroupCount = GeoInfo.primitiveGroupCount;

    return PrimitiveGroupCount;
}

int32
FHoudiniGeoPartObject::HapiGeoGetPrimitiveGroupCount() const
{
    return HapiGeoGetPrimitiveGroupCount( AssetId );
}

int32
FHoudiniGeoPartObject::HapiGeoGetPartCount( HAPI_NodeId OtherAssetId ) const
{
    int32 PartCount = 0;
    HAPI_GeoInfo GeoInfo;

    if ( HapiGeoGetInfo( OtherAssetId, GeoInfo ) )
        PartCount = GeoInfo.partCount;

    return PartCount;
}

int32
FHoudiniGeoPartObject::HapiGeoGetPartCount() const
{
    return HapiGeoGetPartCount( AssetId );
}

bool
FHoudiniGeoPartObject::HapiPartGetInfo( HAPI_PartInfo & PartInfo ) const
{
    return HapiPartGetInfo( AssetId, PartInfo );
}

bool
FHoudiniGeoPartObject::HapiPartGetInfo( HAPI_NodeId OtherAssetId, HAPI_PartInfo & PartInfo ) const
{
    FMemory::Memset< HAPI_PartInfo >( PartInfo, 0 );

    if ( FHoudiniApi::GetPartInfo(
        FHoudiniEngine::Get().GetSession(),
        GeoId, PartId, &PartInfo ) == HAPI_RESULT_SUCCESS )
    {
        return true;
    }

    return false;
}

FHoudiniEngineString
FHoudiniGeoPartObject::HapiPartGetName( HAPI_NodeId OtherAssetId ) const
{
    HAPI_StringHandle StringHandle = -1;
    HAPI_PartInfo PartInfo;

    if ( HapiPartGetInfo( OtherAssetId, PartInfo ) )
        StringHandle = PartInfo.nameSH;

    return FHoudiniEngineString( StringHandle );
}

FHoudiniEngineString
FHoudiniGeoPartObject::HapiPartGetName() const
{
    return HapiPartGetName( AssetId );
}

HAPI_PartType
FHoudiniGeoPartObject::HapiPartGetType( HAPI_NodeId OtherAssetId ) const
{
    HAPI_PartType PartType = HAPI_PARTTYPE_INVALID;
    HAPI_PartInfo PartInfo;

    if ( HapiPartGetInfo( OtherAssetId, PartInfo ) )
        PartType = PartInfo.type;

    return PartType;
}

HAPI_PartType
FHoudiniGeoPartObject::HapiPartGetType() const
{
    return HapiPartGetType( AssetId );
}

int32
FHoudiniGeoPartObject::HapiPartGetFaceCount( HAPI_NodeId OtherAssetId ) const
{
    int32 FaceCount = 0;
    HAPI_PartInfo PartInfo;

    if ( HapiPartGetInfo( OtherAssetId, PartInfo ) )
        FaceCount = PartInfo.faceCount;

    return FaceCount;
}

int32
FHoudiniGeoPartObject::HapiPartGetFaceCount() const
{
    return HapiPartGetFaceCount( AssetId );
}

int32
FHoudiniGeoPartObject::HapiPartGetVertexCount( HAPI_NodeId OtherAssetId ) const
{
    int32 VertexCount = 0;
    HAPI_PartInfo PartInfo;

    if ( HapiPartGetInfo( OtherAssetId, PartInfo ) )
        VertexCount = PartInfo.vertexCount;

    return VertexCount;
}

int32
FHoudiniGeoPartObject::HapiPartGetVertexCount() const
{
    return HapiPartGetVertexCount( AssetId );
}

int32
FHoudiniGeoPartObject::HapiPartGetPointCount( HAPI_NodeId OtherAssetId ) const
{
    int32 PointCount = 0;
    HAPI_PartInfo PartInfo;

    if ( HapiPartGetInfo( OtherAssetId, PartInfo ) )
        PointCount = PartInfo.pointCount;

    return PointCount;
}

int32
FHoudiniGeoPartObject::HapiPartGetPointCount() const
{
    return HapiPartGetPointCount( AssetId );
}

bool
FHoudiniGeoPartObject::HapiPartIsInstanced( HAPI_NodeId OtherAssetId ) const
{
    bool bPartIsInstanced = false;
    HAPI_PartInfo PartInfo;

    if ( HapiPartGetInfo( OtherAssetId, PartInfo ) )
        bPartIsInstanced = PartInfo.isInstanced;

    return bPartIsInstanced;
}

bool
FHoudiniGeoPartObject::HapiPartIsInstanced() const
{
    return HapiPartIsInstanced( AssetId );
}

int32
FHoudiniGeoPartObject::HapiPartGetInstancedPartCount( HAPI_NodeId OtherAssetId ) const
{
    int32 InstancedPartCount = 0;
    HAPI_PartInfo PartInfo;

    if ( HapiPartGetInfo( OtherAssetId, PartInfo ) )
        InstancedPartCount = PartInfo.instancedPartCount;

    return InstancedPartCount;
}

int32
FHoudiniGeoPartObject::HapiPartGetInstancedPartCount() const
{
    return HapiPartGetInstancedPartCount( AssetId );
}

int32
FHoudiniGeoPartObject::HapiPartGetInstanceCount( HAPI_NodeId OtherAssetId ) const
{
    int32 InstanceCount = 0;
    HAPI_PartInfo PartInfo;

    if ( HapiPartGetInfo( OtherAssetId, PartInfo ) )
        InstanceCount = PartInfo.instanceCount;

    return InstanceCount;
}

int32
FHoudiniGeoPartObject::HapiPartGetInstanceCount() const
{
    return HapiPartGetInstanceCount( AssetId );
}

int32
FHoudiniGeoPartObject::HapiPartGetPointAttributeCount( HAPI_NodeId OtherAssetId ) const
{
    int32 PointAttributeCount = 0;
    HAPI_PartInfo PartInfo;

    if ( HapiPartGetInfo( OtherAssetId, PartInfo ) )
        PointAttributeCount = PartInfo.attributeCounts[ HAPI_ATTROWNER_POINT ];

    return PointAttributeCount;
}

int32
FHoudiniGeoPartObject::HapiPartGetPointAttributeCount() const
{
    return HapiPartGetPointAttributeCount( AssetId );
}

int32
FHoudiniGeoPartObject::HapiPartGetVertexAttributeCount( HAPI_NodeId OtherAssetId ) const
{
    int32 VertexAttributeCount = 0;
    HAPI_PartInfo PartInfo;

    if ( HapiPartGetInfo( OtherAssetId, PartInfo ) )
        VertexAttributeCount = PartInfo.attributeCounts[ HAPI_ATTROWNER_VERTEX ];

    return VertexAttributeCount;
}

int32
FHoudiniGeoPartObject::HapiPartGetVertexAttributeCount() const
{
    return HapiPartGetVertexAttributeCount( AssetId );
}

int32
FHoudiniGeoPartObject::HapiPartGetPrimitiveAttributeCount( HAPI_NodeId OtherAssetId ) const
{
    int32 PrimitiveAttributeCount = 0;
    HAPI_PartInfo PartInfo;

    if ( HapiPartGetInfo( OtherAssetId, PartInfo ) )
        PrimitiveAttributeCount = PartInfo.attributeCounts[ HAPI_ATTROWNER_PRIM ];

    return PrimitiveAttributeCount;
}

int32
FHoudiniGeoPartObject::HapiPartGetPrimitiveAttributeCount() const
{
    return HapiPartGetPrimitiveAttributeCount( AssetId );
}

int32
FHoudiniGeoPartObject::HapiPartGetDetailAttributeCount( HAPI_NodeId OtherAssetId ) const
{
    int32 DetailAttributeCount = 0;
    HAPI_PartInfo PartInfo;

    if ( HapiPartGetInfo( OtherAssetId, PartInfo ) )
        DetailAttributeCount = PartInfo.attributeCounts[ HAPI_ATTROWNER_DETAIL ];

    return DetailAttributeCount;
}

int32
FHoudiniGeoPartObject::HapiPartGetDetailAttributeCount() const
{
    return HapiPartGetDetailAttributeCount( AssetId );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeInfo(
    HAPI_NodeId OtherAssetId, const char * AttributeName,
    HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & AttributeInfo ) const
{
    FMemory::Memset< HAPI_AttributeInfo >( AttributeInfo, 0 );

    if ( FHoudiniApi::GetAttributeInfo(
        FHoudiniEngine::Get().GetSession(),
        GeoId, PartId, AttributeName, AttributeOwner,
        &AttributeInfo ) == HAPI_RESULT_SUCCESS )
    {
         return true;
    }

    return false;
}

bool
FHoudiniGeoPartObject::HapiGetAttributeInfo(
    const char * AttributeName, HAPI_AttributeOwner AttributeOwner,
    HAPI_AttributeInfo & AttributeInfo ) const
{
    return HapiGetAttributeInfo( AssetId, AttributeName, AttributeOwner, AttributeInfo );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeInfo(
    HAPI_NodeId OtherAssetId, const std::string & AttributeName,
    HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & AttributeInfo) const
{
    return HapiGetAttributeInfo( OtherAssetId, AttributeName.c_str(), AttributeOwner, AttributeInfo );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeInfo(
    const std::string & AttributeName, HAPI_AttributeOwner AttributeOwner,
    HAPI_AttributeInfo & AttributeInfo) const
{
    return HapiGetAttributeInfo( AssetId, AttributeName, AttributeOwner, AttributeInfo );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeInfo(
    HAPI_NodeId OtherAssetId, const FString & AttributeName,
    HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & AttributeInfo ) const
{
    std::string AttributeNameRaw = "";
    FHoudiniEngineUtils::ConvertUnrealString( AttributeName, AttributeNameRaw );

    return HapiGetAttributeInfo( OtherAssetId, AttributeNameRaw, AttributeOwner, AttributeInfo );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeInfo(
    const FString & AttributeName, HAPI_AttributeOwner AttributeOwner,
    HAPI_AttributeInfo & AttributeInfo ) const
{
    return HapiGetAttributeInfo( AssetId, AttributeName, AttributeOwner, AttributeInfo );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeInfo(
    HAPI_NodeId OtherAssetId, const char * AttributeName,
    HAPI_AttributeInfo & AttributeInfo ) const
{
    for ( int32 AttrIdx = 0; AttrIdx < HAPI_ATTROWNER_MAX; ++AttrIdx )
    {
        if ( !HapiGetAttributeInfo(
            OtherAssetId, AttributeName, (HAPI_AttributeOwner) AttrIdx, AttributeInfo ) )
        {
            AttributeInfo.exists = false;
            return false;
        }

        if ( AttributeInfo.exists )
            break;
    }

    return true;
}

bool
FHoudiniGeoPartObject::HapiGetAttributeInfo( const char * AttributeName, HAPI_AttributeInfo & AttributeInfo ) const
{
    return HapiGetAttributeInfo( AssetId, AttributeName, AttributeInfo );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeInfo(
    HAPI_NodeId OtherAssetId, const std::string & AttributeName,
    HAPI_AttributeInfo & AttributeInfo ) const
{
    return HapiGetAttributeInfo( OtherAssetId, AttributeName.c_str(), AttributeInfo );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeInfo( const std::string & AttributeName, HAPI_AttributeInfo & AttributeInfo ) const
{
    return HapiGetAttributeInfo( AssetId, AttributeName, AttributeInfo );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeInfo(
    HAPI_NodeId OtherAssetId, const FString & AttributeName,
    HAPI_AttributeInfo & AttributeInfo) const
{
    std::string AttributeNameRaw = "";
    FHoudiniEngineUtils::ConvertUnrealString( AttributeName, AttributeNameRaw );

    return HapiGetAttributeInfo( OtherAssetId, AttributeNameRaw, AttributeInfo );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeInfo( const FString & AttributeName, HAPI_AttributeInfo & AttributeInfo ) const
{
    return HapiGetAttributeInfo( AssetId, AttributeName, AttributeInfo );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsFloat(
    HAPI_NodeId OtherAssetId, const char * AttributeName,
    HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< float > & AttributeData,
    int32 TupleSize ) const
{
    AttributeData.SetNumUninitialized( 0 );

    if ( !HapiGetAttributeInfo( OtherAssetId, AttributeName, AttributeOwner, ResultAttributeInfo ) )
    {
        ResultAttributeInfo.exists = false;
        return false;
    }

    if ( !ResultAttributeInfo.exists )
        return false;

    if ( TupleSize > 0 )
        ResultAttributeInfo.tupleSize = TupleSize;

    AttributeData.SetNumUninitialized( ResultAttributeInfo.count * ResultAttributeInfo.tupleSize );

    if ( FHoudiniApi::GetAttributeFloatData(
        FHoudiniEngine::Get().GetSession(), GeoId, PartId, AttributeName,
        &ResultAttributeInfo, -1, &AttributeData[ 0 ], 0,
        ResultAttributeInfo.count ) == HAPI_RESULT_SUCCESS )
    {
        return true;
    }

    ResultAttributeInfo.exists = false;
    return false;
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsFloat(
    const char * AttributeName, HAPI_AttributeOwner AttributeOwner,
    HAPI_AttributeInfo & ResultAttributeInfo, TArray< float > & AttributeData, int32 TupleSize ) const
{
    return HapiGetAttributeDataAsFloat(
        AssetId, AttributeName, AttributeOwner, ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsFloat(
    HAPI_NodeId OtherAssetId, const std::string & AttributeName,
    HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & ResultAttributeInfo, TArray< float > & AttributeData,
    int32 TupleSize ) const
{
    return HapiGetAttributeDataAsFloat(
        OtherAssetId, AttributeName.c_str(), AttributeOwner, ResultAttributeInfo,
        AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsFloat(
    const std::string & AttributeName,
    HAPI_AttributeOwner AttributeOwner,
    HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< float > & AttributeData,
    int32 TupleSize ) const
{
    return HapiGetAttributeDataAsFloat(
        AssetId, AttributeName, AttributeOwner, ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsFloat(
    HAPI_NodeId OtherAssetId, const FString & AttributeName,
    HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< float > & AttributeData,
    int32 TupleSize ) const
{
    std::string AttributeNameRaw = "";
    FHoudiniEngineUtils::ConvertUnrealString( AttributeName, AttributeNameRaw );

    return HapiGetAttributeDataAsFloat(
        OtherAssetId, AttributeNameRaw, AttributeOwner, ResultAttributeInfo,
        AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsFloat(
    const FString & AttributeName, HAPI_AttributeOwner AttributeOwner,
    HAPI_AttributeInfo & ResultAttributeInfo, TArray< float > & AttributeData, int32 TupleSize ) const
{
    return HapiGetAttributeDataAsFloat(
        AssetId, AttributeName, AttributeOwner, ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsFloat(
    HAPI_NodeId OtherAssetId, const char * AttributeName,
    HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< float > & AttributeData, int32 TupleSize ) const
{
    for ( int32 AttrIdx = 0; AttrIdx < HAPI_ATTROWNER_MAX; ++AttrIdx )
    {
        if ( !HapiGetAttributeDataAsFloat(
            OtherAssetId, AttributeName, (HAPI_AttributeOwner) AttrIdx,
            ResultAttributeInfo, AttributeData, TupleSize ) )
        {
            ResultAttributeInfo.exists = false;
            return false;
        }

        if ( ResultAttributeInfo.exists )
            break;
    }

    return true;
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsFloat(
    const char * AttributeName, HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< float > & AttributeData, int32 TupleSize ) const
{
    return HapiGetAttributeDataAsFloat( AssetId, AttributeName, ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsFloat(
    HAPI_NodeId OtherAssetId, const std::string & AttributeName,
    HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< float > & AttributeData, int32 TupleSize ) const
{
    return HapiGetAttributeDataAsFloat(
        OtherAssetId, AttributeName.c_str(), ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsFloat(
    const std::string & AttributeName,
    HAPI_AttributeInfo & ResultAttributeInfo,
    TArray <float > & AttributeData, int32 TupleSize ) const
{
    return HapiGetAttributeDataAsFloat( AssetId, AttributeName, ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsFloat(
    HAPI_NodeId OtherAssetId, const FString & AttributeName,
    HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< float > & AttributeData, int32 TupleSize ) const
{
    std::string AttributeNameRaw = "";
    FHoudiniEngineUtils::ConvertUnrealString( AttributeName, AttributeNameRaw );

    return HapiGetAttributeDataAsFloat(
        OtherAssetId, AttributeNameRaw, ResultAttributeInfo,
        AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsFloat(
    const FString & AttributeName,
    HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< float > & AttributeData, int32 TupleSize ) const
{
    return HapiGetAttributeDataAsFloat( AssetId, AttributeName, ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsInt(
    HAPI_NodeId OtherAssetId, const char * AttributeName,
    HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< int32 > & AttributeData,
    int32 TupleSize ) const
{
    AttributeData.SetNumUninitialized( 0 );

    if ( !HapiGetAttributeInfo( OtherAssetId, AttributeName, AttributeOwner, ResultAttributeInfo ) )
    {
        ResultAttributeInfo.exists = false;
        return false;
    }

    if ( !ResultAttributeInfo.exists )
        return false;

    if ( TupleSize > 0 )
        ResultAttributeInfo.tupleSize = TupleSize;

    AttributeData.SetNumUninitialized( ResultAttributeInfo.count * ResultAttributeInfo.tupleSize );

    if ( FHoudiniApi::GetAttributeIntData(
        FHoudiniEngine::Get().GetSession(), GeoId, PartId, AttributeName,
        &ResultAttributeInfo, -1, &AttributeData[ 0 ], 0,
        ResultAttributeInfo.count ) == HAPI_RESULT_SUCCESS )
    {
        return true;
    }

    ResultAttributeInfo.exists = false;
    return false;
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsInt(
    const char * AttributeName, HAPI_AttributeOwner AttributeOwner,
    HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< int32 > & AttributeData, int32 TupleSize ) const
{
    return HapiGetAttributeDataAsInt(
        AssetId, AttributeName, AttributeOwner, ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsInt(
    HAPI_NodeId OtherAssetId, const std::string & AttributeName,
    HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< int32 > & AttributeData,
    int32 TupleSize ) const
{
    return HapiGetAttributeDataAsInt(
        OtherAssetId, AttributeName.c_str(), AttributeOwner, ResultAttributeInfo,
        AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsInt(
    const std::string & AttributeName,
    HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< int32 > & AttributeData,
    int32 TupleSize ) const
{
    return HapiGetAttributeDataAsInt(
        AssetId, AttributeName, AttributeOwner, ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsInt(
    HAPI_NodeId OtherAssetId, const FString & AttributeName,
    HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< int32 > & AttributeData,
    int32 TupleSize ) const
{
    std::string AttributeNameRaw = "";
    FHoudiniEngineUtils::ConvertUnrealString( AttributeName, AttributeNameRaw );

    return HapiGetAttributeDataAsInt(
        OtherAssetId, AttributeNameRaw, AttributeOwner, ResultAttributeInfo,
        AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsInt(
    const FString & AttributeName, HAPI_AttributeOwner AttributeOwner,
    HAPI_AttributeInfo & ResultAttributeInfo, TArray< int32 > & AttributeData, int32 TupleSize ) const
{
    return HapiGetAttributeDataAsInt(
        AssetId, AttributeName, AttributeOwner, ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsInt(
    HAPI_NodeId OtherAssetId, const char * AttributeName,
    HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< int32 > & AttributeData, int32 TupleSize ) const
{
    for ( int32 AttrIdx = 0; AttrIdx < HAPI_ATTROWNER_MAX; ++AttrIdx )
    {
        if ( !HapiGetAttributeDataAsInt(
            OtherAssetId, AttributeName, (HAPI_AttributeOwner) AttrIdx,
            ResultAttributeInfo, AttributeData, TupleSize ) )
        {
            ResultAttributeInfo.exists = false;
            return false;
        }

        if ( ResultAttributeInfo.exists )
            break;
    }

    return true;
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsInt(
    const char * AttributeName, HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< int32 > & AttributeData, int32 TupleSize ) const
{
    return HapiGetAttributeDataAsInt( AssetId, AttributeName, ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsInt(
    HAPI_NodeId OtherAssetId, const std::string & AttributeName,
    HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< int32 > & AttributeData, int32 TupleSize ) const
{
    return HapiGetAttributeDataAsInt(
        OtherAssetId, AttributeName.c_str(), ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsInt(
    const std::string & AttributeName,
    HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< int32 > & AttributeData, int32 TupleSize ) const
{
    return HapiGetAttributeDataAsInt( AssetId, AttributeName, ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsInt(
    HAPI_NodeId OtherAssetId, const FString & AttributeName,
    HAPI_AttributeInfo & ResultAttributeInfo, TArray< int32 > & AttributeData, int32 TupleSize ) const
{
    std::string AttributeNameRaw = "";
    FHoudiniEngineUtils::ConvertUnrealString( AttributeName, AttributeNameRaw );

    return HapiGetAttributeDataAsInt(
        OtherAssetId, AttributeNameRaw, ResultAttributeInfo,
        AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsInt(
    const FString & AttributeName,
    HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< int32 > & AttributeData, int32 TupleSize ) const
{
    return HapiGetAttributeDataAsInt( AssetId, AttributeName, ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsString(
    HAPI_NodeId OtherAssetId, const char * AttributeName,
    HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< FString > & AttributeData,
    int32 TupleSize ) const
{
    AttributeData.SetNumUninitialized( 0 );

    if ( !HapiGetAttributeInfo( OtherAssetId, AttributeName, AttributeOwner, ResultAttributeInfo ) )
    {
        ResultAttributeInfo.exists = false;
        return false;
    }

    if ( !ResultAttributeInfo.exists )
        return false;

    if ( TupleSize > 0 )
        ResultAttributeInfo.tupleSize = TupleSize;

    TArray< HAPI_StringHandle > StringHandles;
    StringHandles.Init( -1, ResultAttributeInfo.count * ResultAttributeInfo.tupleSize );
    if ( FHoudiniApi::GetAttributeStringData(
        FHoudiniEngine::Get().GetSession(),
        GeoId, PartId, AttributeName, &ResultAttributeInfo,
        &StringHandles[ 0 ], 0, ResultAttributeInfo.count ) == HAPI_RESULT_SUCCESS )
    {
        // Use a map to minimize the number of HAPI calls for performance!
        TMap<int32, FString> StringHandleToStringMap;
        for ( int32 Idx = 0; Idx < StringHandles.Num(); ++Idx )
        {
            FString* FoundString = StringHandleToStringMap.Find( StringHandles[ Idx ] );
            if ( FoundString )
            {
                AttributeData.Add( *FoundString );
            }
            else
            {
                FString HapiString = TEXT("");
                FHoudiniEngineString HoudiniEngineString( StringHandles[ Idx ] );
                HoudiniEngineString.ToFString( HapiString );
                StringHandleToStringMap.Add( StringHandles[ Idx ], HapiString );
                AttributeData.Add( *HapiString );
            }
        }

        return true;
    }

    ResultAttributeInfo.exists = false;
    return false;
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsString(
    const char * AttributeName, HAPI_AttributeOwner AttributeOwner,
    HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< FString > & AttributeData, int32 TupleSize ) const
{
    return HapiGetAttributeDataAsString(
        AssetId, AttributeName, AttributeOwner, ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsString(
    HAPI_NodeId OtherAssetId, const std::string & AttributeName,
    HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< FString > & AttributeData,
    int32 TupleSize ) const
{
    return HapiGetAttributeDataAsString(
        OtherAssetId, AttributeName.c_str(), AttributeOwner, ResultAttributeInfo,
        AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsString(
    const std::string & AttributeName,
    HAPI_AttributeOwner AttributeOwner,
    HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< FString > & AttributeData,
    int32 TupleSize ) const
{
    return HapiGetAttributeDataAsString(
        AssetId, AttributeName, AttributeOwner, ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsString(
    HAPI_NodeId OtherAssetId, const FString & AttributeName,
    HAPI_AttributeOwner AttributeOwner,
    HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< FString > & AttributeData,
    int32 TupleSize ) const
{
    std::string AttributeNameRaw = "";
    FHoudiniEngineUtils::ConvertUnrealString( AttributeName, AttributeNameRaw );

    return HapiGetAttributeDataAsString(
        OtherAssetId, AttributeNameRaw, AttributeOwner, ResultAttributeInfo,
        AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsString(
    const FString & AttributeName, HAPI_AttributeOwner AttributeOwner,
    HAPI_AttributeInfo & ResultAttributeInfo, TArray< FString > & AttributeData, int32 TupleSize ) const
{
    return HapiGetAttributeDataAsString(
        AssetId, AttributeName, AttributeOwner, ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsString(
    HAPI_NodeId OtherAssetId, const char * AttributeName,
    HAPI_AttributeInfo & ResultAttributeInfo, TArray< FString > & AttributeData, int32 TupleSize ) const
{
    for ( int32 AttrIdx = 0; AttrIdx < HAPI_ATTROWNER_MAX; ++AttrIdx )
    {
        if ( !HapiGetAttributeDataAsString(
            OtherAssetId, AttributeName, (HAPI_AttributeOwner) AttrIdx,
            ResultAttributeInfo, AttributeData, TupleSize ) )
        {
            ResultAttributeInfo.exists = false;
            return false;
        }

        if ( ResultAttributeInfo.exists )
            break;
    }

    return true;
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsString(
    const char * AttributeName, HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< FString > & AttributeData, int32 TupleSize ) const
{
    return HapiGetAttributeDataAsString( AssetId, AttributeName, ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsString(
    HAPI_NodeId OtherAssetId, const std::string & AttributeName,
    HAPI_AttributeInfo & ResultAttributeInfo, TArray< FString > & AttributeData, int32 TupleSize ) const
{
    return HapiGetAttributeDataAsString(
        OtherAssetId, AttributeName.c_str(), ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsString(
    const std::string & AttributeName,
    HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< FString > & AttributeData, int32 TupleSize ) const
{
    return HapiGetAttributeDataAsString( AssetId, AttributeName, ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsString(
    HAPI_NodeId OtherAssetId, const FString & AttributeName,
    HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< FString > & AttributeData, int32 TupleSize ) const
{
    std::string AttributeNameRaw = "";
    FHoudiniEngineUtils::ConvertUnrealString( AttributeName, AttributeNameRaw );

    return HapiGetAttributeDataAsString(
        OtherAssetId, AttributeNameRaw, ResultAttributeInfo,
        AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeDataAsString(
    const FString & AttributeName,
    HAPI_AttributeInfo & ResultAttributeInfo,
    TArray< FString > & AttributeData, int32 TupleSize ) const
{
    return HapiGetAttributeDataAsString( AssetId, AttributeName, ResultAttributeInfo, AttributeData, TupleSize );
}

bool
FHoudiniGeoPartObject::HapiObjectGetUniqueInstancerMaterialId( HAPI_NodeId & MaterialId ) const
{
    return HapiObjectGetUniqueInstancerMaterialId( AssetId, MaterialId );
}

bool
FHoudiniGeoPartObject::HapiObjectGetUniqueInstancerMaterialId(
    HAPI_NodeId OtherAssetId, HAPI_NodeId& MaterialId ) const
{
    MaterialId = -1;

    if ( HapiObjectIsInstancer( OtherAssetId ) )
    {
        HAPI_Bool bSingleFaceMaterial = false;
        if ( FHoudiniApi::GetMaterialNodeIdsOnFaces(
            FHoudiniEngine::Get().GetSession(),
            GeoId, PartId, &bSingleFaceMaterial,
            &MaterialId, 0, 1 ) == HAPI_RESULT_SUCCESS )
        {
            return true;
        }
    }

    return false;
}

bool
FHoudiniGeoPartObject::HapiPartGetUniqueMaterialIds( TSet< HAPI_NodeId > & MaterialIds ) const
{
    return HapiPartGetUniqueMaterialIds( AssetId, MaterialIds );
}

bool
FHoudiniGeoPartObject::HapiPartGetUniqueMaterialIds(
    HAPI_NodeId OtherAssetId,
    TSet< HAPI_NodeId > & MaterialIds ) const
{
    MaterialIds.Empty();

    int32 FaceCount = HapiPartGetFaceCount( OtherAssetId );
    if ( FaceCount > 0 )
    {
        TArray< HAPI_NodeId > FaceMaterialIds;
        FaceMaterialIds.SetNumUninitialized( FaceCount );

        HAPI_Bool bSingleFaceMaterial = false;
        if ( FHoudiniApi::GetMaterialNodeIdsOnFaces(
            FHoudiniEngine::Get().GetSession(),
            GeoId, PartId, &bSingleFaceMaterial,
            &FaceMaterialIds[0], 0, FaceCount ) == HAPI_RESULT_SUCCESS )
        {
            MaterialIds.Append( FaceMaterialIds );
            return true;
        }
    }

    return false;
}

bool
FHoudiniGeoPartObject::HapiGetAllAttributeNames( HAPI_NodeId OtherAssetId, TArray< FString > & AttributeNames ) const
{
    AttributeNames.Empty();

    for ( int32 AttrIdx = HAPI_ATTROWNER_VERTEX; AttrIdx < HAPI_ATTROWNER_MAX; ++AttrIdx )
    {
        TArray< FString > AttributeValues;
        if ( HapiGetAttributeNames( OtherAssetId, (HAPI_AttributeOwner) AttrIdx, AttributeValues ) )
        {
            if ( AttributeValues.Num() > 0 )
                AttributeNames.Append(AttributeValues);
        }
    }

    return true;
}

bool
FHoudiniGeoPartObject::HapiGetAllAttributeNames( TArray< FString > & AttributeNames ) const
{
    return HapiGetAllAttributeNames( AssetId, AttributeNames );
}

bool
FHoudiniGeoPartObject::HapiGetAttributeNames(
    HAPI_NodeId OtherAssetId, HAPI_AttributeOwner AttributeOwner,
    TArray< FString > & AttributeNames ) const
{
    AttributeNames.Empty();
    int32 AttributeCount = 0;

    switch ( AttributeOwner)
    {
        case HAPI_ATTROWNER_POINT:
        {
            AttributeCount = HapiPartGetPointAttributeCount( OtherAssetId );
            break;
        }

        case HAPI_ATTROWNER_VERTEX:
        {
            AttributeCount = HapiPartGetVertexAttributeCount( OtherAssetId );
            break;
        }

        case HAPI_ATTROWNER_PRIM:
        {
            AttributeCount = HapiPartGetPrimitiveAttributeCount( OtherAssetId );
            break;
        }

        case HAPI_ATTROWNER_DETAIL:
        {
            AttributeCount = HapiPartGetDetailAttributeCount( OtherAssetId );
            break;
        }

        default:
        {
            return false;
        }
    }

    if ( AttributeCount > 0 )
    {
        TArray< HAPI_StringHandle > AttributeNameHandles;
        AttributeNameHandles.SetNumUninitialized( AttributeCount );

        if ( FHoudiniApi::GetAttributeNames(
            FHoudiniEngine::Get().GetSession(), GeoId, PartId,
            AttributeOwner, &AttributeNameHandles[ 0 ],
            AttributeCount ) != HAPI_RESULT_SUCCESS )
        {
            return false;
        }

        for ( int32 Idx = 0, Num = AttributeNameHandles.Num(); Idx < Num; ++Idx )
        {
            FString HapiString = TEXT( "" );
            FHoudiniEngineString HoudiniEngineString( AttributeNameHandles[ Idx ] );
            if ( HoudiniEngineString.ToFString( HapiString ) )
                AttributeNames.Add( HapiString );
        }
    }

    return true;
}

bool
FHoudiniGeoPartObject::HapiGetAttributeNames(
    HAPI_AttributeOwner AttributeOwner,
    TArray< FString > & AttributeNames ) const
{
    return HapiGetAttributeNames( AssetId, AttributeOwner, AttributeNames );
}

bool
FHoudiniGeoPartObject::HapiGetPointAttributeNames( HAPI_NodeId OtherAssetId, TArray< FString > & AttributeNames ) const
{
    return HapiGetAttributeNames( OtherAssetId, HAPI_ATTROWNER_POINT, AttributeNames );
}

bool
FHoudiniGeoPartObject::HapiGetPointAttributeNames( TArray< FString > & AttributeNames ) const
{
    return HapiGetPointAttributeNames( AssetId, AttributeNames );
}

bool
FHoudiniGeoPartObject::HapiGetVertexAttributeNames( HAPI_NodeId OtherAssetId, TArray< FString > & AttributeNames ) const
{
    return HapiGetAttributeNames( OtherAssetId, HAPI_ATTROWNER_VERTEX, AttributeNames );
}

bool
FHoudiniGeoPartObject::HapiGetVertexAttributeNames( TArray< FString > & AttributeNames ) const
{
    return HapiGetVertexAttributeNames( AssetId, AttributeNames );
}

bool
FHoudiniGeoPartObject::HapiGetPrimitiveAttributeNames(
    HAPI_NodeId OtherAssetId,
    TArray< FString > & AttributeNames ) const
{
    return HapiGetAttributeNames( OtherAssetId, HAPI_ATTROWNER_PRIM, AttributeNames );
}

bool
FHoudiniGeoPartObject::HapiGetPrimitiveAttributeNames( TArray< FString > & AttributeNames ) const
{
    return HapiGetPrimitiveAttributeNames( AssetId, AttributeNames );
}

bool
FHoudiniGeoPartObject::HapiGetDetailAttributeNames( HAPI_NodeId OtherAssetId, TArray< FString > & AttributeNames ) const
{
    return HapiGetAttributeNames( OtherAssetId, HAPI_ATTROWNER_DETAIL, AttributeNames );
}

bool
FHoudiniGeoPartObject::HapiGetDetailAttributeNames( TArray< FString > & AttributeNames ) const
{
    return HapiGetDetailAttributeNames( AssetId, AttributeNames );
}


bool
FHoudiniGeoPartObject::HapiGetVertices( HAPI_NodeId OtherAssetId, TArray< int32 > & Vertices ) const
{
    Vertices.Empty();

    int32 VertexCount = HapiPartGetVertexCount( OtherAssetId );
    if ( !VertexCount )
        return false;

    Vertices.SetNumUninitialized( VertexCount );

    if ( FHoudiniApi::GetVertexList(
        FHoudiniEngine::Get().GetSession(), GeoId,
        PartId, &Vertices[ 0 ], 0, VertexCount ) != HAPI_RESULT_SUCCESS )
    {
        return false;
    }

    return true;
}

bool
FHoudiniGeoPartObject::HapiGetVertices( TArray< int32 > & Vertices ) const
{
    return HapiGetVertices( AssetId, Vertices );
}
