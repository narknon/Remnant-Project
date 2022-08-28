#include "RemnantFogOfWarComponent.h"

class UMaterialInstanceDynamic;
class AActor;

void URemnantFogOfWarComponent::UpdateMaterial(UMaterialInstanceDynamic* MaterialInstance, FVector WorldLocation, bool bSetMask, float ScaleOverride) const {
}

void URemnantFogOfWarComponent::SetDebugLocation(const FVector& NewLocation) {
}

void URemnantFogOfWarComponent::LockToActor(AActor* Actor) {
}

bool URemnantFogOfWarComponent::HasDebugLocation() const {
    return false;
}

AActor* URemnantFogOfWarComponent::GetLockActor() const {
    return NULL;
}

void URemnantFogOfWarComponent::ClearDebugLocation() {
}

URemnantFogOfWarComponent::URemnantFogOfWarComponent() {
    this->MinimumWorldBoundsDimension = 32000.00f;
    this->WorldPaddingScale = 1.00f;
    this->Scale = 1.00f;
    this->LockedActor = NULL;
    this->VisitedCoordinatesOwner = NULL;
}

