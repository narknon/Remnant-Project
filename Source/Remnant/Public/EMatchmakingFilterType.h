#pragma once
#include "CoreMinimal.h"
#include "EMatchmakingFilterType.generated.h"

UENUM(BlueprintType)
enum class EMatchmakingFilterType : uint8 {
    CampaignDifficulty,
    PowerLevel,
    CharacterType,
};

