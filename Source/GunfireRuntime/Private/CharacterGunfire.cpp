#include "CharacterGunfire.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"
#include "StatsComponent.h"
#include "ActionComponent.h"
#include "HitLogComponent.h"
#include "ReplicatedMovementComponent.h"

class UShapeComponent;
class AActor;
class UDamageTypeGunfire;
class UImpactDirection;
class AImpactEffect;
class UFaction;
class UPrimitiveComponent;
class UObject;
class UStateMachineComponent;
class UInventoryComponent;

void ACharacterGunfire::StopWeaponPhantom(UShapeComponent* Shape) {
}

void ACharacterGunfire::StopAllWeaponPhantoms() {
}

void ACharacterGunfire::StartWeaponPhantom(UShapeComponent* Shape, AActor* Cause, TSubclassOf<UDamageTypeGunfire> DamageType, TSubclassOf<UImpactDirection> ImpactDirection, TSubclassOf<AImpactEffect> ImpactEffect, const FName& EffectBone, EEffectSpawnDirection EffectSpawnDirection, FRotator EffectOrientation, float DamageMod, float DamageScalar, bool Blockable, bool Evadable, int32 PowerOverride, float HitCooldown) {
}

void ACharacterGunfire::SortTags() {
}

void ACharacterGunfire::SetWeaponPhantomsSuspended(bool bIsSuspended) {
}

void ACharacterGunfire::SetTarget(AActor* Character) {
}

void ACharacterGunfire::SetIsTargetable(bool Targetable) {
}

void ACharacterGunfire::SetHealth(float Health) {
}

void ACharacterGunfire::SetGlobalCooldown(float Time) {
}

void ACharacterGunfire::SetFaction(TSubclassOf<UFaction> NewFaction) {
}

void ACharacterGunfire::SetCooldown(const FName& Cooldown, float Time) {
}

void ACharacterGunfire::SetAimTarget(AActor* InTarget) {
}

void ACharacterGunfire::ServerSetAimTarget_Implementation(AActor* InTarget) {
}
bool ACharacterGunfire::ServerSetAimTarget_Validate(AActor* InTarget) {
    return true;
}

void ACharacterGunfire::ScaleStat(FName Stat, float Scalar, bool AutoInitValue) {
}

void ACharacterGunfire::RestoreAggroGroup(FName PreviousAggroGroup, bool bRemoveAll) {
}

void ACharacterGunfire::ResetHealth(bool bResetHitLocations) {
}

void ACharacterGunfire::ResetClothingSimulation(bool FullReset) {
}

void ACharacterGunfire::RemoveTag(const FName& Tag, bool bRemoveAll) {
}

void ACharacterGunfire::ReinitializeCloth() {
}

void ACharacterGunfire::Ragdoll(const FName RootBoneName) {
}

void ACharacterGunfire::PostComputeStats() {
}

void ACharacterGunfire::OnRep_Target(AActor* PreviousTarget) {
}

void ACharacterGunfire::OnRep_Health() {
}

void ACharacterGunfire::OnRagdollHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit) {
}



void ACharacterGunfire::OnGameViewportFocusChanged(bool HasFocus) {
}


void ACharacterGunfire::OnCharacterStateChanged(const FName& StateName, const FName& PreviousStateName) {
}

void ACharacterGunfire::OnCharacterDead_Implementation(EDeadReason Reason, AActor* Cause) {
}

void ACharacterGunfire::ModifyStat(FName Stat, float Value) {
}

void ACharacterGunfire::MarkActorHit(UObject* WorldContextObject, UShapeComponent* Shape, AActor* Actor) {
}

bool ACharacterGunfire::IsWounded() const {
    return false;
}

bool ACharacterGunfire::IsEditor() {
    return false;
}

bool ACharacterGunfire::IsCinematicCharacter() {
    return false;
}

bool ACharacterGunfire::IsAlive() const {
    return false;
}

void ACharacterGunfire::HitPause(float Duration, float Dilation, float EaseInTime, float EaseOutTime) {
}

bool ACharacterGunfire::HasRecentlyHitActor(UObject* WorldContextObject, UShapeComponent* Shape, AActor* Actor) const {
    return false;
}

bool ACharacterGunfire::HasAnyOverlappingDamageable(TArray<AActor*> IgnoredActors, bool bIgnoreDeadActors) const {
    return false;
}

FRotator ACharacterGunfire::GetViewRotation() const {
    return FRotator{};
}

AActor* ACharacterGunfire::GetTarget() {
    return NULL;
}

UStateMachineComponent* ACharacterGunfire::GetStateMachine() const {
    return NULL;
}

float ACharacterGunfire::GetStat(FName Stat) {
    return 0.0f;
}

bool ACharacterGunfire::GetIsTargetable() {
    return false;
}

