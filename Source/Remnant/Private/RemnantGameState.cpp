#include "RemnantGameState.h"
#include "Net/UnrealNetwork.h"
#include "RemnantSpawnFilterManager.h"

class UObject;
class ACheckpoint;
class AActor;

void ARemnantGameState::OnRep_ZoneTravelState() {
}

void ARemnantGameState::OnRep_ActivatedCheckpoint() {
}

bool ARemnantGameState::IsZoneTravelPending(const UObject* WorldContextObject, float& OutTimeRemaining) {
    return false;
}

bool ARemnantGameState::IsZoneTravelAvailable(const UObject* WorldContextObject, EZoneTravelLock& OutReason, AActor* Source, bool bIsTravelMenu, float AdditionalDistance) {
    return false;
}

ACheckpoint* ARemnantGameState::GetActivatedCheckpoint(const UObject* WorldContextObject, bool bIncludeDeactivatingCheckpoint) {
    return NULL;
}

void ARemnantGameState::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARemnantGameState, bTestMap);
    DOREPLIFETIME(ARemnantGameState, PingManager);
    DOREPLIFETIME(ARemnantGameState, ZoneTravelState);
    DOREPLIFETIME(ARemnantGameState, ActivatedCheckpoint);
}

ARemnantGameState::ARemnantGameState() {
    this->bTestMap = false;
    this->TravelCountdownAdditionalDistance = 200.00f;
    this->PingManager = NULL;
    this->PingManagerType = NULL;
    this->SpawnFilterManager = CreateDefaultSubobject<URemnantSpawnFilterManager>(TEXT("SpawnFilterManager"));
    this->ActivatedCheckpoint = NULL;
    this->DeactivatingCheckpoint = NULL;
    this->PreviouslyActivatingCheckpoint = NULL;
    this->TravelCountdownSource = NULL;
}

