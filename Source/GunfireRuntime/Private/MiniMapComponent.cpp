#include "MiniMapComponent.h"

class ACharacterGunfire;
class AActor;

void UMiniMapComponent::UpdateMiniMapLevel() {
}

void UMiniMapComponent::TryAutoAddToMiniMap() {
}

void UMiniMapComponent::SetMiniMapLevel(int32 NewLevel) {
}

void UMiniMapComponent::RemoveFromMiniMap() {
}

void UMiniMapComponent::OnDead(uint8 Reason, ACharacterGunfire* Character, AActor* Cause) {
}

bool UMiniMapComponent::IsAddedToMiniMap() {
    return false;
}

void UMiniMapComponent::AutoAddToMiniMap_Implementation() {
}

void UMiniMapComponent::AddToMiniMap(AActor* MiniMapRefActor) {
}

UMiniMapComponent::UMiniMapComponent() {
    this->Type = EMiniMapActorType::Default;
    this->ActorClass = NULL;
    this->WidgetClass = NULL;
    this->AutoAdd = false;
    this->AutoAddRetryInterval = 0.00f;
    this->AbsoluteScale = false;
    this->Scale = 1.00f;
    this->MiniMapManager = NULL;
    this->bAutoUpdateLevel = false;
    this->LevelUpdateAdditionalZ = 0.00f;
    this->MiniMapLevel = 0;
}

