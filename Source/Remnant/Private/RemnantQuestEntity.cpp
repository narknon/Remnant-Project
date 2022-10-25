#include "RemnantQuestEntity.h"
#include "Templates/SubclassOf.h"

class ARemnantQuest;
class UFaction;
class AActor;
class ACharacterGunfire;
class URemnantQuestZone;
class AZoneActor;
class URemnantQuestTile;

void URemnantQuestEntity::ZoneUnloaded() {
}

void URemnantQuestEntity::SetFactionAffiliation(TSubclassOf<UFaction> TargetFaction, EAffiliation Affiliation, bool Propogate) {
}

void URemnantQuestEntity::SetFaction(TSubclassOf<UFaction> NewFaction) {
}

void URemnantQuestEntity::ResetSpawns() {
}

void URemnantQuestEntity::ReactivateSpawns() {
}

void URemnantQuestEntity::OnSpawnListLoaded() {
}

void URemnantQuestEntity::OnDead(uint8 Reason, ACharacterGunfire* Character, AActor* Cause) {
}

void URemnantQuestEntity::OnActorRegistered(AActor* Actor) {
}

void URemnantQuestEntity::OnActorDestroyed(AActor* Actor) {
}

void URemnantQuestEntity::OnActorDead(const FDamageInfo& DamageInfo) {
}

AZoneActor* URemnantQuestEntity::GetZone() {
    return NULL;
}

ARemnantQuest* URemnantQuestEntity::GetRootQuest() {
    return NULL;
}

ARemnantQuest* URemnantQuestEntity::GetRemnantQuest() {
    return NULL;
}

URemnantQuestZone* URemnantQuestEntity::GetQuestZone() {
    return NULL;
}

URemnantQuestTile* URemnantQuestEntity::GetQuestTile() {
    return NULL;
}

int32 URemnantQuestEntity::GetNumSpawns() {
    return 0;
}

TArray<AActor*> URemnantQuestEntity::GetActors() {
    return TArray<AActor*>();
}

URemnantQuestEntity::URemnantQuestEntity() {
    this->SpawnTable = NULL;
    this->Transient = false;
    this->ForceSpawnIfNotFound = false;
    this->HackGenerateSpawnsIfMissing = false;
    this->PersistDestroyed = true;
    this->LootSpawnTable = NULL;
    this->Faction = NULL;
}

