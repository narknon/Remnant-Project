#include "SessionDetails.h"

FSessionDetails::FSessionDetails() {
    this->PowerLevel = 0;
    this->Difficulty = 0;
    this->CharacterType = 0;
    this->Location = EPresenceContent::MENU;
    this->DlcRequired = EDlcRequirementTypes::None;
    this->IsHighPriority = false;
}

