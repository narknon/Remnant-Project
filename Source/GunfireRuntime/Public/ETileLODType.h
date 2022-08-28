#pragma once
#include "CoreMinimal.h"
#include "ETileLODType.generated.h"

UENUM(BlueprintType)
enum class ETileLODType : uint8 {
    None,
    Near,
    Distant,
};

