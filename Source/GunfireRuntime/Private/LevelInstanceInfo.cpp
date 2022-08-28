#include "LevelInstanceInfo.h"

FLevelInstanceInfo::FLevelInstanceInfo() {
    this->ID = 0;
    this->bBlockOnLoad = false;
    this->bShouldBeLoaded = false;
    this->bShouldBeVisible = false;
    this->bShouldLoadChildLevels = false;
}

