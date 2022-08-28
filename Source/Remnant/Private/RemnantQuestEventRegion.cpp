#include "RemnantQuestEventRegion.h"

class AActor;
class ARemnantCharacter;
class AEventRegion;

void URemnantQuestEventRegion::SetMusicState(FName MusicState) {
}

void URemnantQuestEventRegion::OnActorRegistered(AActor* Actor) {
}

void URemnantQuestEventRegion::LockEvent() {
}

bool URemnantQuestEventRegion::IsEventRegionActive() const {
    return false;
}

bool URemnantQuestEventRegion::IsComplete() const {
    return false;
}

TArray<ARemnantCharacter*> URemnantQuestEventRegion::GetPlayersInRegion() {
    return TArray<ARemnantCharacter*>();
}

int32 URemnantQuestEventRegion::GetNumPlayersInRegion() {
    return 0;
}

ARemnantCharacter* URemnantQuestEventRegion::GetFirstPlayerInRegion() {
    return NULL;
}

AEventRegion* URemnantQuestEventRegion::GetEventRegion() {
    return NULL;
}

FName URemnantQuestEventRegion::GetAggroGroup() {
    return NAME_None;
}

void URemnantQuestEventRegion::EventPlayerExit(FEventRegionCharacter Player) {
}

void URemnantQuestEventRegion::EventPlayerEnter(FEventRegionCharacter Player) {
}

void URemnantQuestEventRegion::EventOnEnd() {
}

void URemnantQuestEventRegion::EventOnBegin() {
}

void URemnantQuestEventRegion::End() {
}

void URemnantQuestEventRegion::CompleteEvent() {
}

void URemnantQuestEventRegion::Begin() {
}

URemnantQuestEventRegion::URemnantQuestEventRegion() {
    this->MusicSet = NULL;
    this->bOverrideExistingSet = true;
    this->bApplyAggroGroupToStack = false;
    this->EventRegion = NULL;
}

