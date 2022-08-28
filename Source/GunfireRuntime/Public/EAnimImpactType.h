#pragma once
#include "CoreMinimal.h"
#include "EAnimImpactType.generated.h"

UENUM(BlueprintType)
enum class EAnimImpactType : uint8 {
    Foot,
    FootSprint,
    Hand,
    HandSprint,
    Land,
    Body,
    Slam,
};

