#include "RemnantUIActor.h"

ARemnantUIActor::ARemnantUIActor() {
    this->TravelLock = EDialogTravelLock::None;
    this->bAllowedDuringTravel = false;
}

