#pragma once
#include "CoreMinimal.h"
#include "LevelInstanceStateDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FLevelInstanceStateDelegate, int32, LevelID);

