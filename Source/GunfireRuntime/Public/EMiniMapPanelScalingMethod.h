#pragma once
#include "CoreMinimal.h"
#include "EMiniMapPanelScalingMethod.generated.h"

UENUM(BlueprintType)
enum class EMiniMapPanelScalingMethod : uint8 {
    NonUniform,
    Maxima,
    Minima,
};

