#include "SavedCharacter.h"

void USavedCharacter::SetSkipIntro(bool ShouldSkipIntro) {
}

void USavedCharacter::SetKey(FName Key) {
}

void USavedCharacter::SetCharacterType(ERemnantCharacterType NewCharacterType) {
}

void USavedCharacter::MarkValidExit() {
}

void USavedCharacter::IncrementCounter(FName Counter) {
}

bool USavedCharacter::HasKey(FName Key) {
    return false;
}

int32 USavedCharacter::GetCounter(FName Counter) {
    return 0;
}

bool USavedCharacter::CheckForInvalidExit() {
    return false;
}

USavedCharacter::USavedCharacter() {
    this->Level = 1;
    this->Age = 20;
    this->TraitRank = 0;
    this->HasInitializedArchetype = false;
    this->bFinishedIntro = false;
    this->bSkipIntro = false;
    this->Gender = EGender::Male;
    this->HostType = ELastHostType::FriendsOnly;
    this->ID = 0;
    this->QuestDifficulty = 1;
    this->InitialDifficulty = 1;
    this->PowerLevel = 1;
    this->CharacterType = ERemnantCharacterType::Standard;
    this->bDeceased = false;
    this->BossCount = 0;
    this->bValidExit = true;
    this->InvalidExitCount = 0;
    this->bHasHandledCurrencyAward = false;
}

