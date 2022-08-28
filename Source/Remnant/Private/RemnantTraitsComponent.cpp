#include "RemnantTraitsComponent.h"

void URemnantTraitsComponent::ServerAddTraitPoints_Implementation(int32 Points) {
}
bool URemnantTraitsComponent::ServerAddTraitPoints_Validate(int32 Points) {
    return true;
}

void URemnantTraitsComponent::MarkClientTraitPointChangeValid(int32 AddedTraitPoints) {
}

TArray<FTraitInfo> URemnantTraitsComponent::GetTraitsForLevel(int32 Level) const {
    return TArray<FTraitInfo>();
}

TArray<int32> URemnantTraitsComponent::GetTraitLevelBands() const {
    return TArray<int32>();
}

FTraitInfo URemnantTraitsComponent::GetTraitByLevelAndCategory(int32 Level, const FName& Category) const {
    return FTraitInfo{};
}

int32 URemnantTraitsComponent::GetTotalAvailableTraits() const {
    return 0;
}

int32 URemnantTraitsComponent::GetNumAvailableTraits() const {
    return 0;
}

void URemnantTraitsComponent::ClientTraitPointTimeOut() {
}

void URemnantTraitsComponent::ClientTraitLevelTimeOut() {
}

void URemnantTraitsComponent::ClientSpentTraitPointTimeOut() {
}

URemnantTraitsComponent::URemnantTraitsComponent() {
    this->bFailAddIfTraitMaxLevel = true;
    this->ValidTraitType = NULL;
    this->MaxTraitPointIncrement = 20;
}

