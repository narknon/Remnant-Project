#pragma once
#include "CoreMinimal.h"
#include "AchievementId.h"
#include "AchievementUpdateCallbackProxy.h"
#include "AchievementSetCallbackProxy.generated.h"

class APlayerController;
class UAchievementSetCallbackProxy;
class UObject;

UCLASS(Blueprintable)
class UAchievementSetCallbackProxy : public UAchievementUpdateCallbackProxy {
    GENERATED_BODY()
public:
    UAchievementSetCallbackProxy();
    UFUNCTION(BlueprintCallable)
    static UAchievementSetCallbackProxy* SetAchievementProgress(UObject* WorldContextObject, APlayerController* PlayerController, FAchievementId AchievementName, int32 Progress);
    
};

