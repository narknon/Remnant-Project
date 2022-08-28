#include "AIShootStateDecorator.h"

UAIShootStateDecorator::UAIShootStateDecorator() {
    this->WeaponType = NULL;
    this->ReadyTime = 0.00f;
    this->ReadyStartEvent = TEXT("OnBeginReadyWeapon");
    this->ReadyLingerTime = 0.00f;
    this->Pressure = 0;
    this->CooldownMin = 0.50f;
    this->CooldownMax = 1.50f;
    this->GlobalCooldown = false;
    this->GlobalCooldownMin = 0.25f;
    this->GlobalCooldownMax = 0.50f;
    this->ShotRequiresLOS = false;
    this->BlindShootDivergeDistance = -1.00f;
    this->ValidateArc = false;
    this->ArcYawMin = -90.00f;
    this->ArcYawMax = 90.00f;
    this->ArcPitchMin = -60.00f;
    this->ArcPitchMax = 80.00f;
}

