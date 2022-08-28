#include "MapTileTemplate.h"

AMapTileTemplate::AMapTileTemplate() {
    this->TileRating = -1;
    this->Overlay = false;
    this->TileFlags = 255;
    this->Optional = false;
    this->North = false;
    this->East = false;
    this->South = false;
    this->West = false;
    this->NorthEast = false;
    this->SouthEast = false;
    this->SouthWest = false;
    this->NorthWest = false;
    this->Direction = ETileDirection::None;
    this->TileSet = NULL;
}

