#include "RemnantQuestComponent.h"

class URemnantQuestTile;
class URemnantQuestZone;
class AZoneActor;
class APlayerController;
class ARemnantQuest;
class URemnantQuestEntity;

bool URemnantQuestComponent::IsZoneLoaded() {
    return false;
}

AZoneActor* URemnantQuestComponent::GetZone() {
    return NULL;
}

FName URemnantQuestComponent::GetUniqueName() {
    return NAME_None;
}

ARemnantQuest* URemnantQuestComponent::GetRootQuest() {
    return NULL;
}

ARemnantQuest* URemnantQuestComponent::GetRemnantQuest() {
    return NULL;
}

URemnantQuestZone* URemnantQuestComponent::GetQuestZone() {
    return NULL;
}

URemnantQuestTile* URemnantQuestComponent::GetQuestTile() {
    return NULL;
}

URemnantQuestEntity* URemnantQuestComponent::GetQuestEntity() {
    return NULL;
}

void URemnantQuestComponent::DebugTravelTo(APlayerController* Player) {
}

bool URemnantQuestComponent::DebugCanTravelTo() {
    return false;
}

URemnantQuestComponent::URemnantQuestComponent() {
}

