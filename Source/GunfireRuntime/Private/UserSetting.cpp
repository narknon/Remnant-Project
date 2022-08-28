#include "UserSetting.h"

void UUserSetting::ResetToDefault() {
}

FText UUserSetting::GetDisplayValue() const {
    return FText::GetEmpty();
}

void UUserSetting::Apply() {
}

UUserSetting::UUserSetting() {
    this->AllowOnConsoles = true;
    this->Platforms = 31;
    this->Settings = NULL;
}

