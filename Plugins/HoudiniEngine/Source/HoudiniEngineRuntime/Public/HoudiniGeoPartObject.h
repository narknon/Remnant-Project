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

#include "HAPI_Common.h"
#include "CoreMinimal.h"
#include <string>


class FArchive;
struct FTransform;
struct HAPI_GeoInfo;
struct HAPI_PartInfo;
struct HAPI_ObjectInfo;
class FHoudiniEngineString;

struct HOUDINIENGINERUNTIME_API FHoudiniGeoPartObject
{
    public:

        /** Constructors. **/
        FHoudiniGeoPartObject();
        FHoudiniGeoPartObject( HAPI_NodeId InAssetId, HAPI_NodeId InObjectId, HAPI_NodeId InGeoId, HAPI_PartId InPartId );

        FHoudiniGeoPartObject(
            const FTransform & InTransform, HAPI_NodeId InAssetId, const HAPI_ObjectInfo & ObjectInfo,
            const HAPI_GeoInfo & GeoInfo, const HAPI_PartInfo & PartInfo );

        FHoudiniGeoPartObject(
            const FTransform & InTransform, const FString & InObjectName, const FString & InPartName,
            HAPI_NodeId InAssetId, HAPI_NodeId InObjectId, HAPI_NodeId InGeoId, HAPI_PartId InPartId );

        FHoudiniGeoPartObject( const FHoudiniGeoPartObject & GeoPartObject, bool bCopyLoaded = false );

    public:

        /** Return hash value for this object, used when using this object as a key inside hashing containers. **/
        uint32 GetTypeHash() const;

        /** Comparison operator, used by hashing containers. **/
        bool operator==( const FHoudiniGeoPartObject & HoudiniGeoPartObject ) const;

        /** Compare based on object and part name. **/
        bool CompareNames( const FHoudiniGeoPartObject & HoudiniGeoPartObject ) const;

        /** Serialization. **/
        void Serialize( FArchive & Ar );

        /** Return true if this geo part object corresponds to a valid HAPI object. **/
        bool IsValid() const;

        /** Return true if this geo part object corresponds to an instancer. **/
        bool IsInstancer() const;

        /** Return true if this geo part object is visible. **/
        bool IsVisible() const;

        /** Return true if this geo part object is a curve. **/
        bool IsCurve() const;

        /** Return true if this geo part object is a box. **/
        bool IsBox() const;

        /** Return true if this geo part object is a sphere. **/
        bool IsSphere() const;

        /** Return true if this geo part object is a volume. **/
        bool IsVolume() const;

        /** Return true if this geo part object is editable. **/
        bool IsEditable() const;

        /** Return true if this geo part is used for collision. **/
        bool IsCollidable() const;

        /** Return true if this geo part is used for collision and is renderable. **/
        bool IsRenderCollidable() const;

        /** Return true if this geo part object corresponds to a packed primitive instancer **/
        bool IsPackedPrimitiveInstancer() const;

        /** Return true if this geo part object corresponds to an attribute instancer **/
        bool IsAttributeInstancer() const;

        /** Return true if this geo part object corresponds to an attribute override instancer **/
        bool IsAttributeOverrideInstancer() const;

        /** Return true if corresponding geometry has changed. **/
        bool HasGeoChanged() const;

        /** Return true if this object has a custom name. **/
        bool HasCustomName() const;

        /** Set custom name. **/
        void SetCustomName( const FString & CustomName );

        /** Updates the HGPO's custom name, returns true if a custom name was found **/
        bool UpdateCustomName();

    public:

        /** Return object id. **/
        HAPI_NodeId GetObjectId() const;

        /** Return geo id. **/
        HAPI_NodeId GetGeoId() const;

        /** Return part id. **/
        HAPI_PartId GetPartId() const;

        /** Return the unique path to this part's node */
        const FString& GetNodePath() const;

    /** HAPI: Other helpers. **/
    public:

