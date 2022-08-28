#include "UtilityItem.h"

void AUtilityItem::UseCharge() {
}

void AUtilityItem::Recharge() {
}

float AUtilityItem::GetCooldownPct() {
    return 0.0f;
}

uint8 AUtilityItem::GetCharges() {
    return 0;
}

AUtilityItem::AUtilityItem() {
    this->MaxCharges = 1;
    this->CooldownTime = 1.00f;
}

