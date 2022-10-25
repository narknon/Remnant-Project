#include "QuestTrigger.h"

class ATriggerVolume;
class ARemnantCharacter;

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

