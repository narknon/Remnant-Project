#include "TraversalState.h"

UTraversalState::UTraversalState() {
    this->bDisableCollisionOnEntry = true;
    this->LerpTime = 0.25f;
    this->bAttachToSurface = false;
    this->bCollideWithSurface = true;
}

