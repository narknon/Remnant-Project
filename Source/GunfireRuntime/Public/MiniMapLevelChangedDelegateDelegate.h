#pragma once
#include "CoreMinimal.h"
#include "MiniMapLevelChangedDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FMiniMapLevelChangedDelegate, int32, ID, int32, NewLevel);

