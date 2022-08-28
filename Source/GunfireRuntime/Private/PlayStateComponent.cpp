#include "PlayStateComponent.h"

class APlayerControllerGunfire;
class UPlayStateEffect;

bool UPlayStateComponent::IsLocallyControlled() const {
    return false;
}

APlayerControllerGunfire* UPlayStateComponent::GetOwningPlayerController() const {
    return NULL;
}

float UPlayStateComponent::GetElapsedTransitionTime() const {
    return 0.0f;
}

UPlayStateEffect* UPlayStateComponent::GetActiveEffect(UClass* Class) const {
    return NULL;
}

UPlayStateComponent::UPlayStateComponent() {
    this->StateSet = NULL;
    this->CurrentState = NULL;
}

