#include "Equipment.h"
#include "Net/UnrealNetwork.h"
#include "StatsComponent.h"

class ACharacterGunfire;
class AEquipmentMod;
class UInventoryComponent;
class AUIHud;

bool AEquipment::ValidateEquip_Implementation(ACharacterGunfire* ToCharacter) {
    return false;
}

void AEquipment::Unequip() {
}

void AEquipment::SetInputEnabled(bool Enabled) {
}

void AEquipment::SetInHand(bool InHand) {
}

void AEquipment::SetAttachmentsVisible(bool Visible) {
}

void AEquipment::ServerSetInHand_Implementation(bool InHand) {
}
bool AEquipment::ServerSetInHand_Validate(bool InHand) {
    return true;
}

void AEquipment::ScaleStat(FName Stat, float Scalar, bool AutoInitValue) {
}


void AEquipment::PostComputeStats() {
}

void AEquipment::PostComputeCharacterStats_Implementation() {
}

float AEquipment::PlayAnimation(FName AnimationID, float PlayRate, bool bCharacterOnly) {
    return 0.0f;
}












void AEquipment::ModifyStat(FName Stat, float Value) {
}

bool AEquipment::IsLocallyControlled() {
    return false;
}

bool AEquipment::IsInHand() const {
    return false;
}

bool AEquipment::IsEquipped() const {
    return false;
}

bool AEquipment::IsActive() const {
    return false;
}

bool AEquipment::IsActionAllowed() const {
    return false;
}

void AEquipment::InstanceDataChanged() {
}

float AEquipment::GetStat(FName Stat) {
    return 0.0f;
}

int32 AEquipment::GetItemID() {
    return 0;
}

UInventoryComponent* AEquipment::GetInventoryComponent() {
    return NULL;
}

AUIHud* AEquipment::GetHud() const {
    return NULL;
}

int32 AEquipment::GetEquipmentSlotIdx() {
    return 0;
}

AEquipmentMod* AEquipment::GetEquipmentMod(uint8 Slot) {
    return NULL;
}

FName AEquipment::GetCurrentAnimation() const {
    return NAME_None;
}

ACharacterGunfire* AEquipment::GetCharacter() const {
    return NULL;
}

TArray<AEquipmentMod*> AEquipment::GetAttachedMods() {
    return TArray<AEquipmentMod*>();
}

void AEquipment::Detach() {
}

void AEquipment::Deactivate() {
}

void AEquipment::ComputeStats() {
}

void AEquipment::ComputeCharacterStats() {
}

void AEquipment::Activate() {
}

void AEquipment::_NotifyTakeDamage(const FDamageInfo& DamageInfo) {
}

void AEquipment::_NotifyHitTarget(const FDamageInfo& DamageInfo) {
}

void AEquipment::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AEquipment, CharacterReplicated);
    DOREPLIFETIME(AEquipment, bIsActiveReplicated);
    DOREPLIFETIME(AEquipment, bIsInHandReplicated);
}

AEquipment::AEquipment() {
    this->AnimationLayer = TEXT("UpperBody");
    this->AutoEnableInput = true;
    this->ShouldUnequip = true;
    this->UseEquipmentAnimTimings = false;
    this->EquipSound = NULL;
    this->StatsComp = CreateDefaultSubobject<UStatsComponent>(TEXT("StatsComp"));
    this->Character = NULL;
    this->CharacterReplicated = NULL;
    this->VisualComponent = NULL;
    this->bIsActiveReplicated = false;
    this->bIsInHandReplicated = false;
}

