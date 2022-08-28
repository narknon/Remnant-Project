#include "InspectStat.h"

FInspectStat::FInspectStat() {
    this->Icon = NULL;
    this->Type = EInspectStatType::Standard;
    this->Value = 0.00f;
    this->Bonus = 0.00f;
    this->Range = 0.00f;
    this->Primary = false;
    this->Hidden = false;
    this->Modifier = false;
}

