#pragma once
#include "CoreMinimal.h"
#include "AchievementWriteCallbackProxy.h"
#include "AchievementUpdateCallbackProxy.generated.h"

UCLASS(Abstract, Blueprintable)
class UAchievementUpdateCallbackProxy : public UAchievementWriteCallbackProxy {
    GENERATED_BODY()
public:
    UAchievementUpdateCallbackProxy();
};

