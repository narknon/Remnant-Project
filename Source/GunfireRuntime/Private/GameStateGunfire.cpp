#include "GameStateGunfire.h"
#include "TimeDilationManager.h"

class UObject;
class AGameStateGunfire;

void AGameStateGunfire::StartMatch() {
}

AGameStateGunfire* AGameStateGunfire::GetGunfireGameState(const UObject* WorldContextObject) {
    return NULL;
}

AGameStateGunfire::AGameStateGunfire() {
    this->TimeDilationManager = CreateDefaultSubobject<UTimeDilationManager>(TEXT("TimeDilatonManager"));
}

