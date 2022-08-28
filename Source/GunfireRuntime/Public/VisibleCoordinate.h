#pragma once
#include "CoreMinimal.h"
#include "VisibleCoordinate.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FVisibleCoordinate {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, SaveGame)
    uint16 X;
    
    UPROPERTY(EditAnywhere, SaveGame)
    uint16 Y;
    
    FVisibleCoordinate();
};

