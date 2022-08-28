#include "CheatProtectedItemParams.h"

FCheatProtectedItemParams::FCheatProtectedItemParams() {
    this->ProtectedType = NULL;
    this->QuantityTolerance = 0;
    this->ValidateOnRemove = false;
    this->ValidateOnAdd = false;
    this->ValidationType = EOnAddCheatValidationType::CheckByQuantity;
}

