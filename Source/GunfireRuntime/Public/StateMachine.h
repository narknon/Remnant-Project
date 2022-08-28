#pragma once
#include "CoreMinimal.h"
#include "StateMachineSubobject.h"
#include "StateMachine.generated.h"

class UActorState;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UStateMachine : public UStateMachineSubobject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DefaultState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UActorState*> States;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UActorState*> HitReactions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UActorState*> LinkedHitReactions;
    
    UStateMachine();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActorState* GetStateParent(UActorState* State) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActorState* GetState(const FName& NameID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActorState* GetRootState(UActorState* State) const;
    
};

