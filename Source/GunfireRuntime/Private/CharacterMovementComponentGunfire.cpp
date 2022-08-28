#include "CharacterMovementComponentGunfire.h"
#include "Templates/SubclassOf.h"

class AActor;
class APhysicsBounds;
class UPhysicsBoundsType;

void UCharacterMovementComponentGunfire::SetSwingConstraint(bool Enabled, const FVector& SwingPoint, float RopeLength) {
}

void UCharacterMovementComponentGunfire::SetNavigationType(TEnumAsByte<ENavigationType> NavigationType) {
}

void UCharacterMovementComponentGunfire::SetCanSwim(bool bInCanSwim) {
}

bool UCharacterMovementComponentGunfire::Is3DNavigating() const {
    return false;
}

AActor* UCharacterMovementComponentGunfire::GetWaterBoundsActor(bool bConstrainToFluidFilled) const {
    return NULL;
}

APhysicsBounds* UCharacterMovementComponentGunfire::GetWaterBounds(bool bConstrainToFluidFilled) const {
    return NULL;
}

AActor* UCharacterMovementComponentGunfire::GetPhysicsBoundsActor() const {
    return NULL;
}

APhysicsBounds* UCharacterMovementComponentGunfire::GetPhysicsBounds() const {
    return NULL;
}

TEnumAsByte<ENavigationType> UCharacterMovementComponentGunfire::GetNavigationType() const {
    return Unknown;
}

FString UCharacterMovementComponentGunfire::GetDebugInfo(int32 DebugLevel) const {
    return TEXT("");
}

TSubclassOf<UPhysicsBoundsType> UCharacterMovementComponentGunfire::GetCurrentWaterBoundsType(bool bConstrainToFluidFilled) const {
    return NULL;
}

TSubclassOf<UPhysicsBoundsType> UCharacterMovementComponentGunfire::GetCurrentPhysicsBoundsType() const {
    return NULL;
}

void UCharacterMovementComponentGunfire::AddExternalVelocity(FVector ExternalVelocityIn) {
}

UCharacterMovementComponentGunfire::UCharacterMovementComponentGunfire() {
    this->MaxSpeedBackwards = -1.00f;
    this->bAllowVerticalInputAcceleration = true;
    this->bIgnoreZFrictionAndBrakingWhenFlying = false;
    this->DoSoftCharacterCollision = false;
    this->SoftCharacterCollisionWeight = 10.00f;
    this->SoftCharacterCollisionRadius = -1.00f;
    this->SoftCharacterIgnore = NULL;
    this->DoSpecialCharacterCollision = false;
    this->SpecialCharacterCollisionIterations = 10;
    this->SpecialCharacterCollisionAlpha = 0.25f;
    this->TurnSmoothTime = 0.00f;
    this->CrouchedRadius = 40.00f;
    this->ConstrainToNavMesh = false;
    this->PerchSimpleRadius = 5.00f;
    this->bPerchFallingRadiusChange = false;
    this->PerchFallingRadius = 5.00f;
    this->PerchFallingThreshold = -300.00f;
    this->PerchShowDebug = false;
    this->KnockBackImpulseScale = 1.00f;
    this->KnockUpImpulseScale = 1.00f;
    this->WallSlideDampenThresholdDeg = 0.00f;
    this->WallSlideDampenMulti = 0.60f;
    this->AcceptanceRadiusScale = 1.10f;
    this->AcceptanceHeightScale = 1.05f;
    this->DefaultNavigationType = Ground;
    this->FullTurnSpeedVelocity = 1500.00f;
    this->bAutoSetSwimmingMode = true;
    this->bStartWithSwimmingDisabled = false;
}

