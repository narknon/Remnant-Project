#include "ZoneLinkInfo.h"

FZoneLinkInfo::FZoneLinkInfo() {
    this->LinkActor = NULL;
    this->ZoneID = 0;
    this->Type = EZoneLinkType::Link;
    this->IsActive = false;
    this->Used = false;
    this->TileID = 0;
}

