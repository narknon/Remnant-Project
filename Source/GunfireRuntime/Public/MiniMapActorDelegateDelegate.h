#pragma once
#include "CoreMinimal.h"
#include "MiniMapActorDelegateDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FMiniMapActorDelegate, int32, ID);