        /** HAPI: Return true if given attribute exists on a given owner. **/
        bool HapiCheckAttributeExistance(
            HAPI_NodeId OtherAssetId, const FString & AttributeName,
            HAPI_AttributeOwner AttributeOwner ) const;
        bool HapiCheckAttributeExistance(
            const FString & AttributeName, HAPI_AttributeOwner AttributeOwner ) const;
        bool HapiCheckAttributeExistance(
            HAPI_NodeId OtherAssetId, const std::string & AttributeName,
            HAPI_AttributeOwner AttributeOwner ) const;
        bool HapiCheckAttributeExistance(
            const std::string & AttributeName, HAPI_AttributeOwner AttributeOwner ) const;
        bool HapiCheckAttributeExistance(
            HAPI_NodeId OtherAssetId, const char * AttributeName,
            HAPI_AttributeOwner AttributeOwner ) const;
        bool HapiCheckAttributeExistance(
            const char * AttributeName, HAPI_AttributeOwner AttributeOwner ) const;

        /** HAPI: Get instance transformations. **/
        bool HapiGetInstanceTransforms( HAPI_NodeId OtherAssetId, TArray< FTransform > & AllTransforms ) const;
        bool HapiGetInstanceTransforms( TArray< FTransform > & AllTransforms ) const;

        /** HAPI: Get Attribute info on a specified owner. **/
        bool HapiGetAttributeInfo(
            HAPI_NodeId OtherAssetId, const char * AttributeName,
            HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & AttributeInfo ) const;
        bool HapiGetAttributeInfo(
            const char * AttributeName, HAPI_AttributeOwner AttributeOwner,
            HAPI_AttributeInfo & AttributeInfo ) const;
        bool HapiGetAttributeInfo(
            HAPI_NodeId OtherAssetId, const std::string & AttributeName,
            HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & AttributeInfo ) const;
        bool HapiGetAttributeInfo(
            const std::string & AttributeName,
            HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & AttributeInfo ) const;
        bool HapiGetAttributeInfo(
            HAPI_NodeId OtherAssetId, const FString & AttributeName,
            HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & AttributeInfo ) const;
        bool HapiGetAttributeInfo(
            const FString & AttributeName,
            HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & AttributeInfo ) const;

        /** HAPI: Get Attribute info on any owner. **/
        bool HapiGetAttributeInfo(
            HAPI_NodeId OtherAssetId, const char * AttributeName,
            HAPI_AttributeInfo & AttributeInfo )  const;
        bool HapiGetAttributeInfo(
            const char * AttributeName, HAPI_AttributeInfo & AttributeInfo ) const;
        bool HapiGetAttributeInfo(
            HAPI_NodeId OtherAssetId, const std::string & AttributeName,
            HAPI_AttributeInfo & AttributeInfo ) const;
        bool HapiGetAttributeInfo(
            const std::string & AttributeName, HAPI_AttributeInfo & AttributeInfo ) const;
        bool HapiGetAttributeInfo(
            HAPI_NodeId OtherAssetId, const FString & AttributeName,
            HAPI_AttributeInfo & AttributeInfo ) const;
        bool HapiGetAttributeInfo(
            const FString & AttributeName, HAPI_AttributeInfo & AttributeInfo ) const;

