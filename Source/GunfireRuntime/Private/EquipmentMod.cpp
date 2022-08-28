#include "EquipmentMod.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

class AEquipment;
class AEquipmentMod;
class UInventoryComponent;
class AItem;
class AActor;

bool AEquipmentMod::UnequipMod(UInventoryComponent* Inventory, int32 ItemID, uint8 Slot, bool AddToInventory) {
    return false;
}

void AEquipmentMod::ScaleStat(FName Stat, float Scalar, bool AutoInitValue) const {
}

void AEquipmentMod::OnPostComputeStats_Implementation() const {
}

void AEquipmentMod::OnDetached_Implementation() {
}

void AEquipmentMod::OnComputeStats_Implementation() const {
}

void AEquipmentMod::OnAttached_Implementation() {
}

void AEquipmentMod::ModifyStat(FName Stat, float Value) const {
}

bool AEquipmentMod::HasItemOrEquippedMod(UInventoryComponent* Inventory, TSubclassOf<AItem> ItemBP) {
    return false;
}

float AEquipmentMod::GetStat(FName Stat) const {
    return 0.0f;
}

uint8 AEquipmentMod::GetSlot() const {
    return 0;
}

FInspectInfo AEquipmentMod::GetPreviewInspectInfoFromInventory(AActor* Actor, UInventoryComponent* Inventory, int32 ItemID, uint8 Slot, int32 ModItemID) {
    return FInspectInfo{};
}

FInspectInfo AEquipmentMod::GetPreviewInspectInfo(AActor* Actor, UInventoryComponent* Inventory, int32 ItemID, uint8 Slot, TSubclassOf<AEquipmentMod> Mod, uint8 ModLevel) {
    return FInspectInfo{};
}

AEquipment* AEquipmentMod::GetEquipment() const {
    return NULL;
}

bool AEquipmentMod::FindEquippedModInInventory(UInventoryComponent* Inventory, TSubclassOf<AItem> Mod, int32& OutItemID, FEquipmentModData& OutModData) {
    return false;
}

bool AEquipmentMod::EquipModFromInventory(UInventoryComponent* Inventory, int32 ItemID, uint8 Slot, int32 ModItemID) {
    return false;
}

bool AEquipmentMod::EquipMod(UInventoryComponent* Inventory, int32 ItemID, uint8 Slot, TSubclassOf<AEquipmentMod> Mod, uint8 ModLevel) {
    return false;
}

void AEquipmentMod::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AEquipmentMod, _Equipment);
    DOREPLIFETIME(AEquipmentMod, _Slot);
    DOREPLIFETIME(AEquipmentMod, _Level);
}

AEquipmentMod::AEquipmentMod() {
    this->Hidden = true;
    this->ReplicateMod = false;
    this->VisualSlot = TEXT("Default");
    this->CanBeRemoved = true;
    this->_Equipment = NULL;
    this->_Slot = 0;
    this->_Level = 0;
}

