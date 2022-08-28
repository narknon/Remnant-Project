#include "AIFollowTargetStateDecorator.h"

UAIFollowTargetStateDecorator::UAIFollowTargetStateDecorator() {
    this->MinRadius = 100.00f;
    this->MaxRadius = 200.00f;
    this->MinHeight = 60.00f;
    this->MaxHeight = 80.00f;
    this->FollowAngle = 60.00f;
    this->MatchSpeed = true;
    this->MaxSpeed = 500.00f;
    this->MatchDistance = 300.00f;
    this->AcceptanceRadius = 20.00f;
    this->OutOfRangeScalar = 2.00f;
}

