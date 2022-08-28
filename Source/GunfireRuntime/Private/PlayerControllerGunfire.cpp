#include "PlayerControllerGunfire.h"
#include "Net/UnrealNetwork.h"
#include "PlayStateComponent.h"

class AActor;
class ULevelSequence;
class APawn;

void APlayerControllerGunfire::SpectateTarget(AActor* Actor) {
}

void APlayerControllerGunfire::SpectatePrevPlayer() {
}

void APlayerControllerGunfire::SpectateNextPlayer() {
}

void APlayerControllerGunfire::SetGameInputEnabled(bool bEnabled) {
}

void APlayerControllerGunfire::ServerUnlockAllTraits_Implementation(int32 StartingLevel) {
}
bool APlayerControllerGunfire::ServerUnlockAllTraits_Validate(int32 StartingLevel) {
    return true;
}

void APlayerControllerGunfire::ServerSpectateTarget_Implementation(AActor* Actor) {
}
bool APlayerControllerGunfire::ServerSpectateTarget_Validate(AActor* Actor) {
    return true;
}

void APlayerControllerGunfire::ServerRequestTime_Implementation(uint16 ClientTime) {
}
bool APlayerControllerGunfire::ServerRequestTime_Validate(uint16 ClientTime) {
    return true;
}

void APlayerControllerGunfire::ServerOnLevelTransition_Implementation(int32 LevelID, ELevelTransition TransitionType) {
}
bool APlayerControllerGunfire::ServerOnLevelTransition_Validate(int32 LevelID, ELevelTransition TransitionType) {
    return true;
}

void APlayerControllerGunfire::ServerDropItem_Implementation(const FString& NameOfBP, int32 Quantity, int32 LevelOverride, int32 Stacks) {
}
bool APlayerControllerGunfire::ServerDropItem_Validate(const FString& NameOfBP, int32 Quantity, int32 LevelOverride, int32 Stacks) {
    return true;
}

void APlayerControllerGunfire::ServerDoAction_Implementation(const FString& NameOfBP, bool bApplyToTarget) {
}
bool APlayerControllerGunfire::ServerDoAction_Validate(const FString& NameOfBP, bool bApplyToTarget) {
    return true;
}

void APlayerControllerGunfire::ServerBeginSpectate_Implementation() {
}
bool APlayerControllerGunfire::ServerBeginSpectate_Validate() {
    return true;
}

void APlayerControllerGunfire::ServerAddTrait_Implementation(const FString& NameOfBP, int32 Level) {
}
bool APlayerControllerGunfire::ServerAddTrait_Validate(const FString& NameOfBP, int32 Level) {
    return true;
}

void APlayerControllerGunfire::RestoreSpectateViewTarget() {
}

void APlayerControllerGunfire::ResetPauseRefCount() {
}

void APlayerControllerGunfire::RemoveCinematicListener(const FCinematicDelegate& Event) {
}

void APlayerControllerGunfire::QuitGame() {
}

void APlayerControllerGunfire::ProposeToSkipCutscene_Implementation(ULevelSequence* InSequence) {
}
bool APlayerControllerGunfire::ProposeToSkipCutscene_Validate(ULevelSequence* InSequence) {
    return true;
}

void APlayerControllerGunfire::OnRep_SpectateTarget() {
}

void APlayerControllerGunfire::MulticastUnlockAchievement_Implementation(uint8 Idx, uint8 Type, int32 Amount) {
}

bool APlayerControllerGunfire::IsInCinematic() const {
    return false;
}

bool APlayerControllerGunfire::IsGameInputEnabled() const {
    return false;
}

AActor* APlayerControllerGunfire::GetSpectateTarget() {
    return NULL;
}

APawn* APlayerControllerGunfire::GetRelevantViewTarget() {
    return NULL;
}

APawn* APlayerControllerGunfire::GetRelevantPawn() {
    return NULL;
}

FString APlayerControllerGunfire::GetPlayerIdentifier() const {
    return TEXT("");
}

void APlayerControllerGunfire::ClientTimeReply_Implementation(uint16 ServerTime, uint16 ClientTime) {
}

void APlayerControllerGunfire::BeginSpectate() {
}

void APlayerControllerGunfire::BeginPlaying() {
}

void APlayerControllerGunfire::AddCinematicListener(const FCinematicDelegate& Event) {
}

void APlayerControllerGunfire::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(APlayerControllerGunfire, SpectateActor);
}

APlayerControllerGunfire::APlayerControllerGunfire() {
    this->SpectateActor = NULL;
    this->PlayState = CreateDefaultSubobject<UPlayStateComponent>(TEXT("PlayState"));
}

