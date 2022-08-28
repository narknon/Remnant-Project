#include "MapRegionTemplate.h"

AMapRegionTemplate::AMapRegionTemplate() {
    this->TileWidth = 10;
    this->TileHeight = 10;
    this->Maziness = 2;
    this->PathIterations = 2;
    this->NumTilesMin = 1;
    this->NumTilesMax = 100;
    this->TileSet = NULL;
}