FInspectStat ACharacterGunfire::GetInspectStatInfo(const FName& Stat) {
    return FInspectStat{};
}

FInspectInfo ACharacterGunfire::GetInspectInfo() {
    return FInspectInfo{};
}

float ACharacterGunfire::GetHealthPercentage() const {
    return 0.0f;
}

float ACharacterGunfire::GetHealthMax() const {
    return 0.0f;
}

float ACharacterGunfire::GetHealth() const {
    return 0.0f;
}

float ACharacterGunfire::GetCooldownPct(const FName& Cooldown) {
    return 0.0f;
}

UInventoryComponent* ACharacterGunfire::GetCharacterInventory() const {
    return NULL;
}

AActor* ACharacterGunfire::GetAimTarget() {
    return NULL;
}

FName ACharacterGunfire::GetAggroGroup() {
    return NAME_None;
}

void ACharacterGunfire::EnableClothingSimulation() {
}

void ACharacterGunfire::DisableClothingSimulation() {
}

void ACharacterGunfire::DifficultyChanged() {
}

void ACharacterGunfire::ComputeStats() {
}

void ACharacterGunfire::ClientNotifyTakeDamage_Implementation(AActor* Source, float Damage, int32 Power) {
}

void ACharacterGunfire::ClientNotifyHitTarget_Implementation(AActor* Cause, AActor* InTarget, const FVector& ImpactPoint, float Damage, bool Killed, bool Critical, bool WeakSpot, bool Resisted) {
}

void ACharacterGunfire::ClearAggroGroup() {
}

bool ACharacterGunfire::CheckTags(const TArray<FName>& TagsToCheck, bool AllOrNothing) const {
    return false;
}

bool ACharacterGunfire::CheckTag(FName Tag) const {
    return false;
}

bool ACharacterGunfire::CheckCooldown(const FName& Cooldown) {
    return false;
}

bool ACharacterGunfire::AreWeaponPhantomsSuspended() const {
    return false;
}

bool ACharacterGunfire::AreCharacterOptimizationsEnabled() {
    return false;
}

void ACharacterGunfire::ApplyHealthDelta(float Delta) {
}

void ACharacterGunfire::AddTag(const FName& Tag) {
}

void ACharacterGunfire::AddAggroGroup(FName NewAggroGroup, bool bUniqueOnly) {
}

void ACharacterGunfire::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ACharacterGunfire, Faction);
    DOREPLIFETIME(ACharacterGunfire, Level);
    DOREPLIFETIME(ACharacterGunfire, Seed);
    DOREPLIFETIME(ACharacterGunfire, HealthNormalized);
    DOREPLIFETIME(ACharacterGunfire, Target);
    DOREPLIFETIME(ACharacterGunfire, AimTarget);
}

ACharacterGunfire::ACharacterGunfire() {
    this->StatsComp = CreateDefaultSubobject<UStatsComponent>(TEXT("StatsComp"));
    this->ActionComp = CreateDefaultSubobject<UActionComponent>(TEXT("ActionComp"));
    this->HitLogComp = CreateDefaultSubobject<UHitLogComponent>(TEXT("HitLogComp"));
    this->ReplicatedMovementComp = CreateDefaultSubobject<UReplicatedMovementComponent>(TEXT("ReplicatedMovement"));
    this->InspectStats = NULL;
    this->Faction = NULL;
    this->DefaultDamageType = NULL;
    this->DefaultImpactEffect = NULL;
    this->DefaultBlockEffect = NULL;
    this->FootEffect = NULL;
    this->FootSprintEffect = NULL;
    this->HandEffect = NULL;
    this->HandSprintEffect = NULL;
    this->LandEffect = NULL;
    this->SlamEffect = NULL;
    this->BodyEffect = NULL;
    this->GlobalFootImpactOffset = 0.00f;
    this->ReceiveDecals = EDecalReceiverType::Inherit;
    this->NetNotifyHitTarget = false;
    this->SpawnID = 0;
    this->Level = 1;
    this->Seed = 0;
    this->HealthNormalized = 1000.00f;
    this->EnableCharacterOptimizations = false;
    this->ActivationHalfHeightInflation = 60.00f;
    this->ActivationRadiusInflation = 60.00f;
    this->MinimumTimeDilation = 0.00f;
    this->CachedStateMachine = NULL;
    this->CachedInventory = NULL;
    this->Target = NULL;
    this->CharacterTarget = NULL;
    this->AimTarget = NULL;
    this->bSkipWallChecks = true;
    this->bPauseClothSimulationOnTimeDilation = true;
    this->bResetAnimDynamicsOnResumeClothingSim = false;
    this->ClothSimulationPauseThreshold = 0.05f;
    this->CharacterManager = NULL;
}

