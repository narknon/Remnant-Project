#pragma once
#include "CoreMinimal.h"
#include "ECombatSize.generated.h"

UENUM(BlueprintType)
enum class ECombatSize : uint8 {
    Normal = 0x1,
    Big = 0x3,
};

