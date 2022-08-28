#pragma once
#include "CoreMinimal.h"
#include "SpectateTargetChangedDelegateDelegate.generated.h"

class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FSpectateTargetChangedDelegate, AActor*, SpectateTarget);

