#include "AssetCache.h"

class UAssetCache;

void UAssetCache::PreloadAssets() {
}

bool UAssetCache::IsAssetCachedPreloaded() {
    return false;
}

UAssetCache* UAssetCache::GetInstance() {
    return NULL;
}

UAssetCache::UAssetCache() {
    this->PreloadMethod = EAssetCachePreloadMethod::OnGameInstanceInit;
    this->PackageLoadedCount = 0;
    this->PackageFailedCount = 0;
    this->IsPreloaded = false;
}

