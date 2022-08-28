#pragma once
#include "CoreMinimal.h"
#include "ECullCategory.generated.h"

UENUM(BlueprintType)
enum class ECullCategory : uint8 {
    Tracers,
    SoundsAttached,
    EmitterAttached,
    EmitterAtLocation,
    ImpactEffect,
    Decal,
};

