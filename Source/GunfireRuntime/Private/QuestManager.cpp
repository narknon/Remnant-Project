#include "QuestManager.h"
#include "Templates/SubclassOf.h"

class UEventTreeComponent;
class ULevel;
class UObject;
class AQuest;
class UQuestManager;

void UQuestManager::SetupQuestVariables(UEventTreeComponent* EventTreeComponent) {
}

void UQuestManager::NotifyQuestsUpdated() {
}

bool UQuestManager::NotifyQuestByName(UObject* WorldContextObject, FName QuestNameID, FName EventName) {
    return false;
}

AQuest* UQuestManager::GetQuestByType(TSubclassOf<AQuest> QuestBP) {
    return NULL;
}

UQuestManager* UQuestManager::GetInstance(UObject* WorldContextObject) {
    return NULL;
}

TArray<AQuest*> UQuestManager::FindQuestsInLevel(ULevel* Level) {
    return TArray<AQuest*>();
}

AQuest* UQuestManager::FindQuestByNameID(FName QuestNameID) {
    return NULL;
}

AQuest* UQuestManager::FindQuestByID(int32 ID) {
    return NULL;
}

void UQuestManager::DestroyQuest(AQuest* Quest) {
}

AQuest* UQuestManager::AddQuest(TSubclassOf<AQuest> QuestBP, int32 SeedOverride) {
    return NULL;
}

UQuestManager::UQuestManager() {
    this->QuestIDGen = 0;
}

