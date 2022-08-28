#pragma once
#include "CoreMinimal.h"
#include "StateMachineSubobject.h"
#include "Condition.generated.h"

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API UCondition : public UStateMachineSubobject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool InvertCondition;
    
    UCondition();
};

