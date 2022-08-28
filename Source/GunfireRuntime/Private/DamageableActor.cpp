#include "DamageableActor.h"
#include "Net/UnrealNetwork.h"

void ADamageableActor::UpdateVisualState(FName TransitionTag) {
}

void ADamageableActor::SetHealth(float NewHealth) {
}

void ADamageableActor::PostComputeStats() {
}

void ADamageableActor::OnRep_Health() {
}



bool ADamageableActor::IsAlive() const {
    return false;
}

int32 ADamageableActor::GetNumDamageStates() const {
    return 0;
}

float ADamageableActor::GetHealthPercentage() const {
    return 0.0f;
}

float ADamageableActor::GetHealthMax() const {
    return 0.0f;
}

float ADamageableActor::GetHealth() const {
    return 0.0f;
}

int32 ADamageableActor::GetDamageState() const {
    return 0;
}

void ADamageableActor::DifficultyChanged() {
}

void ADamageableActor::ComputeStats() {
}

void ADamageableActor::ApplyHealthDelta(float Delta) {
}

void ADamageableActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ADamageableActor, Faction);
    DOREPLIFETIME(ADamageableActor, DamageableLevel);
    DOREPLIFETIME(ADamageableActor, Health);
}

ADamageableActor::ADamageableActor() {
    this->ImpulseRadius = 100.00f;
    this->ImpulseStrength = 5000.00f;
    this->Invincible = false;
    this->InvincibleMethod = EInvincibleHandlingMethod::DamageFails;
    this->BeginNetDormant = false;
    this->HealthMax = 100.00f;
    this->Faction = NULL;
    this->DisablePersistence = false;
    this->UseLevelScaling = false;
    this->DamageableLevel = 1;
    this->Health = -1.00f;
    this->DamageState = 0;
    this->AimTargetComponent = NULL;
    this->DamageStats = NULL;
}

