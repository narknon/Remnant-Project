#include "RemnantSaveGameProfile.h"
#include "Templates/SubclassOf.h"

class AItem;

bool URemnantSaveGameProfile::UpdateAccountCurrency(TSubclassOf<AItem> CurrencyType, int32 Quantity) {
    return false;
}

int32 URemnantSaveGameProfile::GetAccountCurrencyForItemType(TSubclassOf<AItem> CurrencyType) {
    return 0;
}

URemnantSaveGameProfile::URemnantSaveGameProfile() {
    this->ActiveCharacterIndex = -1;
    this->bNeedsCheatedSaveConfirmation = false;
    this->SurvivalBossesKilled = 0;
    this->SurvivalCoopBossesKilled = 0;
    this->SurvivalItemsAcquired = 0;
}

