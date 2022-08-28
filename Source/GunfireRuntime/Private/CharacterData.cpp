#include "CharacterData.h"

FCharacterData::FCharacterData() {
    this->ExperienceValue = 0;
    this->HealthMax = 0;
    this->HealthRegen = 0.00f;
    this->StaminaMax = 0;
    this->StaminaRegen = 0.00f;
    this->StaminaRegenDelay = 0.00f;
    this->StaminaEmptyDelay = 0.00f;
    this->Damage = 0;
    this->DamageMod = 0;
    this->Defense = 0;
    this->PhysicalResistance = 0;
    this->ArcaneResistance = 0;
    this->FireResistance = 0;
    this->EarthResistance = 0;
    this->AirResistance = 0;
    this->IceResistance = 0;
    this->WrathResistance = 0;
    this->ChaosResistance = 0;
    this->AttackSpeed = 0.00f;
}

