#include "SplineFollowingComponent.h"

class USplineComponent;

void USplineFollowingComponent::SetSpline(USplineComponent* Spline, TEnumAsByte<ESplineAttachmentRule::Type> Location, float CustomTime) {
}

float USplineFollowingComponent::GetCurrentSplineTime() const {
    return 0.0f;
}

USplineFollowingComponent::USplineFollowingComponent() {
    this->MovementSpeed = 1000.00f;
    this->MovementDirection = ESplineMovementDirection::Forward;
    this->AttachType = ESplineAttachType::LocationAndRotation;
    this->bPingPong = false;
    this->bIsPaused = false;
}

