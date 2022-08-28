#include "TraitsComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

class UProgressionComponent;
class UTrait;

bool UTraitsComponent::UnlockTrait(TSubclassOf<UTrait> TraitBP, int32 StartingLevel) {
    return false;
}

void UTraitsComponent::SetTraitLevel(TSubclassOf<UTrait> TraitBP, int32 NewLevel, bool bAwardTraitPoints) {
}

void UTraitsComponent::SetAllTraitLevels(int32 NewLevel, bool bAwardTraitPoints) {
}

void UTraitsComponent::ServerUnlockTrait_Implementation(TSubclassOf<UTrait> TraitBP, int32 StartingLevel) {
}
bool UTraitsComponent::ServerUnlockTrait_Validate(TSubclassOf<UTrait> TraitBP, int32 StartingLevel) {
    return true;
}

void UTraitsComponent::Purchase_Implementation(TSubclassOf<UTrait> TraitBP) {
}
bool UTraitsComponent::Purchase_Validate(TSubclassOf<UTrait> TraitBP) {
    return true;
}

void UTraitsComponent::OnRep_Traits() {
}

void UTraitsComponent::OnRep_TraitPointsSpent() {
}

void UTraitsComponent::OnRep_TraitPoints() {
}

void UTraitsComponent::OnLevelUp() {
}

void UTraitsComponent::OnComputeStats() {
}

bool UTraitsComponent::HasTraitByName(const FName& NameID, int32 RequiredLevel) const {
    return false;
}

bool UTraitsComponent::HasTrait(TSubclassOf<UTrait> TraitBP, int32 RequiredLevel) const {
    return false;
}

int32 UTraitsComponent::GetTraitLevel(TSubclassOf<UTrait> TraitBP) const {
    return 0;
}

int32 UTraitsComponent::GetTotalTraitLevels() const {
    return 0;
}

UProgressionComponent* UTraitsComponent::GetProgression() const {
    return NULL;
}

TArray<FTraitInfo> UTraitsComponent::GetAvailableTraits() const {
    return TArray<FTraitInfo>();
}

int32 UTraitsComponent::GetAvailableTraitPoints() const {
    return 0;
}

TArray<FTraitInfo> UTraitsComponent::GetAllTraits() const {
    return TArray<FTraitInfo>();
}

void UTraitsComponent::Equip_Implementation(TSubclassOf<UTrait> TraitBP, int32 SlotIndex) {
}
bool UTraitsComponent::Equip_Validate(TSubclassOf<UTrait> TraitBP, int32 SlotIndex) {
    return true;
}

bool UTraitsComponent::CanPurchase(TSubclassOf<UTrait> TraitBP) {
    return false;
}

bool UTraitsComponent::CanEquip(TSubclassOf<UTrait> TraitBP, int32 SlotIndex) {
    return false;
}

void UTraitsComponent::AddTraitPoints(int32 Points) {
}

bool UTraitsComponent::AddTrait(TSubclassOf<UTrait> TraitBP, int32 Level) {
    return false;
}

void UTraitsComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UTraitsComponent, TraitPoints);
    DOREPLIFETIME(UTraitsComponent, TraitPointsSpent);
    DOREPLIFETIME(UTraitsComponent, Traits);
}

UTraitsComponent::UTraitsComponent() {
    this->TraitPointsPerLevelTable = NULL;
    this->DefaultTraitLevel = 1;
    this->TraitPoints = 0;
    this->TraitPointsSpent = 0;
}

