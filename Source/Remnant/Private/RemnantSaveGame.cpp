#include "RemnantSaveGame.h"

URemnantSaveGame::URemnantSaveGame() {
    this->NewGame = true;
    this->HasMainCampaign = false;
    this->LastActiveRootSlot = -1;
    this->ZoneIDGen = 1;
    this->QuestIDGen = 1;
}

