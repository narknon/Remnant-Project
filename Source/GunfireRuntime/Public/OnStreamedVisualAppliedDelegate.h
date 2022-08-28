#pragma once
#include "CoreMinimal.h"
#include "OnStreamedVisualAppliedDelegate.generated.h"

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnStreamedVisualApplied, FName, SlotID, FName, VisualID);

