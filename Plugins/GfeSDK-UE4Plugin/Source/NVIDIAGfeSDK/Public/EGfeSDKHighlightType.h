#pragma once
#include "CoreMinimal.h"
#include "EGfeSDKHighlightType.generated.h"

UENUM(BlueprintType)
enum class EGfeSDKHighlightType : uint8 {
    NONE,
    Milestone,
    Achievement,
    Incident = 0x4,
    StateChange = 0x8,
    Unannounced = 0x10,
    MAX = 0x20,
};

