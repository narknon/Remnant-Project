#include "DialogManager.h"

class UDialogInstance;
class AActor;
class USoundBase;
class UObject;
class UDialogManager;

bool UDialogManager::StopDialog(AActor* Source) {
    return false;
}

bool UDialogManager::StopActiveDialog() {
    return false;
}

UDialogInstance* UDialogManager::PlayDialogFromSound(AActor* Source, TSoftObjectPtr<USoundBase> Dialog) {
    return NULL;
}

UDialogInstance* UDialogManager::PlayDialog(AActor* Source, const FDialogInfo& Info) {
    return NULL;
}

UDialogManager* UDialogManager::GetDialogManager(UObject* WorldContextObject) {
    return NULL;
}

UDialogInstance* UDialogManager::GetActiveDialog(AActor* Source) {
    return NULL;
}

UDialogManager::UDialogManager() {
    this->DialogCullDistance = 3500.00f;
}

