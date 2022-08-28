#include "GenericItem.h"
#include "Net/UnrealNetwork.h"

class UInventoryComponent;
class AActor;

bool AGenericItem::ValidatePickupHandled_Implementation(const FSpawnList& SpawnList, UInventoryComponent* Inventory) {
    return false;
}

bool AGenericItem::ValidateAddToInventory_Implementation(const FSpawnList& SpawnList, UInventoryComponent* Inventory) {
    return false;
}

void AGenericItem::OnRep_CachedSpawnList() {
}


bool AGenericItem::HasMaxSpawnsForCharacter_Implementation(AActor* Actor) {
    return false;
}

void AGenericItem::HandleAward_Implementation(const FSpawnList& SpawnList, UInventoryComponent* Inventory, bool bForceNoSharing) {
}

void AGenericItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AGenericItem, CachedSpawnList);
}

AGenericItem::AGenericItem() {
    this->RandomizedDrop = NULL;
    this->bShareNonItemPickups = false;
    this->bUseGeneratedObjectLabel = true;
    this->bUseGeneratedObjectIcon = true;
    this->bUseGeneratedObjectPickupSound = false;
    this->bAddToInventory = false;
    this->bSaveOnAward = true;
}

