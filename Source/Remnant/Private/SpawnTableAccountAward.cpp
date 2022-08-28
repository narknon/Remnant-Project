#include "SpawnTableAccountAward.h"

USpawnTableAccountAward::USpawnTableAccountAward() {
    this->bHardcoreOnly = false;
    this->bFilterByRootQuestMode = false;
    this->bInvertValidQuestMode = false;
    this->ValidQuestMode = EQuestMode::Campaign;
}

