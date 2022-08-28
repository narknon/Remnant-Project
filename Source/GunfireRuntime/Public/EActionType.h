#pragma once
#include "CoreMinimal.h"
#include "EActionType.generated.h"

UENUM(BlueprintType)
enum EActionType {
    Dialog,
    Action,
    Flow,
    Trigger,
};

