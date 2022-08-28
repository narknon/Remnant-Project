#pragma once
#include "CoreMinimal.h"
#include "LevelChangedEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLevelChangedEvent, int32, NewLevel, int32, PreviousLevel);

