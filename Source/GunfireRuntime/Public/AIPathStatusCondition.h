#pragma once
#include "CoreMinimal.h"
#include "Condition.h"
#include "Navigation/PathFollowingComponent.h"
#include "AIPathStatusCondition.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UAIPathStatusCondition : public UCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EPathFollowingStatus::Type> Status;
    
public:
    UAIPathStatusCondition();
};

