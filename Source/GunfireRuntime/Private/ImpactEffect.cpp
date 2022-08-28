#include "ImpactEffect.h"

AImpactEffect::AImpactEffect() {
    this->OverrideSurfaceType = false;
    this->SurfaceTypeOverride = SurfaceType_Default;
    this->SoundVolume = 1.00f;
    this->ParentSkeletalMesh = NULL;
    this->SortPriority = -1;
    this->AutomaticallySetLifespan = true;
    this->SoundOwner = NULL;
}

