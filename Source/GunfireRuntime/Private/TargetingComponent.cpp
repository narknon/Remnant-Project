#include "TargetingComponent.h"

void UTargetingComponent::OnNewTargetSet_Implementation(FHeuristicBoundsHitResult& NewTargetHitResult) {
}

bool UTargetingComponent::GetTarget(FHeuristicBoundsHitResult& OutTargetHitResult, bool bForceRecalc) {
    return false;
}

bool UTargetingComponent::GetSnapTarget(FHeuristicBoundsHitResult& OutSnapTargetHitResult, bool bForceRecalc) {
    return false;
}

UTargetingComponent::UTargetingComponent() {
    this->bCacheTargetOnTick = true;
    this->TargetManager = NULL;
}

