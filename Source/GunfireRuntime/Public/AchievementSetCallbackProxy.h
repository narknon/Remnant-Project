#pragma once
#include "CoreMinimal.h"
#include "AchievementUpdateCallbackProxy.h"
#include "AchievementId.h"
#include "AchievementSetCallbackProxy.generated.h"

class UAchievementSetCallbackProxy;
class UObject;
class APlayerController;

UCLASS(Blueprintable)
class UAchievementSetCallbackProxy : public UAchievementUpdateCallbackProxy {
    GENERATED_BODY()
public:
    UAchievementSetCallbackProxy();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAchievementSetCallbackProxy* SetAchievementProgress(UObject* WorldContextObject, APlayerController* PlayerController, FAchievementId AchievementName, int32 Progress);
    
};

