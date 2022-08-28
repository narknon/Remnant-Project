#include "AINearbyPlayerTargetSelector.h"

UAINearbyPlayerTargetSelector::UAINearbyPlayerTargetSelector() {
    this->Range = 300.00f;
    this->HasPath = false;
    this->CullNotVisible = true;
    this->MaxPathInvalidTime = 0.00f;
}

