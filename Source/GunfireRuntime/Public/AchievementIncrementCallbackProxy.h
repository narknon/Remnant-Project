#pragma once
#include "CoreMinimal.h"
#include "AchievementUpdateCallbackProxy.h"
#include "AchievementId.h"
#include "AchievementIncrementCallbackProxy.generated.h"

class UAchievementIncrementCallbackProxy;
class UObject;
class APlayerController;

UCLASS(Blueprintable)
class UAchievementIncrementCallbackProxy : public UAchievementUpdateCallbackProxy {
    GENERATED_BODY()
public:
    UAchievementIncrementCallbackProxy();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAchievementIncrementCallbackProxy* IncrementAchievementProgress(UObject* WorldContextObject, APlayerController* PlayerController, FAchievementId AchievementName, int32 Progress);
    
};

