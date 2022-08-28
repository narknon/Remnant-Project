#pragma once
#include "CoreMinimal.h"
#include "HitReactionType.generated.h"

UENUM(BlueprintType)
enum class HitReactionType : uint8 {
    Flinch,
    Impact,
    HitLocationDestroyed = 0x5,
    KnockBack,
    Death,
    DeathKnockBack,
    None,
};

