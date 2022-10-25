#include "RemnantGameMode.h"

class AActor;
class ACheckpoint;

void ARemnantGameMode::TravelToZone(int32 DestZoneID, const FName& DestLink, AActor* Source, bool bForce, bool bInstant) {
}

void ARemnantGameMode::TravelToLastCheckpoint(AActor* Source) {
}

void ARemnantGameMode::SetPostDeathScreenTime(float Time) {
}

bool ARemnantGameMode::SetAsRootCheckpoint(const FZoneLinkInfo& NewZoneLink, bool IgnoreActive) {
    return false;
}

bool ARemnantGameMode::SetAsRespawnZoneLink(const FZoneLinkInfo& NewZoneLink, bool bIgnoreWorldState) {
    return false;
}

void ARemnantGameMode::OnFullGameAvailable() {
}

bool ARemnantGameMode::IsEveryoneEntitled(ELicensedContent License, bool ShowFailDialog, bool KickUnentitled) {
    return false;
}

void ARemnantGameMode::IncrementAllPlayersBossCounters() {
}

FZoneLinkInfo ARemnantGameMode::GetRespawnZoneLink() const {
    return FZoneLinkInfo{};
}

void ARemnantGameMode::ActivateCheckpoint(ACheckpoint* Checkpoint) {
}

ARemnantGameMode::ARemnantGameMode() {
    this->BaseQuest = NULL;
    this->AutoLoadQuest = NULL;
    this->DemoQuest = NULL;
    this->DebugQuest = NULL;
    this->DebugTileName = TEXT("POI");
    this->DebugWaypointBP = NULL;
    this->DebugTileset = NULL;
    this->DebugQuestInstance = NULL;
    this->FailResetDelay = 5.00f;
    this->MaxFailResetDelay = 20.00f;
    this->ZoneTravelDelay = 5.00f;
}

