#include "AnimNotify_PlaySoundParameter.h"

UAnimNotify_PlaySoundParameter::UAnimNotify_PlaySoundParameter() {
    this->bFilterDuringCinematics = true;
    this->VolumeMultiplier = 1.00f;
    this->PitchMultiplier = 1.00f;
    this->bFollow = false;
    this->Sound = NULL;
}

