#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EMiniMapLevelRegionType.h"
#include "UObject/NoExportTypes.h"
#include "MiniMapLevelRegion.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AMiniMapLevelRegion : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMiniMapLevelRegionType RegionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MiniMapLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector RegionSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector RegionBuffer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PlaneBuffer;
    
public:
    AMiniMapLevelRegion();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInRegion(AActor* RefActor, int32 CurrentLevel, float AdditionalZ) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetRegionLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AreConcurrentMiniMapLevels(int32 LevelA, int32 LevelB, bool bCheckBelow, bool bCheckAbove);
    
};

