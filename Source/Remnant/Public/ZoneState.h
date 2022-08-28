#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EZoneStatus.h"
#include "ZoneState.generated.h"

USTRUCT(BlueprintType)
struct FZoneState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EZoneStatus Status;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LevelOffset;
    
    REMNANT_API FZoneState();
};

