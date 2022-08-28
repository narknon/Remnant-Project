#include "LevelSequencePossession.h"

FLevelSequencePossession::FLevelSequencePossession() {
    this->Avatar = NULL;
    this->Possessor = NULL;
    this->IsRestricted = false;
    this->CachedTargetability = false;
    this->CachedMovementMode = MOVE_None;
}

