#pragma once
#include "CoreMinimal.h"
#include "Condition.h"
#include "CompareOp.h"
#include "StaminaCondition.generated.h"

UCLASS(Blueprintable, Deprecated, NotPlaceable)
class GUNFIRERUNTIME_API UDEPRECATED_StaminaCondition : public UCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    CompareOp Compare;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Value;
    
public:
    UDEPRECATED_StaminaCondition();
};

