#pragma once
#include "CoreMinimal.h"
#include "ETileFlags.generated.h"

UENUM(BlueprintType)
enum class ETileFlags : uint8 {
    AllowSpawns,
    AllowQuests,
    NoNavValidate,
};

