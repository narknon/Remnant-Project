#pragma once
#include "CoreMinimal.h"
#include "OnShowMatchmakingEventMessageDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnShowMatchmakingEventMessage, const FText&, Heading, const FText&, Message, bool, AlwaysOnTop);

