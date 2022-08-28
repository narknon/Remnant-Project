#include "AIPathToStateDecorator.h"

UAIPathToStateDecorator::UAIPathToStateDecorator() {
    this->AcceptanceRadius = 100.00f;
    this->AcceptanceRadiusMax = -1.00f;
    this->StopOnOverlap = true;
    this->OrientToTargetRadius = -1.00f;
    this->PathRestartDistance = -1.00f;
    this->ProjectDestinationToNavMesh = false;
}

