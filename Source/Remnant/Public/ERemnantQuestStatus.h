#pragma once
#include "CoreMinimal.h"
#include "ERemnantQuestStatus.generated.h"

UENUM(BlueprintType)
enum class ERemnantQuestStatus : uint8 {
    Unloaded,
    Loading,
    Loaded,
    Error,
};

