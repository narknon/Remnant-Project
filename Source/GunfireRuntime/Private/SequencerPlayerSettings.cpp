#include "SequencerPlayerSettings.h"

FSequencerPlayerSettings::FSequencerPlayerSettings() {
    this->HideOtherPlayers = false;
    this->ResetNonMVPs = false;
    this->ResetCameraOnComplete = false;
    this->ShowSkipCinematic = false;
    this->DefaultToPlayerCameraOnFinish = false;
    this->InstigatorPawn = NULL;
}

