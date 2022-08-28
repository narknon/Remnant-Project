#include "Item.h"
#include "Net/UnrealNetwork.h"
#include "PersistenceComponent.h"

class UInventoryComponent;
class UItemInstanceData;
class APawn;
class AActor;

bool AItem::ValidateAdd_Implementation(UInventoryComponent* Inventory, int32 DesiredQuantity, int32& AllowedQuantity) {
    return false;
}

void AItem::SetQuantity(int32 Quantity) {
}

void AItem::SetLevel(uint8 Level) {
}

bool AItem::PreAdd_Implementation(UInventoryComponent* Inventory, int32 Quantity) {
    return false;
}

bool AItem::PickupPreAdd_Implementation(UInventoryComponent* Inventory, int32 Quantity, int32 Level) {
    return false;
}

void AItem::OnRep_InstanceData(UItemInstanceData* PrevData) {
}

void AItem::OnPickupFailed_Implementation() {
}




void AItem::InitializeLootFxForLocalPawn(APawn* Pawn) {
}

int32 AItem::GetQuantity() {
    return 0;
}

int32 AItem::GetMaxQuantity_Implementation() const {
    return 0;
}

uint8 AItem::GetLevel_Implementation() const {
    return 0;
}

FInspectInfo AItem::GetInspectInfo(AActor* Actor, UItemInstanceData* InInstanceData, int32 LevelOverride) {
    return FInspectInfo{};
}

void AItem::DropBounce_Implementation() {
}

void AItem::Bounce_Implementation() {
}

void AItem::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AItem, InstanceData);
    DOREPLIFETIME(AItem, bOnGround);
}

AItem::AItem() {
    this->PersistenceComp = CreateDefaultSubobject<UPersistenceComponent>(TEXT("Persistence"));
    this->Type = NULL;
    this->Category = NULL;
    this->MaxStackCount = 1;
    this->InstanceData = NULL;
    this->bNeedsQuantityToSelect = true;
    this->Icon = NULL;
    this->HUDIcon = NULL;
    this->Interactable = true;
    this->UseInteractInfo = false;
    this->InteractIcon = NULL;
    this->PickupSound = NULL;
    this->LootFxAttachNode = TEXT("LootFX");
    this->LootFxOverride = NULL;
    this->DoBounce = true;
    this->BounceFlipSound = NULL;
    this->BounceSound = NULL;
    this->DroppedImpactEffect = NULL;
    this->bOnGround = true;
    this->LootFxParticles = NULL;
    this->Inspecting = false;
}

