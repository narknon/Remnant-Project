#include "RangedWeaponMode.h"

FRangedWeaponMode::FRangedWeaponMode() {
    this->Range = 0.00f;
    this->PrimaryFalloff = 0.00f;
    this->SecondaryFalloff = 0.00f;
    this->MinCritRange = 0.00f;
    this->MaxCritRange = 0.00f;
    this->RateOfFire = 0.00f;
    this->BurstCount = 0.00f;
    this->BurstRateOfFire = 0.00f;
    this->SprayCount = 0.00f;
    this->HasScope = false;
    this->ScopeFOV = 0.00f;
    this->DamageType = NULL;
    this->Profile = NULL;
    this->Reticule = NULL;
    this->ScopeReticule = NULL;
    this->ScopeWidget = NULL;
    this->ScopeInSound = NULL;
    this->ScopeOutSound = NULL;
    this->MinimumAimDelayForScope = 0.00f;
    this->MuzzleFX = NULL;
    this->AllowReload = false;
    this->ReloadAfterStartLoop = false;
    this->TrajectoryMode = ERangedWeaponTrajectoryMode::Socket;
    this->MuzzleObstructionDistance = 0.00f;
    this->ProjectileToVisualize = NULL;
    this->ScopePostProcessReference = NULL;
}

