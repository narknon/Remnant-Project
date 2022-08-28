#pragma once
#include "CoreMinimal.h"
#include "EPresenceJoinResult.h"
#include "PresenceJoinResultDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FPresenceJoinResult, EPresenceJoinResult, Result);

