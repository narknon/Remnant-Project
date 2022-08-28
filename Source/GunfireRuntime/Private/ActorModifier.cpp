#include "ActorModifier.h"
#include "Net/UnrealNetwork.h"

class AActor;
class ACharacter;

void UActorModifier::SetOwner(AActor* NewOwner) {
}

void UActorModifier::SetLevel(int32 NewLevel) {
}

void UActorModifier::ScaleStat(FName Stat, float Scalar, bool AutoInitValue) {
}

void UActorModifier::PostComputeStats() {
}




void UActorModifier::OnRep_Level() {
}








void UActorModifier::NotifyTakeDamage(const FDamageInfo& DamageInfo) {
}

void UActorModifier::NotifyHitTarget(const FDamageInfo& DamageInfo) {
}

void UActorModifier::ModifyStat(FName Stat, float Value) {
}


void UActorModifier::ModifyDamage_Implementation(FDamageInfo& Info, bool& Rtn) {
}

float UActorModifier::GetStat(FName Stat) {
    return 0.0f;
}

ACharacter* UActorModifier::GetOwningCharacter() const {
    return NULL;
}

AActor* UActorModifier::GetOwner() const {
    return NULL;
}

FInspectInfo UActorModifier::GetInspectInfo(AActor* Actor, int32 InspectLevel) {
    return FInspectInfo{};
}

void UActorModifier::FilterIncomingFallDamage_Implementation(const float& Damage, float& DamageInfoOut, bool& ShouldApplyDamage) {
}

void UActorModifier::FilterIncomingDamage_Implementation(const FDamageInfo& DamageInfo, FDamageInfo& DamageInfoOut, bool& ShouldApplyDamage) {
}

void UActorModifier::ComputeStats() {
}

void UActorModifier::ComputeDerivedStats() {
}

void UActorModifier::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UActorModifier, Level);
}

UActorModifier::UActorModifier() {
    this->Scope = EActorModifierScope::StatsOnly;
    this->Level = 0;
    this->Icon = NULL;
    this->InspectStats = NULL;
    this->Owner = NULL;
    this->StatsComponent = NULL;
}

