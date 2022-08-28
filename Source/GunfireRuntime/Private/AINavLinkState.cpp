#include "AINavLinkState.h"

UAINavLinkState::UAINavLinkState() {
    this->SnapStartPositionToGround = false;
    this->LerpTime = 0.20f;
    this->StopMovementOnExit = true;
}

