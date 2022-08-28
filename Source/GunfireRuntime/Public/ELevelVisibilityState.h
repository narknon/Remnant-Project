#pragma once
#include "CoreMinimal.h"
#include "ELevelVisibilityState.generated.h"

UENUM(BlueprintType)
enum class ELevelVisibilityState : uint8 {
    Hidden,
    Shown,
    Showing,
    Hiding,
};

