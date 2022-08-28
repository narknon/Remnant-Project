#include "BreakableComponent.h"

void UBreakableComponent::Reset() {
}

void UBreakableComponent::OnHidePieces() {
}

bool UBreakableComponent::IsUnbroken() const {
    return false;
}

bool UBreakableComponent::IsBroken() const {
    return false;
}

bool UBreakableComponent::IsBreaking() const {
    return false;
}

void UBreakableComponent::Break() {
}

UBreakableComponent::UBreakableComponent() {
    this->BreakDuration = 10.00f;
    this->RandomImpulse = 300.00f;
    this->RandomTorque = 45.00f;
    this->bUnbrokenMeshSupportsCollisionQueries = true;
    this->bPiecesSupportsCollisionQueries = false;
    this->PiecesCollisionProfileName = TEXT("Breakable");
}

