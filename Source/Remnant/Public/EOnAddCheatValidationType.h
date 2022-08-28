#pragma once
#include "CoreMinimal.h"
#include "EOnAddCheatValidationType.generated.h"

UENUM(BlueprintType)
enum class EOnAddCheatValidationType : uint8 {
    CheckByQuantity,
    CheckByTime,
};

