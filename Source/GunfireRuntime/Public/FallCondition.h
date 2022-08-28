#pragma once
#include "CoreMinimal.h"
#include "EFallConditionCheck.h"
#include "Condition.h"
#include "FallCondition.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UFallCondition : public UCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EFallConditionCheck CheckBy;
    
public:
    UFallCondition();
};

