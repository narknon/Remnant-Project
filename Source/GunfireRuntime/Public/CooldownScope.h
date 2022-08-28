#pragma once
#include "CoreMinimal.h"
#include "CooldownScope.generated.h"

UENUM(BlueprintType)
enum class CooldownScope : uint8 {
    Local,
    Target,
};

