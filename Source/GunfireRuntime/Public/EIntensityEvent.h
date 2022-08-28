#pragma once
#include "CoreMinimal.h"
#include "EIntensityEvent.generated.h"

UENUM(BlueprintType)
enum class EIntensityEvent : uint8 {
    Hit,
    Wounded,
    Death,
    EnemyHit,
    EnemyDeath,
};

