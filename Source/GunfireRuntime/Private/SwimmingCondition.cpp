#include "SwimmingCondition.h"

class UStateMachineComponent;

ESwimmingType USwimmingCondition::GetSwimmingState(UStateMachineComponent* StateMachine) {
    return ESwimmingType::Surface;
}

USwimmingCondition::USwimmingCondition() {
    this->Type = ESwimmingType::Surface;
    this->Method = ESwimmingStateMethod::Calculated;
}

