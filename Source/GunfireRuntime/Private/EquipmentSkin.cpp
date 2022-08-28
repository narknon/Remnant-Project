#include "EquipmentSkin.h"

class AEquipmentSkin;
class AEquipment;
class UInventoryComponent;

bool AEquipmentSkin::IsSkinEquipped(UInventoryComponent* Inventory, int32 SkinID) {
    return false;
}

TArray<int32> AEquipmentSkin::GetSkinsForItem(UInventoryComponent* Inventory, int32 ItemID) {
    return TArray<int32>();
}

AEquipmentSkin* AEquipmentSkin::GetSkinForBP(UInventoryComponent* Inventory, TSoftClassPtr<AEquipment> ItemBP) {
    return NULL;
}

void AEquipmentSkin::EquipSkin(UInventoryComponent* Inventory, int32 ItemID, int32 SkinID) {
}

AEquipmentSkin::AEquipmentSkin() {
}

