#pragma once
#include "CoreMinimal.h"
#include "ZonePlayerDelegateDelegate.generated.h"

class APlayerController;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FZonePlayerDelegate, APlayerController*, Controller);

