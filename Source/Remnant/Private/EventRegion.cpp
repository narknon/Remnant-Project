#include "EventRegion.h"
#include "Net/UnrealNetwork.h"
#include "PersistenceComponent.h"

class ARemnantCharacter;
class APlayerController;
class AActor;
class ACharacterGunfire;
class AEventRegion;

void AEventRegion::PlayerExit(ARemnantCharacter* Character) {
}

void AEventRegion::PlayerEnter(ARemnantCharacter* Character) {
}

void AEventRegion::OnRep_Players() {
}

void AEventRegion::OnRep_Active() {
}

void AEventRegion::OnDead(uint8 Reason, ACharacterGunfire* Character, AActor* Cause) {
}

void AEventRegion::LockEvent() {
}

bool AEventRegion::IsPlayerInRegion(APlayerController* Controller) const {
    return false;
}

bool AEventRegion::IsLocked() const {
    return false;
}

bool AEventRegion::IsLocalPlayerInRegion() const {
    return false;
}

bool AEventRegion::IsComplete() const {
    return false;
}

bool AEventRegion::IsCharacterInRegion(ARemnantCharacter* Character) const {
    return false;
}

bool AEventRegion::IsActive() const {
    return false;
}

bool AEventRegion::HasLocalPlayerVisited() const {
    return false;
}

ARemnantCharacter* AEventRegion::GetFirstCharacter() {
    return NULL;
}

AEventRegion* AEventRegion::GetEventRegionForActor(AActor* Actor, FName EventRegionNameID) {
    return NULL;
}

AEventRegion* AEventRegion::GetEventRegionContainingActor(AActor* Actor) {
    return NULL;
}

TArray<FEventRegionCharacter> AEventRegion::GetCharacters() {
    return TArray<FEventRegionCharacter>();
}

void AEventRegion::End() {
}

void AEventRegion::CompleteEvent() {
}

void AEventRegion::Begin() {
}

void AEventRegion::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AEventRegion, MusicState);
    DOREPLIFETIME(AEventRegion, Complete);
    DOREPLIFETIME(AEventRegion, Characters);
    DOREPLIFETIME(AEventRegion, Active);
    DOREPLIFETIME(AEventRegion, Locked);
    DOREPLIFETIME(AEventRegion, Players);
}

AEventRegion::AEventRegion() {
    this->PersistenceComponent = CreateDefaultSubobject<UPersistenceComponent>(TEXT("Persistence"));
    this->MusicSet = NULL;
    this->MusicState = TEXT("Ambient");
    this->AutoStartEvent = false;
    this->AutoEndEvent = true;
    this->DisableCommitsWhenActive = true;
    this->StartsActive = false;
    this->Complete = false;
    this->Active = false;
    this->Locked = false;
}

