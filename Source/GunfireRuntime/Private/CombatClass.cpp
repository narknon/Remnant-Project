#include "CombatClass.h"

UCombatClass::UCombatClass() {
    this->Size = ECombatSize::Normal;
    this->Weight = 4.00f;
    this->DefaultPressure = 3.00f;
    this->PressureLockout = 0.50f;
    this->MaxMeleePressure = 12.00f;
    this->ResidualPressureDecay = -1.00f;
    this->MaxRangedPressure = 12.00f;
    this->MaxInsiderWeight = 12.00f;
    this->MinInsiderTime = 5.00f;
    this->MaxInsiderTime = 10.00f;
    this->MaxOutsiderRange = 750.00f;
    this->ComputedStats = NULL;
}

