#pragma once
#include "CoreMinimal.h"
#include "VisibleCoordinate.h"
#include "VisitedCoordinates.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FVisitedCoordinates {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FVisibleCoordinate> Coordinates;
    
    FVisitedCoordinates();
};

