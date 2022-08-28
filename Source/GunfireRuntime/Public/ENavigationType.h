#pragma once
#include "CoreMinimal.h"
#include "ENavigationType.generated.h"

UENUM(BlueprintType)
enum ENavigationType {
    Unknown,
    Ground,
    Air,
    Water,
};

