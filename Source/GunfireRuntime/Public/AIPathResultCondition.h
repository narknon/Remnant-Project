#pragma once
#include "CoreMinimal.h"
#include "Condition.h"
#include "Navigation/PathFollowingComponent.h"
#include "AIPathResultCondition.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UAIPathResultCondition : public UCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EPathFollowingResult::Type> Result;
    
public:
    UAIPathResultCondition();
};

