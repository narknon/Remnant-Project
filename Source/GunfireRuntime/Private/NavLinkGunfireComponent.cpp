#include "NavLinkGunfireComponent.h"
#include "Templates/SubclassOf.h"

class UNavArea;

void UNavLinkGunfireComponent::SetLinkEnabledArea(TSubclassOf<UNavArea> AreaClass) {
}

void UNavLinkGunfireComponent::SetLinkEnabled(bool bEnabled) {
}

void UNavLinkGunfireComponent::SetLinkDisableArea(TSubclassOf<UNavArea> AreaClass) {
}

bool UNavLinkGunfireComponent::IsLinkEnabled() const {
    return false;
}

TSubclassOf<UNavArea> UNavLinkGunfireComponent::GetLinkEnabledArea() const {
    return NULL;
}

TSubclassOf<UNavArea> UNavLinkGunfireComponent::GetLinkDisabledArea() const {
    return NULL;
}

UNavLinkGunfireComponent::UNavLinkGunfireComponent() {
}

