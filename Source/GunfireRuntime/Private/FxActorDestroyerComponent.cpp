#include "FxActorDestroyerComponent.h"

class AActor;

void UFxActorDestroyerComponent::SoftDestroyOwner() {
}

void UFxActorDestroyerComponent::SoftDestroyActor(AActor* Actor, const TArray<FName>& InIgnoredComponents, float InForceDestroyTimer) {
}

bool UFxActorDestroyerComponent::IsSoftDestroying() const {
    return false;
}

UFxActorDestroyerComponent::UFxActorDestroyerComponent() {
    this->ForceDestroyTimer = 10.00f;
}

