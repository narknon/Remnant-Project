#pragma once
#include "CoreMinimal.h"
#include "OnMiniMapSelectDelegateDelegate.generated.h"

class AMiniMapActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMiniMapSelectDelegate, AMiniMapActor*, MiniMapActor);

