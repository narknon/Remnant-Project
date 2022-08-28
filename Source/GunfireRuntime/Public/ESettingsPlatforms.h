#pragma once
#include "CoreMinimal.h"
#include "ESettingsPlatforms.generated.h"

UENUM(BlueprintType)
enum class ESettingsPlatforms : uint8 {
    PC,
    XboxOne,
    XboxOneX,
    PS4,
    PS4Pro,
    PCExcludingEpic,
    XboxOneSeries,
    PS5,
};

