#pragma once
#include "CoreMinimal.h"
#include "ERedloadInteractiveMode.generated.h"

UENUM(BlueprintType)
enum class ERedloadInteractiveMode : uint8 {
    Actors,
    MashableActors,
    Items,
    Revive,
};

