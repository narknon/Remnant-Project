#pragma once
#include "CoreMinimal.h"
#include "ELogicalOperator.h"
#include "Conditions.generated.h"

class UCondition;

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FConditions {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UCondition*> Conditions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELogicalOperator LogicalOperator;
    
    FConditions();
};

