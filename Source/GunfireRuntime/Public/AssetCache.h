#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PreloadedCompleteDelegate.h"
#include "EAssetCachePreloadMethod.h"
#include "AssetCache.generated.h"

class UAssetCache;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UAssetCache : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAssetCachePreloadMethod PreloadMethod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftObjectPtr<UObject>> Assets;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPreloadedComplete OnPreloadComplete;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UObject*> LoadedAssets;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 PackageLoadedCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 PackageFailedCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool IsPreloaded;
    
public:
    UAssetCache();
    UFUNCTION(BlueprintCallable)
    static void PreloadAssets();
    
    UFUNCTION(BlueprintCallable)
    bool IsAssetCachedPreloaded();
    
    UFUNCTION(BlueprintCallable)
    static UAssetCache* GetInstance();
    
};

