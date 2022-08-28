#include "AudioFXNode.h"

UAudioFXNode::UAudioFXNode() {
    this->Sound = NULL;
    this->Attached = false;
    this->VolumeMultiplier = 1.00f;
    this->PitchMultiplier = 1.00f;
}

