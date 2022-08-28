#include "EncounterGroup.h"

FEncounterGroup::FEncounterGroup() {
    this->WarmupTime = 0.00f;
    this->CooldownMin = 0.00f;
    this->CooldownMax = 0.00f;
    this->AggroCooldownMin = 0.00f;
    this->AggroCooldownMax = 0.00f;
    this->Target = NULL;
    this->SpawnTable = NULL;
    this->MaxEncounters = 0;
    this->RequireAggro = false;
    this->UseIntensity = false;
    this->PerpetualSpawns = false;
    this->EnableSpawnNotifications = false;
    this->DisableWhenFullyExplored = false;
    this->IgnoreAllowSpawnsFlag = false;
    this->MinRating = 0;
    this->MaxRating = 0;
    this->Stopped = false;
}

