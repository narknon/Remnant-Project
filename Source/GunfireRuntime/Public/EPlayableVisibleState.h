#pragma once
#include "CoreMinimal.h"
#include "EPlayableVisibleState.generated.h"

UENUM(BlueprintType)
enum class EPlayableVisibleState : uint8 {
    None,
    Show,
    Hide,
};

