#include "RemnantPlayerInventoryComponent.h"
#include "Templates/SubclassOf.h"

class AActor;
class AItem;

void URemnantPlayerInventoryComponent::ServerOnClientExceptionUpdate_Implementation(TSubclassOf<AItem> ItemBP, int32 Quantity) {
}
bool URemnantPlayerInventoryComponent::ServerOnClientExceptionUpdate_Validate(TSubclassOf<AItem> ItemBP, int32 Quantity) {
    return true;
}

void URemnantPlayerInventoryComponent::OnTrackedInstanceDataChanged() {
}

int32 URemnantPlayerInventoryComponent::ModifyLevelForNewItem(TSubclassOf<AItem> ItemBP, int32 ItemLevel) {
    return 0;
}

void URemnantPlayerInventoryComponent::MarkClientSoftInventoryChangeValid(TSoftClassPtr<AItem> ItemSoftRef, int32 Quantity, int32 ItemLevel, bool IsItemRemoval) {
}

void URemnantPlayerInventoryComponent::MarkClientInventoryChangeValid(TSubclassOf<AItem> ItemBP, int32 Quantity, int32 ItemLevel, bool IsItemRemoval) {
}

bool URemnantPlayerInventoryComponent::IsItemCheatProtected(TSubclassOf<AItem> ItemBP) const {
    return false;
}

bool URemnantPlayerInventoryComponent::IsCheatValidationEnabled() const {
    return false;
}

int32 URemnantPlayerInventoryComponent::GetLevelForNewItem(AActor* Actor, TSubclassOf<AItem> ItemBP, int32 ItemLevel) {
    return 0;
}

void URemnantPlayerInventoryComponent::ClientValidationTimeOut() {
}

void URemnantPlayerInventoryComponent::AddProtectionTimeOut() {
}

URemnantPlayerInventoryComponent::URemnantPlayerInventoryComponent() {
    this->MaxValidItemAmountOverTime = 1000000;
    this->AddedItemTimeOutSeconds = 60.00f;
    this->DoCurrencyOverTimeValidation = false;
    this->DoCurrencyValidationOnRemove = false;
    this->CurrencyQuantityTolerance = 150;
}

