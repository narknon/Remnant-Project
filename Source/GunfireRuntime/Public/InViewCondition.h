#pragma once
#include "CoreMinimal.h"
#include "Condition.h"
#include "InViewCondition.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UInViewCondition : public UCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Delay;
    
public:
    UInViewCondition();
};

