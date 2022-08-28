#include "FallDamageComponent.h"

void UFallDamageComponent::TriggerFallDeath() {
}

void UFallDamageComponent::SetEnabled(bool bEnabled) {
}

bool UFallDamageComponent::IsEnabled() const {
    return false;
}

void UFallDamageComponent::DisableUntilGrounded(bool bDisable) {
}

UFallDamageComponent::UFallDamageComponent() {
    this->bStartEnabled = true;
    this->bServerAuthoritative = false;
    this->SafeFallDistance = 1000.00f;
    this->TerminalFallDistance = 2500.00f;
    this->MinFallDuration = 1.00f;
    this->LandHealthPercent = 0.25f;
    this->FallDamageType = NULL;
    this->LandDamageType = NULL;
    this->DoDamageOnLand = true;
    this->bSkipDamageWhileInWater = false;
    this->StatsComponent = NULL;
    this->MovementComponent = NULL;
}