        /** HAPI: Get attribute float data on a specified owner. **/
        bool HapiGetAttributeDataAsFloat(
            HAPI_NodeId OtherAssetId, const char * AttributeName,
            HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< float > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsFloat(
            const char * AttributeName, HAPI_AttributeOwner AttributeOwner,
            HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< float > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsFloat(
            HAPI_NodeId OtherAssetId, const std::string & AttributeName,
            HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< float > & AttributeData,
            int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsFloat(
            const std::string & AttributeName, HAPI_AttributeOwner AttributeOwner,
            HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< float > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsFloat(
            HAPI_NodeId OtherAssetId, const FString & AttributeName,
            HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< float > & AttributeData,
            int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsFloat(
            const FString & AttributeName, HAPI_AttributeOwner AttributeOwner,
            HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< float > & AttributeData, int32 TupleSize = 0 ) const;

        /** HAPI: Get attribute float data on any owner. **/
        bool HapiGetAttributeDataAsFloat(
            HAPI_NodeId OtherAssetId, const char * AttributeName,
            HAPI_AttributeInfo & ResultAttributeInfo, TArray< float > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsFloat(
            const char * AttributeName, HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< float > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsFloat(
            HAPI_NodeId OtherAssetId, const std::string & AttributeName,
            HAPI_AttributeInfo & ResultAttributeInfo, TArray< float > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsFloat(
            const std::string & AttributeName, HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< float > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsFloat(
            HAPI_NodeId OtherAssetId, const FString & AttributeName,
            HAPI_AttributeInfo & ResultAttributeInfo, TArray< float > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsFloat(
            const FString & AttributeName, HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< float > & AttributeData, int32 TupleSize = 0 ) const;

        /** HAPI: Get attribute int data on a specified owner. **/
        bool HapiGetAttributeDataAsInt(
            HAPI_NodeId OtherAssetId, const char * AttributeName,
            HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< int32 > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsInt(
            const char * AttributeName, HAPI_AttributeOwner AttributeOwner,
            HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< int32 > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsInt(
            HAPI_NodeId OtherAssetId, const std::string & AttributeName,
            HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< int32 > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsInt(
            const std::string & AttributeName, HAPI_AttributeOwner AttributeOwner,
            HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< int32 > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsInt(
            HAPI_NodeId OtherAssetId, const FString & AttributeName,
            HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< int32 > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsInt(
            const FString & AttributeName, HAPI_AttributeOwner AttributeOwner,
            HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< int32 > & AttributeData, int32 TupleSize = 0 ) const;

        /** HAPI: Get attribute int data on any owner. **/
        bool HapiGetAttributeDataAsInt(
            HAPI_NodeId OtherAssetId, const char * AttributeName,
            HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< int32 > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsInt(
            const char* AttributeName, HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< int32 > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsInt(
            HAPI_NodeId OtherAssetId, const std::string & AttributeName,
            HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< int32 > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsInt(
            const std::string & AttributeName, HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< int32 > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsInt(
            HAPI_NodeId OtherAssetId, const FString & AttributeName,
            HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< int32 > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsInt(
            const FString & AttributeName, HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< int32 > & AttributeData, int32 TupleSize = 0 ) const;

        /** HAPI: Get attribute string data on a specified owner. **/
        bool HapiGetAttributeDataAsString(
            HAPI_NodeId OtherAssetId, const char * AttributeName,
            HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< FString > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsString(
            const char * AttributeName, HAPI_AttributeOwner AttributeOwner,
            HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< FString > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsString(
            HAPI_NodeId OtherAssetId, const std::string & AttributeName,
            HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< FString > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsString(
            const std::string & AttributeName, HAPI_AttributeOwner AttributeOwner,
            HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< FString > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsString(
            HAPI_NodeId OtherAssetId, const FString & AttributeName,
            HAPI_AttributeOwner AttributeOwner, HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< FString > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsString(
            const FString & AttributeName, HAPI_AttributeOwner AttributeOwner,
            HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< FString > & AttributeData, int32 TupleSize = 0 ) const;

        /** HAPI: Get attribute string data on any owner. **/
        bool HapiGetAttributeDataAsString(
            HAPI_NodeId OtherAssetId, const char * AttributeName,
            HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< FString > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsString(
            const char * AttributeName, HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< FString > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsString(
            HAPI_NodeId OtherAssetId, const std::string & AttributeName,
            HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< FString > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsString(
            const std::string & AttributeName, HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< FString > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsString(
            HAPI_NodeId OtherAssetId, const FString & AttributeName,
            HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< FString > & AttributeData, int32 TupleSize = 0 ) const;
        bool HapiGetAttributeDataAsString(
            const FString & AttributeName, HAPI_AttributeInfo & ResultAttributeInfo,
            TArray< FString > & AttributeData, int32 TupleSize = 0 ) const;

        /** HAPI: Get names of all attributes on all owners. **/
        bool HapiGetAllAttributeNames( HAPI_NodeId OtherAssetId, TArray< FString > & AttributeNames ) const;
        bool HapiGetAllAttributeNames( TArray< FString > & AttributeNames ) const;

        /** HAPI: Get names of all attributes on a given owner. **/
        bool HapiGetAttributeNames(
            HAPI_NodeId OtherAssetId, HAPI_AttributeOwner AttributeOwner,
            TArray< FString > & AttributeNames ) const;
        bool HapiGetAttributeNames( HAPI_AttributeOwner AttributeOwner, TArray< FString > & AttributeNames ) const;

        /** HAPI: Get attribute names on point, vertex, detail or primitive. **/
        bool HapiGetPointAttributeNames( HAPI_NodeId OtherAssetId, TArray< FString > & AttributeNames) const;
        bool HapiGetPointAttributeNames( TArray< FString > & AttributeNames ) const;
        bool HapiGetVertexAttributeNames( HAPI_NodeId OtherAssetId, TArray< FString > & AttributeNames ) const;
        bool HapiGetVertexAttributeNames( TArray< FString > & AttributeNames ) const;
        bool HapiGetPrimitiveAttributeNames( HAPI_NodeId OtherAssetId, TArray< FString > & AttributeNames ) const;
        bool HapiGetPrimitiveAttributeNames( TArray< FString > & AttributeNames ) const;
        bool HapiGetDetailAttributeNames( HAPI_NodeId OtherAssetId, TArray< FString > & AttributeNames ) const;
        bool HapiGetDetailAttributeNames( TArray< FString > & AttributeNames ) const;

    /** HAPI: Object related getters. **/
    public:

        /** HAPI: Retrieve corresponding object info structure. **/
        bool HapiObjectGetInfo( HAPI_ObjectInfo & ObjectInfo ) const;
        bool HapiObjectGetInfo( HAPI_NodeId OtherAssetId, HAPI_ObjectInfo & ObjectInfo ) const;

        /** HAPI: If this is an instancer, return id of instanced object. Return -1 if no such object is found. **/
        HAPI_NodeId HapiObjectGetToInstanceId() const;
        HAPI_NodeId HapiObjectGetToInstanceId( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return object name. **/
        FHoudiniEngineString HapiObjectGetName() const;
        FHoudiniEngineString HapiObjectGetName( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return object instance path. **/
        FHoudiniEngineString HapiObjectGetInstancePath() const;
        FHoudiniEngineString HapiObjectGetInstancePath( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return true if object is visible. **/
        bool HapiObjectIsVisible() const;
        bool HapiObjectIsVisible( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return true if object is an instancer. **/
        bool HapiObjectIsInstancer() const;
        bool HapiObjectIsInstancer( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return true if object transform has changed. **/
        bool HapiObjectHasTransformChanged() const;
        bool HapiObjectHasTransformChanged( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return true if any of the underlying geos have changed. **/
        bool HapiObjectHaveGeosChanged() const;
        bool HapiObjectHaveGeosChanged( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Get number of geos. **/
        int32 HapiObjectGetGeoCount() const;
        int32 HapiObjectGetGeoCount( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Get associated node id. This corresponds to id of an obj node. **/
        HAPI_NodeId HapiObjectGetNodeId() const;
        HAPI_NodeId HapiObjectGetNodeId( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return unique material id associated with an instancer. **/
        bool HapiObjectGetUniqueInstancerMaterialId( HAPI_NodeId & MaterialId ) const;
        bool HapiObjectGetUniqueInstancerMaterialId( HAPI_NodeId OtherAssetId, HAPI_NodeId & MaterialId ) const;

    /** HAPI: Geo related getters. **/
    public:

        /** HAPI: Retrieve corresponding geo info structure. **/
        bool HapiGeoGetInfo( HAPI_GeoInfo & GeoInfo ) const;
        bool HapiGeoGetInfo( HAPI_NodeId OtherAssetId, HAPI_GeoInfo & GeoInfo ) const;

        /** HAPI: Return geo type. **/
        HAPI_GeoType HapiGeoGetType() const;
        HAPI_GeoType HapiGeoGetType( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return name of this geo. **/
        FHoudiniEngineString HapiGeoGetName() const;
        FHoudiniEngineString HapiGeoGetName( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return geo node id. This corresponds to id of a sop node. **/
        HAPI_NodeId HapiGeoGetNodeId() const;
        HAPI_NodeId HapiGeoGetNodeId( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return true if this geo is editable. **/
        bool HapiGeoIsEditable() const;
        bool HapiGeoIsEditable( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return true if this geo is templated. **/
        bool HapiGeoIsTemplated() const;
        bool HapiGeoIsTemplated( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return true if this is a display sop geo. **/
        bool HapiGeoIsDisplayGeo() const;
        bool HapiGeoIsDisplayGeo( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return true if geo has changed. **/
        bool HapiGeoHasChanged() const;
        bool HapiGeoHasChanged( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return true if material on this geo has changed. **/
        bool HapiGeoHasMaterialChanged() const;
        bool HapiGeoHasMaterialChanged( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return number of point groups. **/
        int32 HapiGeoGetPointGroupCount() const;
        int32 HapiGeoGetPointGroupCount( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return number of primitive groups. **/
        int32 HapiGeoGetPrimitiveGroupCount() const;
        int32 HapiGeoGetPrimitiveGroupCount( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return number of parts within this geo. **/
        int32 HapiGeoGetPartCount() const;
        int32 HapiGeoGetPartCount( HAPI_NodeId OtherAssetId ) const;

    /** HAPI: Part related getters. **/
    public:

        /** HAPI: Retrieve corresponding part info structure. **/
        bool HapiPartGetInfo( HAPI_PartInfo & PartInfo ) const;
        bool HapiPartGetInfo( HAPI_NodeId OtherAssetId, HAPI_PartInfo & PartInfo ) const;

        /** HAPI: Get name of this part. **/
        FHoudiniEngineString HapiPartGetName() const;
        FHoudiniEngineString HapiPartGetName( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return part type. **/
        HAPI_PartType HapiPartGetType() const;
        HAPI_PartType HapiPartGetType( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return face count. **/
        int32 HapiPartGetFaceCount() const;
        int32 HapiPartGetFaceCount( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return vertex count. **/
        int32 HapiPartGetVertexCount() const;
        int32 HapiPartGetVertexCount( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return point count. **/
        int32 HapiPartGetPointCount() const;
        int32 HapiPartGetPointCount( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return true if this part is used by an instancer. **/
        bool HapiPartIsInstanced() const;
        bool HapiPartIsInstanced( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Number of parts this instancer part is instancing. **/
        int32 HapiPartGetInstancedPartCount() const;
        int32 HapiPartGetInstancedPartCount( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Number of instances that this instancer part is instancing. **/
        int32 HapiPartGetInstanceCount() const;
        int32 HapiPartGetInstanceCount( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Get number of point attributes. **/
        int32 HapiPartGetPointAttributeCount() const;
        int32 HapiPartGetPointAttributeCount( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Get number of vertex attributes. **/
        int32 HapiPartGetVertexAttributeCount() const;
        int32 HapiPartGetVertexAttributeCount( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Get number of primitive attributes. **/
        int32 HapiPartGetPrimitiveAttributeCount() const;
        int32 HapiPartGetPrimitiveAttributeCount( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Get number of detail attributes. **/
        int32 HapiPartGetDetailAttributeCount() const;
        int32 HapiPartGetDetailAttributeCount( HAPI_NodeId OtherAssetId ) const;

        /** HAPI: Return unique material ids associated with this part. **/
        bool HapiPartGetUniqueMaterialIds( TSet< HAPI_NodeId > & MaterialIds ) const;
        bool HapiPartGetUniqueMaterialIds( HAPI_NodeId OtherAssetId, TSet< HAPI_NodeId > & MaterialIds ) const;

    public:

        /** Return list of vertices associated with this geo part object. **/
        bool HapiGetVertices( HAPI_NodeId OtherAssetId, TArray< int32 > & Vertices ) const;
        bool HapiGetVertices( TArray< int32 > & Vertices ) const;

    public:

        /** Return true if this geo part has parameters. **/
        bool HasParameters() const;
        bool HasParameters( HAPI_NodeId InAssetId ) const;

    public:

        /** Transform of this geo part object. **/
        FTransform TransformMatrix;

        /** Name of associated object. **/
        FString ObjectName;

        /** Name of associated part. **/
        FString PartName;

        /** Name of group which was used for splitting, empty if there's none. **/
        FString SplitName;

        /** Name of the instancer material, if available. **/
        FString InstancerMaterialName;

        /** Name of attribute material, if available. **/
        FString InstancerAttributeMaterialName;

        /** Id of corresponding HAPI Asset. **/
        HAPI_NodeId AssetId;

        /** Id of corresponding HAPI Object. **/
        HAPI_NodeId ObjectId;

        /** Id of corresponding HAPI Geo. **/
        HAPI_NodeId GeoId;

        /** Id of corresponding HAPI Part. **/
        HAPI_PartId PartId;

        /** Id of a split. In most cases this will be 0. **/
        int32 SplitId;

        /** Path to the corresponding node */
        mutable FString NodePath;

        /** Flags used by geo part object. **/
        union
        {
            struct
            {
                /* Is set to true when referenced object is visible. This is typically used by instancers. **/
                uint32 bIsVisible : 1;

                /** Is set to true when referenced object is an instancer. **/
                uint32 bIsInstancer : 1;

                /** Is set to true when referenced object is a curve. **/
                uint32 bIsCurve : 1;

                /** Is set to true when referenced object is editable. **/
                uint32 bIsEditable : 1;

                /** Is set to true when geometry has changed. **/
                uint32 bHasGeoChanged : 1;

                /** Is set to true when referenced object is collidable. **/
                uint32 bIsCollidable : 1;

                /** Is set to true when referenced object is collidable and is renderable. **/
                uint32 bIsRenderCollidable : 1;

                /** Is set to true when referenced object has just been loaded. **/
                uint32 bIsLoaded : 1;

                /** Unused flags. **/
                uint32 bPlaceHolderFlags : 3;

                /** Is set to true when referenced object has been loaded during transaction. **/
                uint32 bIsTransacting : 1;

                /** Is set to true when referenced object has a custom name. **/
                uint32 bHasCustomName : 1;

                /** Is set to true when referenced object is a box. **/
                uint32 bIsBox : 1;

                /** Is set to true when referenced object is a sphere. **/
                uint32 bIsSphere : 1;

                /** Is set to true when instancer material is available. **/
                uint32 bInstancerMaterialAvailable : 1;

                /** Is set to true when referenced object is a volume. **/
                uint32 bIsVolume : 1;

                /** Is set to true when instancer attribute material is available. **/
                uint32 bInstancerAttributeMaterialAvailable : 1;

                /** Is set when referenced object contains packed primitive instancing */
                uint32 bIsPackedPrimitiveInstancer : 1;

                /** Is set to true when referenced object is a UCX collision geo. **/
                uint32 bIsUCXCollisionGeo : 1;

                /** Is set to true when referenced object is a rendered UCX collision geo. **/
                uint32 bIsSimpleCollisionGeo : 1;

                /** Is set to true when new collision geo has been generated **/
                uint32 bHasCollisionBeenAdded : 1;

                /** Is set to true when new sockets have been added **/
                uint32 bHasSocketBeenAdded : 1;

                /** unused flag space is zero initialized */
                uint32 UnusedFlagsSpace : 14;
            };

            uint32 HoudiniGeoPartObjectFlagsPacked;
        };

        /** Temporary variable holding serialization version. **/
        uint32 HoudiniGeoPartObjectVersion;
};

/** Function used by hashing containers to create a unique hash for this type of object. **/
HOUDINIENGINERUNTIME_API uint32 GetTypeHash( const FHoudiniGeoPartObject & HoudiniGeoPartObject );

/** Serialization function. **/
HOUDINIENGINERUNTIME_API FArchive& operator<<( FArchive & Ar, FHoudiniGeoPartObject & HoudiniGeoPartObject );

/** Functor used to sort geo part objects. **/
struct HOUDINIENGINERUNTIME_API FHoudiniGeoPartObjectSortPredicate
{
    bool operator()( const FHoudiniGeoPartObject & A, const FHoudiniGeoPartObject & B ) const;
};
