#include "EncounterManager.h"

class AActor;
class USpawnTable;
class UEncounterInstance;

void UEncounterManager::StopEncounter(int32 encounterid) {
}

void UEncounterManager::StopAllEncountersForOwner(AActor* Owner, bool DestroyActiveSpawns) {
}

void UEncounterManager::ResumeEncounter(int32 encounterid) {
}

void UEncounterManager::PauseEncounter(int32 encounterid) {
}

void UEncounterManager::OnSpawnDestroyed(AActor* DestroyedActor) {
}

void UEncounterManager::OnNotifyDead(const FDamageInfo& DamageInfo) {
}

bool UEncounterManager::IsFullyExplored() {
    return false;
}

bool UEncounterManager::IsComplete(int32 encounterid) {
    return false;
}

int32 UEncounterManager::GetNumEncountersForOwner(AActor* Owner) {
    return 0;
}

int32 UEncounterManager::GetFrontTileID() {
    return 0;
}

int32 UEncounterManager::GetCurrentTileID() {
    return 0;
}

int32 UEncounterManager::GetBehindTileID() {
    return 0;
}

UEncounterInstance* UEncounterManager::DoEncounter(USpawnTable* SpawnTable, int32 Level, int32 Rating, const TArray<FName>& Tags, AActor* Target, int32 Flags) {
    return NULL;
}

UEncounterManager::UEncounterManager() {
}

