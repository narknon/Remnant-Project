#include "CooldownStateDecorator.h"

UCooldownStateDecorator::UCooldownStateDecorator() {
    this->ValidateCooldown = true;
    this->Scope = CooldownScope::Local;
    this->CooldownMin = 0.50f;
    this->CooldownMax = 1.50f;
    this->GlobalCooldown = false;
    this->GlobalCooldownMin = 0.25f;
    this->GlobalCooldownMax = 0.50f;
}

