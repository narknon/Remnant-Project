#pragma once
#include "CoreMinimal.h"
#include "EPlayableLoadState.generated.h"

UENUM(BlueprintType)
enum class EPlayableLoadState : uint8 {
    None,
    Preload,
    Load,
    Unload,
    UnloadAndRemove,
};

