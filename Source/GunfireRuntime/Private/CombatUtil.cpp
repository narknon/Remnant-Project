#include "CombatUtil.h"
#include "Templates/SubclassOf.h"

class AActor;
class AImpactEffect;
class UObject;
class UDamageTypeGunfire;
class ACharacter;
class UDamageType;
class UFaction;
class UDamageClass;
class APawn;
class UCurveFloat;

FHitResult UCombatUtil::WeaponTrace(AActor* Cause, const FVector& StartTrace, const FVector& EndTrace) {
    return FHitResult{};
}

void UCombatUtil::SpawnOverlapImpactEffects(UObject* WorldContextObject, TSubclassOf<AImpactEffect> Effect, FHitResult& Hit, const FTransform& SpawnTransform) {
}

void UCombatUtil::SpawnImpactEffectsFromTrace(AActor* Cause, TSubclassOf<AImpactEffect> ImpactEffect, const FVector& Start, const FVector& End, TEnumAsByte<ECollisionChannel> TraceChannel, AActor* Ignore) {
}

void UCombatUtil::SpawnImpactEffects(AActor* Cause, TSubclassOf<AImpactEffect> ImpactEffect, const FHitResult& Impact, bool UseBodyPhysicsMaterial) {
}

bool UCombatUtil::SpawnImpactEffectProjectile(AActor* Projectile, AActor* HitActor, TSubclassOf<AImpactEffect> ImpactEffect) {
    return false;
}

void UCombatUtil::SpawnImpactEffectAOE(AActor* HitActor, TSubclassOf<AImpactEffect> ImpactEffect, const FVector& AOESourceLocation) {
}

TSubclassOf<UDamageTypeGunfire> UCombatUtil::ResolveDamageType(AActor* Cause, AActor* Owner) {
    return NULL;
}

AActor* UCombatUtil::ResolveDamageOwner(AActor* Cause) {
    return NULL;
}

FVector UCombatUtil::PredictLocation(ACharacter* Querier, ACharacter* Target, float Time, float Offset) {
    return FVector{};
}

bool UCombatUtil::IsFriendly(AActor* Actor1, AActor* Actor2) {
    return false;
}

bool UCombatUtil::IsEnemy(AActor* Actor1, AActor* Actor2) {
    return false;
}

bool UCombatUtil::IsDamageable(AActor* Actor) {
    return false;
}

bool UCombatUtil::IsAlive(AActor* Damageable) {
    return false;
}

bool UCombatUtil::HasDamageClass(TSubclassOf<UDamageType> DamageType, TSubclassOf<UDamageClass> RequiredClass) {
    return false;
}

bool UCombatUtil::GetTargetVector(AActor* Cause, FName SourceSocket, AActor* Target, bool SnapToGround, FVector& Origin, FVector& End) {
    return false;
}

bool UCombatUtil::GetReticuleLocation(APawn* Pawn, float Range, float Radius, FRotator& Direction, FVector& Location) {
    return false;
}

bool UCombatUtil::GetPlayerAimVector(APawn* Cause, float Range, FVector& Origin, FVector& End) {
    return false;
}

TSubclassOf<UFaction> UCombatUtil::GetFaction(const AActor* Actor) {
    return NULL;
}

FVector UCombatUtil::GetEyePos(ACharacter* Character) {
    return FVector{};
}

FVector UCombatUtil::GetChestPos(ACharacter* Character) {
    return FVector{};
}

FVector UCombatUtil::GetBasePos(AActor* Actor) {
    return FVector{};
}

bool UCombatUtil::GetAimVector(AActor* Cause, FName SourceSocket, float Range, FVector& Origin, FVector& End) {
    return false;
}

FVector UCombatUtil::GetAimPos(AActor* Actor, AActor* Target) {
    return FVector{};
}

EAffiliation UCombatUtil::GetAffiliation(const AActor* Actor1, const AActor* Actor2) {
    return EAffiliation::SuperFriendly;
}

void UCombatUtil::FireProjectileAsync(UObject* WorldContextObject, TSubclassOf<AActor> ProjectileBP, const FProjectileParams& Params, EFireOutExec& Exec, FHitResult& HitResult, FLatentActionInfo LatentInfo) {
}

AActor* UCombatUtil::FireProjectile(TSubclassOf<AActor> ProjectileBP, const FProjectileParams& Params) {
    return NULL;
}

FDamageInfo UCombatUtil::CreateDamageInfoFromTarget(AActor* Cause, AActor* Target, float Damage, float DamageMod, float DamageScalar, int32 PowerOverride, TSubclassOf<UDamageTypeGunfire> DamageType) {
    return FDamageInfo{};
}

FDamageInfo UCombatUtil::CreateDamageInfoFromHit(AActor* Cause, const FHitResult& Hit, float Damage, float DamageMod, float DamageScalar, int32 PowerOverride, TSubclassOf<UDamageTypeGunfire> DamageType) {
    return FDamageInfo{};
}

float UCombatUtil::ComputeDamageFalloffFromDistance(float Distance, float InnerRadius, float OuterRadius, float Damage, float DamageMin, UCurveFloat* FalloffCurve) {
    return 0.0f;
}

float UCombatUtil::ComputeDamageFalloff(const FVector& Source, AActor* Target, float InnerRadius, float OuterRadius, float Damage, float DamageMin, UCurveFloat* FalloffCurve) {
    return 0.0f;
}

TArray<FVector> UCombatUtil::ApplyWeaponSpread(AActor* Cause, const FVector& Origin, const FVector& End, int32 SprayCount, float Spread, FRandomStream& RandomStream) {
    return TArray<FVector>();
}

void UCombatUtil::ApplyDamageInfo(UObject* WorldContextObject, FDamageInfo DamageInfo, FDamageInfo& Result) {
}

void UCombatUtil::ApplyDamage(AActor* CauseActor, AActor* TargetActor, float Damage, float DamageMod, float DamageScalar, int32 PowerOverride, TSubclassOf<UDamageTypeGunfire> DamageType) {
}

TArray<FVector> UCombatUtil::ApplyCustomWeaponSpread(AActor* Cause, const FVector& Origin, const FVector& End, int32 SprayCount, float Spread, FRandomStream& RandomStream, FCustomWeaponSpread& CustomSpread) {
    return TArray<FVector>();
}

bool UCombatUtil::AllowsWeakSpots(TSubclassOf<UDamageType> DamageType) {
    return false;
}

bool UCombatUtil::AllowsCriticalHits(TSubclassOf<UDamageType> DamageType) {
    return false;
}

UCombatUtil::UCombatUtil() {
}

