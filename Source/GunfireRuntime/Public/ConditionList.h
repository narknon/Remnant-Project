#pragma once
#include "CoreMinimal.h"
#include "StateMachineSubobject.h"
#include "Conditions.h"
#include "ConditionList.generated.h"

class AActor;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UConditionList : public UStateMachineSubobject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConditions Conditions;
    
    UConditionList();
    UFUNCTION(BlueprintCallable)
    bool EvaluateConditions(AActor* Actor);
    
};

