#include "VisualComponent.h"
#include "Net/UnrealNetwork.h"

class UVisualSetSlot;

void UVisualComponent::UpdateSlots() {
}

void UVisualComponent::StopAllStreamingRequests() {
}

void UVisualComponent::SetVisualAt(FName SlotID, int32 Idx) {
}

void UVisualComponent::SetVisual(FName SlotID, FName VisualID) {
}

void UVisualComponent::SetupSlaveMeshes() {
}

void UVisualComponent::SetSlotEnabled(FName SlotID, bool bIsEnabled) {
}

void UVisualComponent::PlayVisualFX(FName NameID) {
}

void UVisualComponent::OnVisualLoaded(FName SlotID, FName VisualID) {
}

UVisualSetSlot* UVisualComponent::GetVisualSlot(FName SlotID) const {
    return NULL;
}

int32 UVisualComponent::GetVisualPositionInSlot(FName SlotID) {
    return 0;
}

FName UVisualComponent::GetSlotVisualID(FName SlotID) {
    return NAME_None;
}

int32 UVisualComponent::GetNumVisualsForSlotID(FName SlotID) const {
    return 0;
}

void UVisualComponent::ClearVisual(FName SlotID) {
}

void UVisualComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UVisualComponent, Seed);
    DOREPLIFETIME(UVisualComponent, Slots);
}

UVisualComponent::UVisualComponent() {
    this->Seed = 0;
    this->VisualSet = NULL;
}

