#pragma once
#include "CoreMinimal.h"
#include "StateMachineSubobject.h"
#include "ActorStateID.h"
#include "Conditions.h"
#include "ActorStateTransition.generated.h"

class UActorState;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UActorStateTransition : public UStateMachineSubobject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Enabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DestinationState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActorStateID DestinationStateID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString Comment;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConditions Conditions;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetDestinationAnimationID;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UActorState* CachedState;
    
public:
    UActorStateTransition();
};

