#include "MusicManager.h"

class UMusicSet;
class UObject;
class UMusicManager;

void UMusicManager::SetMusicState(UMusicSet* Set, FName State) {
}

bool UMusicManager::IsMusicSetActive(UMusicSet* Set) {
    return false;
}

UMusicManager* UMusicManager::GetMusicManager(UObject* WorldContextObject) {
    return NULL;
}

void UMusicManager::DeactivateMusicSet(UMusicSet* Set, FName Outro) {
}

void UMusicManager::ActivateMusicSet(UMusicSet* Set, FName InitialState) {
}

UMusicManager::UMusicManager() {
    this->DefaultMusicSet = NULL;
    this->CurrentState = TEXT("Ambient");
}

