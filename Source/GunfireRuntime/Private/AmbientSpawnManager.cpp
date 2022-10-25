#include "AmbientSpawnManager.h"

class AActor;
class ACharacterGunfire;

void UAmbientSpawnManager::OnUninitialize() {
}

void UAmbientSpawnManager::OnSpawnListLoaded(int32 TileID) {
}

void UAmbientSpawnManager::OnSetTileActive(int32 TileID, bool Active) {
}

void UAmbientSpawnManager::OnGenerateAmbientSpawns() {
}

void UAmbientSpawnManager::OnDead(uint8 Reason, ACharacterGunfire* Character, AActor* Cause) {
}

void UAmbientSpawnManager::OnActorDestroyed(AActor* Actor) {
}

void UAmbientSpawnManager::OnActorDead(const FDamageInfo& DamageInfo) {
}

int32 UAmbientSpawnManager::GetNumActiveActorsOfType(TSoftClassPtr<AActor> ActorBP) {
    return 0;
}

int32 UAmbientSpawnManager::GetActiveCharacterCount() {
    return 0;
}

UAmbientSpawnManager::UAmbientSpawnManager() {
    this->Preload = false;
    this->Generated = false;
}

