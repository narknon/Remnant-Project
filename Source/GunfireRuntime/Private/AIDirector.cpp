#include "AIDirector.h"

class UEncounterGroupInstance;
class AActor;
class UEncounterInstance;

void UAIDirector::Suspend() {
}

void UAIDirector::StopEncounterGroup(UEncounterGroupInstance* EncounterGroup, bool DestroyActiveSpawns) {
}

UEncounterGroupInstance* UAIDirector::StartEncounterGroup(const FEncounterGroup& Group) {
    return NULL;
}

void UAIDirector::Resume() {
}

void UAIDirector::OnNotifyHit(const FDamageInfo& DamageInfo) {
}

void UAIDirector::OnEncounterEvent(UEncounterInstance* Encounter, FName EventName) {
}

void UAIDirector::OnActorSpawned(UEncounterInstance* Encounter, AActor* Actor) {
}

void UAIDirector::OnActorDead(UEncounterInstance* Encounter, AActor* Actor) {
}

bool UAIDirector::HasActiveSpawns() {
    return false;
}

int32 UAIDirector::GetAIDirectorDebugState() {
    return 0;
}

void UAIDirector::ClearAllGroups(bool DestroyActiveSpawns) {
}

UAIDirector::UAIDirector() {
    this->Level = 1;
    this->Suspended = false;
    this->IntensityState = EIntensityState::BuildUp;
    this->IntensityTimer = 0.00f;
    this->IntensityMax = 0.00f;
}

