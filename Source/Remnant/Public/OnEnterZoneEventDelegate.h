#pragma once
#include "CoreMinimal.h"
#include "OnEnterZoneEventDelegate.generated.h"

class AZoneActor;
class APawn;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnEnterZoneEvent, AZoneActor*, Zone, APawn*, PreviousPawn);

