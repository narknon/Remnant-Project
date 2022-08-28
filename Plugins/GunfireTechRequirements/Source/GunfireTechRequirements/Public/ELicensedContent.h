#pragma once
#include "CoreMinimal.h"
#include "ELicensedContent.generated.h"

UENUM(BlueprintType)
enum class ELicensedContent : uint8 {
    PreOrderGladiator,
    PreOrderSurvivor,
    PreOrderNightstalker,
    PreOrderDoomsayer,
    PreOrderTwitch,
    PreOrderSteam,
    GreenXCap,
    GoldCap,
    DLC1,
    DLC2,
    None,
};

