#include "QuestEntity.h"

class UEventTree;
class AQuest;
class AActor;

void UQuestEntity::StartEventTree(UEventTree* NewEventTree) {
}

bool UQuestEntity::IsSpawned() const {
    return false;
}

bool UQuestEntity::HasEventTree(FName NameID) const {
    return false;
}

AQuest* UQuestEntity::GetQuest() const {
    return NULL;
}

UEventTree* UQuestEntity::GetEventTreeByID(FName NameID) const {
    return NULL;
}

AActor* UQuestEntity::GetActor() const {
    return NULL;
}

void UQuestEntity::EndDialog() {
}

void UQuestEntity::DialogTrigger(FName TriggerName, AActor* Initiator, bool Push, bool AllowOverrideExistingStack) {
}

void UQuestEntity::BeginDialog(AActor* Initiator) {
}

UQuestEntity::UQuestEntity() {
    this->EventTree = NULL;
    this->OwnerContext = EQuestEntityOwnerContext::Quest;
}

