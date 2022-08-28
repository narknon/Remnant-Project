#pragma once
#include "CoreMinimal.h"
#include "AchievementId.h"
#include "AchievementUpdateCallbackProxy.h"
#include "AchievementIncrementCallbackProxy.generated.h"

class UAchievementIncrementCallbackProxy;
class UObject;
class APlayerController;

UCLASS(Blueprintable)
class UAchievementIncrementCallbackProxy : public UAchievementUpdateCallbackProxy {
    GENERATED_BODY()
public:
    UAchievementIncrementCallbackProxy();
    UFUNCTION(BlueprintCallable)
    static UAchievementIncrementCallbackProxy* IncrementAchievementProgress(UObject* WorldContextObject, APlayerController* PlayerController, FAchievementId AchievementName, int32 Progress);
    
};

