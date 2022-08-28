#pragma once
#include "CoreMinimal.h"
#include "EAchievementUpdateType.generated.h"

UENUM(BlueprintType)
enum class EAchievementUpdateType : uint8 {
    Increment,
    Set,
};

