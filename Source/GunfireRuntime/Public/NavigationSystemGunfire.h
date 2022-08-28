#pragma once
#include "CoreMinimal.h"
#include "NavigationSystem.h"
#include "NavigationSystemGunfire.generated.h"

UCLASS(Blueprintable, NonTransient)
class GUNFIRERUNTIME_API UNavigationSystemGunfire : public UNavigationSystemV1 {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(Config, EditAnywhere)
    double OctreeUpdateMaxMSPerFrame;
    
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShouldWarnIfSingleElementsIsExpensive;
    
    UPROPERTY(Config, EditAnywhere)
    double WarnIfSingleElementsExceedsMS;
    
public:
    UNavigationSystemGunfire();
};

