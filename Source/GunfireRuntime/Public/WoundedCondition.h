#pragma once
#include "CoreMinimal.h"
#include "EWoundedState.h"
#include "Condition.h"
#include "WoundedCondition.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UWoundedCondition : public UCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EWoundedState WoundedState;
    
public:
    UWoundedCondition();
};

