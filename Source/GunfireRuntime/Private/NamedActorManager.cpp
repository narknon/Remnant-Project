#include "NamedActorManager.h"

class AActor;
class UObject;
class UNamedActorManager;

void UNamedActorManager::RemoveActor(const FName& NameID, AActor* Actor) {
}

UNamedActorManager* UNamedActorManager::GetInstance(UObject* WorldContextObject) {
    return NULL;
}

void UNamedActorManager::FindActorsByTags(UObject* WorldContextObject, const TArray<FName>& Tags, TArray<AActor*>& Actors) {
}

AActor* UNamedActorManager::FindActorByName(UObject* WorldContextObject, FName NameID) {
    return NULL;
}

void UNamedActorManager::AddActor(const FName& NameID, AActor* Actor) {
}

UNamedActorManager::UNamedActorManager() {
}

