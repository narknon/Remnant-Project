#include "EnumUserSetting.h"

void UEnumUserSetting::SetValueEnum(const FEnumUserSettingEntry& Entry) {
}

bool UEnumUserSetting::GetValueEnum(FEnumUserSettingEntry& OutEntry) {
    return false;
}

int32 UEnumUserSetting::GetNumEntries() const {
    return 0;
}

bool UEnumUserSetting::GetNextEntry(int32 CurrentValue, FEnumUserSettingEntry& OutNext, bool bForwards) {
    return false;
}

bool UEnumUserSetting::GetEnumEntryByValue(int32 Value, FEnumUserSettingEntry& OutEntry) {
    return false;
}

bool UEnumUserSetting::GetEnumEntryByIndex(int32 Index, FEnumUserSettingEntry& OutEntry) {
    return false;
}

void UEnumUserSetting::EnableValue(int32 InValue) {
}

void UEnumUserSetting::DisableValue(int32 InValue) {
}

UEnumUserSetting::UEnumUserSetting() {
    this->bWraps = true;
}

