#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EAITacticalPointType.h"
#include "AITacticalPoint.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FAITacticalPoint {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAITacticalPointType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Position;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Direction;
    
public:
    FAITacticalPoint();
};

