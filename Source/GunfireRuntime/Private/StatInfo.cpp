#include "StatInfo.h"

FStatInfo::FStatInfo() {
    this->Icon = NULL;
    this->Type = EInspectStatType::Standard;
    this->Primary = false;
    this->Hidden = false;
    this->Modifier = false;
    this->ForceInspect = false;
    this->ApplyMod = false;
    this->Range = 0.00f;
}

