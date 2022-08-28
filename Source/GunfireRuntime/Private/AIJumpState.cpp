#include "AIJumpState.h"

class UStateMachineComponent;

bool UAIJumpState::IsAIJumpComplete(UStateMachineComponent* StateMachine) {
    return false;
}

UAIJumpState::UAIJumpState() {
    this->Type = EJumpType::NavLink;
    this->DestinationOffset = 0.00f;
    this->ArcMethod = EAutoArcType::ArcHeight;
    this->ArcHeight = 100.00f;
    this->JumpSpeed = 1000.00f;
    this->LeadTarget = false;
    this->RequirePath = false;
    this->ValidateJump = false;
    this->bLockPositionToArc = false;
    this->bSetMaxSpeedToLaunchSpeed = false;
}

