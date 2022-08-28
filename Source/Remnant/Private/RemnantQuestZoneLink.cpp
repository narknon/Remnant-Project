#include "RemnantQuestZoneLink.h"

class AZoneActor;

void URemnantQuestZoneLink::MulticastSetLinkActive_Implementation(AZoneActor* Zone, bool Active) {
}

void URemnantQuestZoneLink::MapLoaded() {
}

void URemnantQuestZoneLink::DestinationZoneLoaded() {
}

void URemnantQuestZoneLink::DestinationMapLoaded() {
}

void URemnantQuestZoneLink::DeactivateWaypoint() {
}

void URemnantQuestZoneLink::ActivateWaypoint(bool SetAsRespawnPoint) {
}

URemnantQuestZoneLink::URemnantQuestZoneLink() {
    this->Type = EZoneLinkType::Link;
    this->StartsActive = false;
    this->DefaultWaypointSpawnTag = TEXT("Waypoint");
    this->WaypointBP = NULL;
    this->OwnsLink = true;
}

