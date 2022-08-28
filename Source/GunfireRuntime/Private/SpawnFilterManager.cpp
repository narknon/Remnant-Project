#include "SpawnFilterManager.h"

class UObject;
class USpawnFilter;
class USpawnFilterManager;

void USpawnFilterManager::SetSpawnFilter(const UObject* WorldContextObject, USpawnFilter* SpawnFilter) {
}

void USpawnFilterManager::RemoveSpawnFilter(const UObject* WorldContextObject, USpawnFilter* SpawnFilter) {
}

USpawnFilterManager* USpawnFilterManager::GetInstance(const UObject* WorldContextObject) {
    return NULL;
}

void USpawnFilterManager::ClearAllSpawnFilters(const UObject* WorldContextObject) {
}

USpawnFilterManager::USpawnFilterManager() {
}

