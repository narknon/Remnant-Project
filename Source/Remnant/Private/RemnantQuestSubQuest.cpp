#include "RemnantQuestSubQuest.h"

class AQuest;
class ARemnantQuest;
class UQuestComponent;

void URemnantQuestSubQuest::SubQuestComplete(AQuest* Quest, EQuestResult Result) {
}

void URemnantQuestSubQuest::OnLinkDeactivated(UQuestComponent* Component) {
}

void URemnantQuestSubQuest::OnLinkActivated(UQuestComponent* Component) {
}

ARemnantQuest* URemnantQuestSubQuest::GetSubQuest() {
    return NULL;
}

URemnantQuestSubQuest::URemnantQuestSubQuest() {
    this->QuestType = ERemnantQuestType::Default;
    this->ChanceToSpawn = 100.00f;
    this->LevelMin = 0;
    this->QuestID = -1;
}

