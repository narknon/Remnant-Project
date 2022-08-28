#pragma once
#include "CoreMinimal.h"
#include "EVarType.generated.h"

UENUM(BlueprintType)
enum class EVarType : uint8 {
    Bool,
    Number,
    Name,
    Object,
};

