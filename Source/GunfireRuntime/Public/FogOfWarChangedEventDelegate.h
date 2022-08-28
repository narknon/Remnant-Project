#pragma once
#include "CoreMinimal.h"
#include "FogOfWarChangedEventDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFogOfWarChangedEvent, int32, X, int32, Y);

