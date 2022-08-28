#include "BoundsStateDecorator.h"

UBoundsStateDecorator::UBoundsStateDecorator() {
    this->bSetBoundsOnEnter = true;
    this->BoundsOnEnter = 0.00f;
    this->bRestoreBounds = true;
    this->bSetBoundsOnExit = false;
    this->BoundsOnExit = 0.00f;
}

