#pragma once
#include "CoreMinimal.h"
#include "ELevelTransition.generated.h"

UENUM(BlueprintType)
enum class ELevelTransition : uint8 {
    Load,
    Unload,
    Show,
    Hide,
    Remove,
};

