#include "NavigationSystemGunfire.h"

UNavigationSystemGunfire::UNavigationSystemGunfire() {
    this->OctreeUpdateMaxMSPerFrame = 0.00f;
    this->ShouldWarnIfSingleElementsIsExpensive = false;
    this->WarnIfSingleElementsExceedsMS = 0.50f;
}

