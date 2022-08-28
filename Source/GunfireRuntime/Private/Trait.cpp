#include "Trait.h"

UTrait::UTrait() {
    this->Type = NULL;
    this->MaxLevel = 1;
    this->bAddIfAlreadyUnlocked = false;
    this->SubsequentUnlockLevelIncrement = 1;
    this->RequiredCharacterLevel = 0;
    this->ConditionList = NULL;
    this->RequiredLicense = ELicensedContent::None;
}

