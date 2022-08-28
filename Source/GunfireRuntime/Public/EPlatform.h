#pragma once
#include "CoreMinimal.h"
#include "EPlatform.generated.h"

UENUM(BlueprintType)
enum class EPlatform : uint8 {
    Unknown,
    PC,
    XboxOne,
    XboxOneS,
    XboxOneX,
    PS4,
    PS4Pro,
    PS5,
    XboxSeriesS,
    XboxSeriesX,
};

