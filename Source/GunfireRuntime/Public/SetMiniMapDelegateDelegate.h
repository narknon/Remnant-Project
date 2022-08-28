#pragma once
#include "CoreMinimal.h"
#include "SetMiniMapDelegateDelegate.generated.h"

class AMiniMapDisplayActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSetMiniMapDelegate, AMiniMapDisplayActor*, MiniMap);

