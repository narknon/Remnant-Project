#include "QuestTrigger.h"

class ARemnantCharacter;
class ATriggerVolume;

bool AQuestTrigger::IsLocalPlayerInRegion() const {
    return false;
}

ATriggerVolume* AQuestTrigger::GetTriggerVolume() const {
    return NULL;
}

TArray<ARemnantCharacter*> AQuestTrigger::GetCharacters() {
    return TArray<ARemnantCharacter*>();
}

AQuestTrigger::AQuestTrigger() {
    this->TriggerVolume = NULL;
    this->bUseManualCollision = false;
}

