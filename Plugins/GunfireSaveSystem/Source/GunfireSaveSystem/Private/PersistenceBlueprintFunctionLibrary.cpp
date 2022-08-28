#include "PersistenceBlueprintFunctionLibrary.h"

class USaveGameProfile;
class UObject;
class AActor;
class USaveGameWorld;
class UPersistenceManager;

void UPersistenceBlueprintFunctionLibrary::SetReference(FPersistentReference& Reference, AActor* InActor) {
}

void UPersistenceBlueprintFunctionLibrary::SetDisableCommit(UObject* WorldContextObject, bool DisableCommit) {
}

AActor* UPersistenceBlueprintFunctionLibrary::GetReference(UObject* WorldContextObject, FPersistentReference& Reference) {
    return NULL;
}

USaveGameProfile* UPersistenceBlueprintFunctionLibrary::GetProfileSave(UObject* WorldContextObject) {
    return NULL;
}

UPersistenceManager* UPersistenceBlueprintFunctionLibrary::GetPersistenceManager(UObject* WorldContextObject) {
    return NULL;
}

USaveGameWorld* UPersistenceBlueprintFunctionLibrary::GetCurrentSave(UObject* WorldContextObject) {
    return NULL;
}

void UPersistenceBlueprintFunctionLibrary::CopyReference(const FPersistentReference& from, FPersistentReference& to) {
}

void UPersistenceBlueprintFunctionLibrary::CommitSave(UObject* WorldContextObject, const FString& Reason) {
}

void UPersistenceBlueprintFunctionLibrary::ClearReference(FPersistentReference& Reference) {
}

UPersistenceBlueprintFunctionLibrary::UPersistenceBlueprintFunctionLibrary() {
}

