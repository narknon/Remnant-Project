#include "LevelLoadingManager.h"
#include "Net/UnrealNetwork.h"

void ULevelLoadingManager::OnRep_LevelInstanceInfo() {
}

void ULevelLoadingManager::OnLevelUnloaded(int32 LevelID) {
}

void ULevelLoadingManager::OnLevelShown(int32 LevelID) {
}

void ULevelLoadingManager::OnLevelLoaded(int32 LevelID) {
}

void ULevelLoadingManager::OnLevelHidden(int32 LevelID) {
}

void ULevelLoadingManager::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ULevelLoadingManager, LevelInstanceInfo);
}

ULevelLoadingManager::ULevelLoadingManager() {
}

