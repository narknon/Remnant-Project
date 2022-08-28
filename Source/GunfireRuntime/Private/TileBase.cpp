#include "TileBase.h"

FTileBase::FTileBase() {
    this->_ID = 0;
    this->Edges = 0;
    this->Direction = ETileDirection::None;
    this->TileRotation = 0.00f;
    this->TileRating = 0;
    this->TileSeed = 0;
    this->Flags = 0;
    this->Overlay = false;
}

