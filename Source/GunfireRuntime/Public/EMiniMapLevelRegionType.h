#pragma once
#include "CoreMinimal.h"
#include "EMiniMapLevelRegionType.generated.h"

UENUM(BlueprintType)
enum class EMiniMapLevelRegionType : uint8 {
    Volume,
    Plane,
};

