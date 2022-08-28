#include "FogOfWarComponent.h"

void UFogOfWarComponent::ToggeleFogOfWar() {
}

void UFogOfWarComponent::ShowVisitedCoordinates() {
}

void UFogOfWarComponent::SetFogOfWar(bool bHasFog) {
}

void UFogOfWarComponent::Init(FBox RelevantWorldBounds) {
}

bool UFogOfWarComponent::HasFogOfWar() const {
    return false;
}

float UFogOfWarComponent::GetWorldMaxDimension() const {
    return 0.0f;
}

FBox UFogOfWarComponent::GetWorldBounds() const {
    return FBox{};
}

float UFogOfWarComponent::GetVisibilityAtLocation(FVector WorldLocation) const {
    return 0.0f;
}

FVector UFogOfWarComponent::GetLocationAtCoordinate(FVisibleCoordinate Coordinate) const {
    return FVector{};
}

void UFogOfWarComponent::AddVisibleLocation(FVector Location) {
}

UFogOfWarComponent::UFogOfWarComponent() {
    this->VisibilityRadius = 500.00f;
    this->MiniMapDimension = 1024;
    this->bLockChanges = false;
    this->MatInst = NULL;
    this->FogOfWarMaskTexture = NULL;
    this->OwningCharacter = NULL;
}

