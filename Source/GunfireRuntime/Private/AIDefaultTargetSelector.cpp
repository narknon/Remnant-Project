#include "AIDefaultTargetSelector.h"

UAIDefaultTargetSelector::UAIDefaultTargetSelector() {
    this->CullNotVisibleTargets = false;
    this->CullNotVisibleTargetsWithNoPath = true;
    this->CullNoThreatTargetsWithNoPath = false;
    this->WoundedAwarenessScalar = 0.10f;
}

