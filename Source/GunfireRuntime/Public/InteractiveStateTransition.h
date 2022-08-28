#pragma once
#include "CoreMinimal.h"
#include "ActorStateTransition.h"
#include "Conditions.h"
#include "InteractiveStateTransition.generated.h"

class UActorState;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UInteractiveStateTransition : public UActorStateTransition {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DestinationStateOther;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConditions ConditionsOther;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UActorState* CachedStateOther;
    
public:
    UInteractiveStateTransition();
};

