#include "AIConvergeToStateDecorator.h"

UAIConvergeToStateDecorator::UAIConvergeToStateDecorator() {
    this->ConvergeTo = EConvergeToType::TacticalPoint;
    this->ConvergeTime = 0.25f;
    this->ConvergeXY = true;
    this->ConvergeZ = false;
    this->ConvergeHeading = true;
    this->ConvereHeadingFaceTarget = false;
    this->UpdateTarget = false;
    this->StopUpdatingWhenConverged = false;
}

