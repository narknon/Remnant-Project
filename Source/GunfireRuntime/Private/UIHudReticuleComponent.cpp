#include "UIHudReticuleComponent.h"

class ARangedWeapon;
class AMeleeWeapon;

void UUIHudReticuleComponent::OnNotifyHitTarget(const FDamageInfo& DamageInfo) {
}

ARangedWeapon* UUIHudReticuleComponent::GetRangedWeapon() const {
    return NULL;
}

AMeleeWeapon* UUIHudReticuleComponent::GetMeleeWeapon() const {
    return NULL;
}

float UUIHudReticuleComponent::GetHitAlpha() const {
    return 0.0f;
}

float UUIHudReticuleComponent::GetCurrentSpread() const {
    return 0.0f;
}

UUIHudReticuleComponent::UUIHudReticuleComponent() {
    this->WeaponType = NULL;
    this->MeleeWeaponType = NULL;
    this->DefaultReticule = NULL;
    this->SpreadBlendRate = 20.00f;
    this->DisabledWeaponVisuals = EDisabledWeaponVisuals::ShowReticuleWithDisabledColor;
    this->bLimitToAimAssistRange = true;
    this->GhostReticuleSmoothingRate = 10.00f;
    this->MaxGhostReticuleOffset = 0.03f;
    this->CenterToGhostReticuleTolerance = 0.04f;
    this->AllowGhostReticuleOnCharacters = false;
    this->CachedCharacter = NULL;
}

