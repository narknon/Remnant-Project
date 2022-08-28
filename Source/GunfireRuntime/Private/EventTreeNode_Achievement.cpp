#include "EventTreeNode_Achievement.h"

UEventTreeNode_Achievement::UEventTreeNode_Achievement() {
    this->Type = EAchievementUpdateType::Increment;
    this->Amount = 1;
}

