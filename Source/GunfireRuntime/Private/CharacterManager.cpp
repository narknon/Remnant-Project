#include "CharacterManager.h"

class ACharacterGunfire;
class AActor;
class UObject;
class UCharacterManager;

void UCharacterManager::KillAllCharactersForOwner(AActor* Owner) {
}

UCharacterManager* UCharacterManager::GetInstance(const UObject* WorldContextObject) {
    return NULL;
}

TArray<ACharacterGunfire*> UCharacterManager::GetCharactersInAggroGroup(FName AggroGroup) {
    return TArray<ACharacterGunfire*>();
}

TArray<ACharacterGunfire*> UCharacterManager::GetCharactersForOwner(AActor* Owner) {
    return TArray<ACharacterGunfire*>();
}

void UCharacterManager::DestroyAllCharactersForOwner(AActor* Owner) {
}

UCharacterManager::UCharacterManager() {
}

