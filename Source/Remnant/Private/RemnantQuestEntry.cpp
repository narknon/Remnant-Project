#include "RemnantQuestEntry.h"

FRemnantQuestEntry::FRemnantQuestEntry() {
    this->Type = ERemnantQuestType::Default;
    this->Rarity = ERemnantQuestRarity::Common;
    this->MaxUsageCount = 0;
    this->DebugState = ERemnantQuestDebugState::None;
    this->RequiredLicense = ELicensedContent::PreOrderGladiator;
    this->QuestGameMode = EQuestMode::Campaign;
}

