#pragma once
#include "CoreMinimal.h"
#include "ELevelLoadState.generated.h"

UENUM(BlueprintType)
enum class ELevelLoadState : uint8 {
    Unloaded,
    LoadRequested,
    Loaded,
    Loading,
    Unloading,
    PreUnloaded,
};

