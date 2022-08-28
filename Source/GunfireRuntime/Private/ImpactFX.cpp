#include "ImpactFX.h"

FImpactFX::FImpactFX() {
    this->SurfaceType = SurfaceType_Default;
    this->ImpactFX = NULL;
    this->ImpactSound = NULL;
    this->DecalMaterial = NULL;
    this->DecalSize = 0.00f;
    this->DecalDepth = 0.00f;
    this->DecalLifeSpan = 0.00f;
    this->DecalFadeScreenSize = 0.00f;
    this->DecalRandomizeRotation = false;
    this->Reflect = false;
}

