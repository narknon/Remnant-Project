#include "PlayerStateGunfire.h"

class APawn;
class ACharacterGunfire;

APawn* APlayerStateGunfire::GetPlayerPawn() const {
    return NULL;
}

ACharacterGunfire* APlayerStateGunfire::GetPlayerCharacter() const {
    return NULL;
}

bool APlayerStateGunfire::GetIsTalking() {
    return false;
}

APlayerStateGunfire::APlayerStateGunfire() {
    this->CachedPawn = NULL;
}

