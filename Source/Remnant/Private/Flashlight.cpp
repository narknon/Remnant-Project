#include "Flashlight.h"

class AActor;

void AFlashlight::ServerToggleFlashlight_Implementation() {
}
bool AFlashlight::ServerToggleFlashlight_Validate() {
    return true;
}





void AFlashlight::LightEndOverlap(AActor* Actor) {
}

void AFlashlight::LightBeginOverlap(AActor* Actor) {
}

void AFlashlight::ApplyChargeDelta(float Delta) {
}

AFlashlight::AFlashlight() {
    this->On = false;
    this->FlashThreshold = 0.10f;
    this->ChargeTimeMin = 2.00f;
}

