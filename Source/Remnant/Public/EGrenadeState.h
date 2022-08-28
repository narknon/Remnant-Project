#pragma once
#include "CoreMinimal.h"
#include "EGrenadeState.generated.h"

UENUM(BlueprintType)
enum class EGrenadeState : uint8 {
    Inactive,
    Equipping,
    Equipped,
    Throwing,
    Thrown,
};

