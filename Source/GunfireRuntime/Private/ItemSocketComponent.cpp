#include "ItemSocketComponent.h"
#include "Templates/SubclassOf.h"

class AItem;
class ACharacterGunfire;
class UInventoryComponent;

void UItemSocketComponent::RequestReturnItemToInventory_Implementation(ACharacterGunfire* Subject) {
}
bool UItemSocketComponent::RequestReturnItemToInventory_Validate(ACharacterGunfire* Subject) {
    return true;
}

void UItemSocketComponent::RequestAddItemFromInventoryById_Implementation(UInventoryComponent* Inventory, int32 ItemID) {
}
bool UItemSocketComponent::RequestAddItemFromInventoryById_Validate(UInventoryComponent* Inventory, int32 ItemID) {
    return true;
}

void UItemSocketComponent::RequestAddItemFromInventoryByClass_Implementation(UInventoryComponent* Inventory, TSubclassOf<AItem> ItemClass) {
}
bool UItemSocketComponent::RequestAddItemFromInventoryByClass_Validate(UInventoryComponent* Inventory, TSubclassOf<AItem> ItemClass) {
    return true;
}

void UItemSocketComponent::RequestAddItemFromInventory_Implementation(ACharacterGunfire* Subject) {
}
bool UItemSocketComponent::RequestAddItemFromInventory_Validate(ACharacterGunfire* Subject) {
    return true;
}

void UItemSocketComponent::RemoveItem_Implementation() {
}

bool UItemSocketComponent::IsValid_Implementation(TSubclassOf<AItem> ItemClass) const {
    return false;
}

bool UItemSocketComponent::IsFull() const {
    return false;
}

bool UItemSocketComponent::IsEmpty() const {
    return false;
}

bool UItemSocketComponent::HasInteractableSlot() const {
    return false;
}

void UItemSocketComponent::ForceFill() {
}

bool UItemSocketComponent::CanAddItemOfClass(TSubclassOf<AItem> ItemClass) const {
    return false;
}

void UItemSocketComponent::AddItem_Implementation(TSubclassOf<AItem> ItemClass) {
}

UItemSocketComponent::UItemSocketComponent() {
    this->Blocked = false;
}

