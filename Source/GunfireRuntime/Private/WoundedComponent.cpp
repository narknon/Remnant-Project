#include "WoundedComponent.h"
#include "Net/UnrealNetwork.h"

class ULevelSequence;
class AActor;
class UWoundedComponent;

void UWoundedComponent::StopReviveActor_Implementation() {
}
bool UWoundedComponent::StopReviveActor_Validate() {
    return true;
}

void UWoundedComponent::ServerKillSelf_Implementation() {
}
bool UWoundedComponent::ServerKillSelf_Validate() {
    return true;
}

void UWoundedComponent::ReviveActor_Implementation(AActor* Target) {
}
bool UWoundedComponent::ReviveActor_Validate(AActor* Target) {
    return true;
}

void UWoundedComponent::Revive(float HealthMultiplier, bool SelfRevive) {
}

void UWoundedComponent::OnRep_State() {
}

void UWoundedComponent::OnCinematicPlaying(FSequencerPlayerSettings Settings, ULevelSequence* CurrentSequence, AActor* Instigator) {
}

void UWoundedComponent::MulticastOnWounded_Implementation(const FDamageInfo& Damage) {
}

void UWoundedComponent::MulticastOnTargetRevived_Implementation(UWoundedComponent* WoundedComponent) {
}

void UWoundedComponent::MulticastOnRevived_Implementation(bool bSelfRevive) {
}

void UWoundedComponent::Kill() {
}

float UWoundedComponent::GetWoundedHealthPct() {
    return 0.0f;
}

void UWoundedComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UWoundedComponent, WoundedHealth);
    DOREPLIFETIME(UWoundedComponent, ReviveProgress);
    DOREPLIFETIME(UWoundedComponent, State);
    DOREPLIFETIME(UWoundedComponent, ReviveTarget);
    DOREPLIFETIME(UWoundedComponent, Revivers);
}

UWoundedComponent::UWoundedComponent() {
    this->WoundedHealth = 0.00f;
    this->ReviveProgress = 0.00f;
    this->WoundedHealthMult = 1.00f;
    this->WoundedHealthBleedOutTime = 90.00f;
    this->ReviveHealthMult = 1.00f;
    this->MaxRevivers = 1;
    this->ReviveRange = 200.00f;
    this->ReviveArc = 45.00f;
    this->PauseWoundRegenDuringRevive = false;
    this->ReviveConditions = NULL;
    this->SkipWoundConditions = NULL;
    this->SelfSkipWoundConditions = NULL;
    this->State = EWoundedState::None;
    this->ReviveTarget = NULL;
}

