#include "ActionBase.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

class UActionComponent;
class AActor;
class UActionBase;
class UDamageTypeGunfire;
class APlayerControllerGunfire;
class UDamageType;

void UActionBase::SetCause(AActor* Cause) {
}

void UActionBase::OnCinematic(APlayerControllerGunfire* Player, bool bIsInCinematicMode) {
}



bool UActionBase::IsActionFinished() const {
    return false;
}

AActor* UActionBase::GetTarget() const {
    return NULL;
}

FHitResult UActionBase::GetHitInfo() const {
    return FHitResult{};
}

TSubclassOf<UDamageType> UActionBase::GetDamageType() const {
    return NULL;
}

AActor* UActionBase::GetCauseOwner() const {
    return NULL;
}

AActor* UActionBase::GetCause() const {
    return NULL;
}

UActionComponent* UActionBase::GetActionComponent() const {
    return NULL;
}

AActor* UActionBase::FireProjectile(AActor* CauseActor, FName SourceSocket, AActor* TargetActor, TSubclassOf<AActor> ProjectileBP, float Speed, bool bOrientTowardsTarget, float AutoArcHeight, float GravityScale) {
    return NULL;
}

void UActionBase::FinishAction() {
}

void UActionBase::DoInstantHit(AActor* CauseActor, FName SourceSocket, float Range, int32 SprayCount, float Spread, TSubclassOf<UDamageTypeGunfire> DamageType, float Damage, float DamageMod, float DamageScalar) {
}

void UActionBase::ApplyDamage(AActor* CauseActor, AActor* TargetActor, float Damage, float DamageMod, float DamageScalar, TSubclassOf<UDamageTypeGunfire> DamageType, FHitResult HitInfo) {
}

bool UActionBase::AllowAction_Implementation(TSubclassOf<UActionBase> ActionBP, const FDamageInfo& InDamageInfo) {
    return false;
}

void UActionBase::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UActionBase, ActionID);
}

UActionBase::UActionBase() {
    this->ActionID = 0;
    this->ApplyOnKilled = false;
    this->bStopOnCinematic = false;
}

