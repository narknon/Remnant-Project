#include "FactionManager.h"

class UObject;
class UFactionManager;

UFactionManager* UFactionManager::GetFactionManager(UObject* WorldContextObject) {
    return NULL;
}

UFactionManager::UFactionManager() {
    this->FactionOverridePropogationRadius = 5000.00f;
}

