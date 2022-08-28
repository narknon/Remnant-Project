#pragma once
#include "CoreMinimal.h"
#include "Conditions.h"
#include "VariableInfo.generated.h"

USTRUCT(BlueprintType)
struct FVariableInfo {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConditions Conditions;
    
    GUNFIRERUNTIME_API FVariableInfo();
};

