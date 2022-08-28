#include "RemnantQuestZone.h"

class USpawnTable;
class APlayerController;

void URemnantQuestZone::ZoneUnloaded() {
}

void URemnantQuestZone::ZoneLoaded() {
}

void URemnantQuestZone::TravelToParent() {
}

void URemnantQuestZone::SetSpawnTableOverride(USpawnTable* SpawnTable) {
}

void URemnantQuestZone::PlayerExitedZone(APlayerController* Controller) {
}

void URemnantQuestZone::PlayerEnteredZone(APlayerController* Controller) {
}

void URemnantQuestZone::ParentMapLoaded() {
}

void URemnantQuestZone::MapLoaded() {
}

URemnantQuestZone::URemnantQuestZone() {
    this->ZoneDef = NULL;
    this->Static = false;
    this->RequestedID = -1;
    this->bForceLevelOffset = false;
    this->TileSet = NULL;
    this->LevelMin = 0;
    this->OwnsZone = true;
    this->ZoneID = -1;
    this->AssetsGathered = false;
}

