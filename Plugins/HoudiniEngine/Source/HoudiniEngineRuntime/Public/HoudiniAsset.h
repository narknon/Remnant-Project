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
#include "UObject/Object.h"
#include "HAPI.h"
#include "HoudiniAsset.generated.h"


class UThumbnailInfo;
class UAssetImportData;
class UHoudiniAssetComponent;


UCLASS( EditInlineNew, config = Engine )
class HOUDINIENGINERUNTIME_API UHoudiniAsset : public UObject
{
    GENERATED_UCLASS_BODY()

    /** UObject methods. **/
    public:

        virtual void FinishDestroy() override;
        virtual void Serialize( FArchive & Ar ) override;
        virtual void GetAssetRegistryTags( TArray< FAssetRegistryTag > & OutTags ) const override;

    public:

        /** Initialize this asset from given buffer / file. **/
        void CreateAsset( const uint8 * BufferStart, const uint8 * BufferEnd, const FString & InFileName );

        /** Return buffer containing the raw Houdini OTL data. **/
        const uint8* GetAssetBytes() const;

        /** Return path of the corresponding OTL/HDA file. **/
        const FString& GetAssetFileName() const;

        /** Return the size in bytes of raw Houdini OTL data. **/
        uint32 GetAssetBytesCount() const;

        /** Returns true if this asset contains Houdini logo. **/
        bool IsPreviewHoudiniLogo() const;

        /** Return true if this asset is a limited commercial asset. **/
        bool IsAssetLimitedCommercial() const;

        /** Return true if this asset is a non commercial asset. **/
        bool IsAssetNonCommercial() const;

        /** Retrieves list of asset names contained within the HDA. **/
        bool GetAssetNames( HAPI_AssetLibraryId & AssetLibraryId, TArray< HAPI_StringHandle > & AssetNames );

    public:

        /** Filename of the OTL. **/
        UPROPERTY()
        FString AssetFileName;

        /** Information for thumbnail rendering. */
        UPROPERTY()
        UThumbnailInfo * ThumbnailInfo;

#if WITH_EDITORONLY_DATA

        /** Importing data and options used for this Houdini asset. */
        UPROPERTY( Category = ImportSettings, VisibleAnywhere, Instanced )
        UAssetImportData * AssetImportData;

#endif

    protected:

        /** Current version of the asset. **/
        static const uint32 PersistenceFormatVersion;

    protected:

        /** Buffer containing raw Houdini OTL data. **/
        uint8 * AssetBytes;

        /** Field containing the size of raw Houdini OTL data in bytes. **/
        uint32 AssetBytesCount;

        /** Version of the asset file format. **/
        uint32 FileFormatVersion;

        /** Flags used by this asset. **/
        union
        {
            struct
            {
                /** Flag which is set to true when preview geometry contains Houdini logo. **/
                uint32 bPreviewHoudiniLogo : 1;

                /** Flag which indicates if this is a limited commercial license asset. **/
                uint32 bAssetLimitedCommercial : 1;

                /** Flag which indicates if this is a non-commercial license asset. **/
                uint32 bAssetNonCommercial : 1;
            };

            uint32 HoudiniAssetFlagsPacked;
        };
};
