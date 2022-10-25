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

#include "HoudiniGeoPartObject.h"
#include "HoudiniCookHandler.h"
#include "ImageUtils.h"

class UTexture2D;
class UMaterialExpression;
class UMaterialInstanceConstant;

struct UGenericAttribute;

struct HOUDINIENGINERUNTIME_API FHoudiniEngineMaterialUtils
{
public:
    /** HAPI : Create Unreal materials and necessary textures. Reuse existing materials, if they are not updated. **/
    static void HapiCreateMaterials(
        HAPI_NodeId AssetId,
        FHoudiniCookParams& HoudiniCookParams, const HAPI_AssetInfo & AssetInfo,
        const TSet< HAPI_NodeId > & UniqueMaterialIds, const TSet< HAPI_NodeId > & UniqueInstancerMaterialIds,
        TMap< FString, UMaterialInterface * > & Materials, const bool& bForceRecookAll );

    /** HAPI : Retrieve a list of image planes. **/
    static bool HapiGetImagePlanes(
        HAPI_ParmId NodeParmId, const HAPI_MaterialInfo & MaterialInfo,
        TArray< FString > & ImagePlanes );

    /** HAPI : Extract image data. **/
    static bool HapiExtractImage(
        HAPI_ParmId NodeParmId, const HAPI_MaterialInfo & MaterialInfo,
        TArray< char > & ImageBuffer, const char * PlaneType, HAPI_ImageDataFormat ImageDataFormat,
        HAPI_ImagePacking ImagePacking, bool bRenderToImage );
        
    /** HAPI : Get unique material SHOP name. **/
    static bool GetUniqueMaterialShopName( HAPI_NodeId AssetId, HAPI_NodeId MaterialId, FString & Name );

    /** Helper function to locate first Material expression of given class within given expression subgraph. **/
    static UMaterialExpression * MaterialLocateExpression( UMaterialExpression * Expression, UClass * ExpressionClass );

    /** Creates Material Instance from attributes **/
    static bool CreateMaterialInstances( 
        const FHoudiniGeoPartObject& HoudiniGeoPartObject, FHoudiniCookParams& CookParams,
        UMaterialInstance *& CreatedMaterialInstance, UMaterialInterface*& OriginalMaterialInterface,
        std::string AttributeName, int32 MaterialIndex = 0 );

    /** Updates the material instance parameter corresponding to the generic parameter found in the asset **/
    static bool UpdateMaterialInstanceParameter( UGenericAttribute MaterialParam, UMaterialInstanceConstant* MaterialInstance, FHoudiniCookParams& CookParams );

    /** Try to find a texture generated by HoudiniEngine that matches the texture string **/
    static UTexture* FindGeneratedTexture( const FString& TextureString, FHoudiniCookParams& CookParams );

#if WITH_EDITOR

    /** Create a texture from given information. **/
    static UTexture2D * CreateUnrealTexture(
        UTexture2D * ExistingTexture, const HAPI_ImageInfo & ImageInfo,
        UPackage * Package, const FString & TextureName,
        const TArray< char > & ImageBuffer, const FString & TextureType,
        const FCreateTexture2DParameters & TextureParameters, TextureGroup LODGroup, const FString& NodePath );

    /** Create various material components. **/
    static bool CreateMaterialComponentDiffuse(
        FHoudiniCookParams& HoudiniCookParams, const HAPI_NodeId& AssetId,
        UMaterial * Material, const HAPI_MaterialInfo & MaterialInfo,
        const HAPI_NodeInfo & NodeInfo, int32 & MaterialNodeY );

    static bool CreateMaterialComponentNormal(
        FHoudiniCookParams& HoudiniCookParams, const HAPI_NodeId& AssetId,
        UMaterial * Material, const HAPI_MaterialInfo & MaterialInfo,
        const HAPI_NodeInfo & NodeInfo, int32 & MaterialNodeY );

    static bool CreateMaterialComponentSpecular(
        FHoudiniCookParams& HoudiniCookParams, const HAPI_NodeId& AssetId,
        UMaterial * Material, const HAPI_MaterialInfo & MaterialInfo,
        const HAPI_NodeInfo & NodeInfo, int32 & MaterialNodeY );

    static bool CreateMaterialComponentRoughness(
        FHoudiniCookParams& HoudiniCookParams, const HAPI_NodeId& AssetId,
        UMaterial * Material, const HAPI_MaterialInfo & MaterialInfo,
        const HAPI_NodeInfo & NodeInfo, int32 & MaterialNodeY );

    static bool CreateMaterialComponentMetallic(
        FHoudiniCookParams& HoudiniCookParams, const HAPI_NodeId& AssetId,
        UMaterial * Material, const HAPI_MaterialInfo & MaterialInfo,
        const HAPI_NodeInfo & NodeInfo, int32 & MaterialNodeY );

    static bool CreateMaterialComponentEmissive(
        FHoudiniCookParams& HoudiniCookParams, const HAPI_NodeId& AssetId,
        UMaterial * Material, const HAPI_MaterialInfo & MaterialInfo,
        const HAPI_NodeInfo & NodeInfo, int32 & MaterialNodeY );

    static bool CreateMaterialComponentOpacity(
        FHoudiniCookParams& HoudiniCookParams, const HAPI_NodeId& AssetId,
        UMaterial * Material, const HAPI_MaterialInfo & MaterialInfo,
        const HAPI_NodeInfo & NodeInfo, int32 & MaterialNodeY );

    static bool CreateMaterialComponentOpacityMask(
        FHoudiniCookParams& HoudiniCookParams, const HAPI_NodeId& AssetId,
        UMaterial * Material, const HAPI_MaterialInfo & MaterialInfo,
        const HAPI_NodeInfo & NodeInfo, int32 & MaterialNodeY );

#endif

    /** Material node construction offsets. **/
    static const int32 MaterialExpressionNodeX;
    static const int32 MaterialExpressionNodeY;
    static const int32 MaterialExpressionNodeStepX;
    static const int32 MaterialExpressionNodeStepY;

};