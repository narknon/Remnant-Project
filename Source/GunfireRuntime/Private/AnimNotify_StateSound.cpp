#include "AnimNotify_StateSound.h"

UAnimNotify_StateSound::UAnimNotify_StateSound() {
    this->bIsStateTransient = false;
    this->FadeOut = 0.20f;
    this->bFilterDuringCinematics = true;
    this->Sound = NULL;
    this->VolumeMultiplier = 1.00f;
    this->PitchMultiplier = 1.00f;
    this->bAllowLooping = false;
    this->bFollow = false;
    this->bStopWhenAttachedToDestroyed = false;
}

