#include "PhysicsImpactSoundInfo.h"

FPhysicsImpactSoundInfo::FPhysicsImpactSoundInfo() {
    this->FoleySound = NULL;
    this->RollingSound = NULL;
    this->VelocityVolumeCurve = NULL;
    this->PitchVelocityCurve = NULL;
    this->StopSoundManually = false;
    this->VelocityDurationCurve = NULL;
    this->MaxDistance = 0.00f;
    this->FoleySoundThreshold = 0.00f;
    this->RollingSoundThreshold = 0.00f;
}

