#pragma once
#include "CoreMinimal.h"
#include "ESpawnFlags.generated.h"

UENUM(BlueprintType)
enum class ESpawnFlags : uint8 {
    NavMesh,
    NavAccessible,
    OutOfSight,
    InView,
    InFieldOfView,
};

