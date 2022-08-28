#include "AnimNotify_PlaySoundSetSound.h"

UAnimNotify_PlaySoundSetSound::UAnimNotify_PlaySoundSetSound() {
    this->bStateTransient = false;
    this->bFilterDuringCinematics = true;
    this->EquipmentType = NULL;
    this->bUseMainMesh = false;
    this->EquipmentSocketIndex = -1;
    this->VolumeMultiplier = 1.00f;
    this->PitchMultiplier = 1.00f;
    this->bAttach = false;
}

