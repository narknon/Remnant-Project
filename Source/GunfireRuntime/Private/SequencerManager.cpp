#include "SequencerManager.h"

class UEventTreeComponent;
class AActor;
class ULevelSequence;
class UObject;
class APlayerGunfire;
class USequencerManager;

void USequencerManager::UpdateSkipStatus_Implementation(ULevelSequence* InSequence, bool ShouldSkip) {
}

void USequencerManager::SkipSequence_Implementation(ULevelSequence* InSequence) {
}

void USequencerManager::SetupSequence_Client_Implementation(UObject* WorldContextObject, ULevelSequence* LevelSequence, FSequencerPlayerSettings LevelSequenceSettings, AActor* Instigator, UEventTreeComponent* SourceComponent) {
}

void USequencerManager::ProposeToSkip_Implementation(ULevelSequence* InSequence, APlayerGunfire* Player) {
}
bool USequencerManager::ProposeToSkip_Validate(ULevelSequence* InSequence, APlayerGunfire* Player) {
    return true;
}

USequencerManager* USequencerManager::GetInstance(UObject* WorldContextObject) {
    return NULL;
}

USequencerManager::USequencerManager() {
    this->PossessedObjectAction = NULL;
}

