#include "RemnantQuestManager.h"

class ARemnantQuest;
class AActor;
class UQuestObjective;

TArray<FRemnantQuestEntry> URemnantQuestManager::SortQuestList(const TArray<FRemnantQuestEntry>& QuestList) {
    return TArray<FRemnantQuestEntry>();
}

bool URemnantQuestManager::IsQuestValid(ARemnantQuest* Quest, AActor* Actor) {
    return false;
}

TArray<ARemnantQuest*> URemnantQuestManager::GetRootQuests() {
    return TArray<ARemnantQuest*>();
}

ARemnantQuest* URemnantQuestManager::GetRootQuestForSlot(int32 SlotID) {
    return NULL;
}

TArray<FRemnantQuestEntry> URemnantQuestManager::GetRegisteredRootQuestsForMode(EQuestMode Mode) {
    return TArray<FRemnantQuestEntry>();
}

TArray<FRemnantQuestEntry> URemnantQuestManager::GetRegisteredRootQuests() {
    return TArray<FRemnantQuestEntry>();
}

TArray<FRemnantQuestEntry> URemnantQuestManager::GetRegisteredQuests() {
    return TArray<FRemnantQuestEntry>();
}

FRemnantQuestEntry URemnantQuestManager::GetRegisteredQuestByID(const FString& QuestID) {
    return FRemnantQuestEntry{};
}

void URemnantQuestManager::GetQuestsForActor(AActor* Actor, bool IncludeInjectedQuests, TArray<ARemnantQuest*>& Rtn) {
}

bool URemnantQuestManager::GetLicenseForSoftQuest(TSoftClassPtr<ARemnantQuest> Quest, ELicensedContent& OutLicense) {
    return false;
}

UQuestObjective* URemnantQuestManager::GetCurrentQuestObjective(ARemnantQuest* Quest) {
    return NULL;
}

ARemnantQuest* URemnantQuestManager::GetActiveRootQuest() {
    return NULL;
}

void URemnantQuestManager::DestroyRootQuest(ARemnantQuest* Quest) {
}

ARemnantQuest* URemnantQuestManager::CreateRootQuest(int32 SlotID, const FString& QuestID, int32 Difficulty) {
    return NULL;
}

void URemnantQuestManager::ActivateRootQuest(ARemnantQuest* Quest) {
}

URemnantQuestManager::URemnantQuestManager() {
}

