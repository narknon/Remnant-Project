#include "HitLocationInfo.h"

FHitLocationInfo::FHitLocationInfo() {
    this->PhysMat = NULL;
    this->bCollisionInitiallyEnabled = false;
    this->DamageScalar = 0.00f;
    this->HealthRatio = 0.00f;
    this->KillOnDestroyed = false;
    this->bResistSpot = false;
    this->bIsWeakSpot = false;
    this->Destroyed = false;
    this->DamageTaken = 0.00f;
}

