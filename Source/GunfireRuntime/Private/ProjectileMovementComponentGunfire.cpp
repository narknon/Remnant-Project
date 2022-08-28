#include "ProjectileMovementComponentGunfire.h"

FVector UProjectileMovementComponentGunfire::SimulateBounce(FVector CurrentVelocity, const FHitResult& Hit, float& OutGravityScale) {
    return FVector{};
}

void UProjectileMovementComponentGunfire::SetPenetrate(bool bShouldPenetrate) {
}

UProjectileMovementComponentGunfire::UProjectileMovementComponentGunfire() {
    this->Penetrate = false;
    this->bApplyPostBounceGravityScale = false;
    this->PostBounceGravityScale = 1.00f;
    this->BounceNormalAlignmentAlpha = 0.00f;
    this->PenetrateVelocityModifier = 1.00f;
    this->bApplyPostBounceVelocityClamp = false;
}

