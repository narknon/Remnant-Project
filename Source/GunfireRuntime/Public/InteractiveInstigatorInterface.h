#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "InteractiveInstigatorInterface.generated.h"

class UStateMachineComponent;
class AItem;
class UWoundedComponent;

UINTERFACE(Blueprintable, MinimalAPI)
class UInteractiveInstigatorInterface : public UInterface {
    GENERATED_BODY()
};

class IInteractiveInstigatorInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool CanDoStateInteraction(UStateMachineComponent* StateMachine, FName StateName);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool CanDoItemInteraction(AItem* Item);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    bool CanDoCharacterRevive(UWoundedComponent* WoundedComponent);
    
};

