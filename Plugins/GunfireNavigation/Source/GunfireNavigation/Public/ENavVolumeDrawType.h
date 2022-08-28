#pragma once
#include "CoreMinimal.h"
#include "ENavVolumeDrawType.generated.h"

UENUM(BlueprintType)
enum ENavVolumeDrawType {
    DRAWTYPE_Open,
    DRAWTYPE_Blocked,
    DRAWTYPE_All,
    DRAWTYPE_MAX UMETA(Hidden),
};

