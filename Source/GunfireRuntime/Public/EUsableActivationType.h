#pragma once
#include "CoreMinimal.h"
#include "EUsableActivationType.generated.h"

UENUM(BlueprintType)
enum class EUsableActivationType : uint8 {
    Press,
    PressAndNoHold,
    Hold,
};

