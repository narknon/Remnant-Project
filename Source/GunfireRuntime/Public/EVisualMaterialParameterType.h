#pragma once
#include "CoreMinimal.h"
#include "EVisualMaterialParameterType.generated.h"

UENUM(BlueprintType)
enum class EVisualMaterialParameterType : uint8 {
    Scalar,
    Color,
    Texture,
    Tween,
};

