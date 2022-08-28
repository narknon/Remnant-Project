#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/NoExportTypes.h"
#include "Engine/EngineTypes.h"
#include "UObject/Object.h"
#include "Engine/EngineTypes.h"
#include "UObject/NoExportTypes.h"
#include "Engine/LatentActionManager.h"
#include "DamageInfo.h"
#include "UObject/NoExportTypes.h"
#include "EAffiliation.h"
#include "ProjectileParams.h"
#include "EFireOutExec.h"
#include "UObject/NoExportTypes.h"
#include "CustomWeaponSpread.h"
#include "CombatUtil.generated.h"

class AImpactEffect;
class AActor;
class UDamageTypeGunfire;
class ACharacter;
class UDamageType;
class UFaction;
class UDamageClass;
class APawn;
class UCurveFloat;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UCombatUtil : public UObject {
    GENERATED_BODY()
public:
    UCombatUtil();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FHitResult WeaponTrace(AActor* Cause, const FVector& StartTrace, const FVector& EndTrace);
    
    UFUNCTION(BlueprintCallable)
    static void SpawnOverlapImpactEffects(UObject* WorldContextObject, TSubclassOf<AImpactEffect> Effect, UPARAM(Ref) FHitResult& Hit, const FTransform& SpawnTransform);
    
    UFUNCTION(BlueprintCallable)
    static void SpawnImpactEffectsFromTrace(AActor* Cause, TSubclassOf<AImpactEffect> ImpactEffect, const FVector& Start, const FVector& End, TEnumAsByte<ECollisionChannel> TraceChannel, AActor* Ignore);
    
    UFUNCTION(BlueprintCallable)
    static void SpawnImpactEffects(AActor* Cause, TSubclassOf<AImpactEffect> ImpactEffect, const FHitResult& Impact, bool UseBodyPhysicsMaterial);
    
    UFUNCTION(BlueprintCallable)
    static bool SpawnImpactEffectProjectile(AActor* Projectile, AActor* HitActor, TSubclassOf<AImpactEffect> ImpactEffect);
    
    UFUNCTION(BlueprintCallable)
    static void SpawnImpactEffectAOE(AActor* HitActor, TSubclassOf<AImpactEffect> ImpactEffect, const FVector& AOESourceLocation);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSubclassOf<UDamageTypeGunfire> ResolveDamageType(AActor* Cause, AActor* Owner);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static AActor* ResolveDamageOwner(AActor* Cause);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector PredictLocation(ACharacter* Querier, ACharacter* Target, float Time, float Offset);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsFriendly(AActor* Actor1, AActor* Actor2);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsEnemy(AActor* Actor1, AActor* Actor2);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsDamageable(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsAlive(AActor* Damageable);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasDamageClass(TSubclassOf<UDamageType> DamageType, TSubclassOf<UDamageClass> RequiredClass);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetTargetVector(AActor* Cause, FName SourceSocket, AActor* Target, bool SnapToGround, FVector& Origin, FVector& End);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetReticuleLocation(APawn* Pawn, float Range, float Radius, FRotator& Direction, FVector& Location);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetPlayerAimVector(APawn* Cause, float Range, FVector& Origin, FVector& End);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TSubclassOf<UFaction> GetFaction(const AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetEyePos(ACharacter* Character);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetChestPos(ACharacter* Character);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetBasePos(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetAimVector(AActor* Cause, FName SourceSocket, float Range, FVector& Origin, FVector& End);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FVector GetAimPos(AActor* Actor, AActor* Target);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static EAffiliation GetAffiliation(const AActor* Actor1, const AActor* Actor2);
    
    UFUNCTION(BlueprintCallable)
    static void FireProjectileAsync(UObject* WorldContextObject, TSubclassOf<AActor> ProjectileBP, const FProjectileParams& Params, EFireOutExec& Exec, FHitResult& HitResult, FLatentActionInfo LatentInfo);
    
    UFUNCTION(BlueprintCallable)
    static AActor* FireProjectile(TSubclassOf<AActor> ProjectileBP, const FProjectileParams& Params);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FDamageInfo CreateDamageInfoFromTarget(AActor* Cause, AActor* Target, float Damage, float DamageMod, float DamageScalar, int32 PowerOverride, TSubclassOf<UDamageTypeGunfire> DamageType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FDamageInfo CreateDamageInfoFromHit(AActor* Cause, const FHitResult& Hit, float Damage, float DamageMod, float DamageScalar, int32 PowerOverride, TSubclassOf<UDamageTypeGunfire> DamageType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float ComputeDamageFalloffFromDistance(float Distance, float InnerRadius, float OuterRadius, float Damage, float DamageMin, UCurveFloat* FalloffCurve);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static float ComputeDamageFalloff(const FVector& Source, AActor* Target, float InnerRadius, float OuterRadius, float Damage, float DamageMin, UCurveFloat* FalloffCurve);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FVector> ApplyWeaponSpread(AActor* Cause, const FVector& Origin, const FVector& End, int32 SprayCount, float Spread, UPARAM(Ref) FRandomStream& RandomStream);
    
    UFUNCTION(BlueprintCallable)
    static void ApplyDamageInfo(UObject* WorldContextObject, FDamageInfo DamageInfo, FDamageInfo& Result);
    
    UFUNCTION(BlueprintCallable)
    static void ApplyDamage(AActor* CauseActor, AActor* TargetActor, float Damage, float DamageMod, float DamageScalar, int32 PowerOverride, TSubclassOf<UDamageTypeGunfire> DamageType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static TArray<FVector> ApplyCustomWeaponSpread(AActor* Cause, const FVector& Origin, const FVector& End, int32 SprayCount, float Spread, UPARAM(Ref) FRandomStream& RandomStream, UPARAM(Ref) FCustomWeaponSpread& CustomSpread);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AllowsWeakSpots(TSubclassOf<UDamageType> DamageType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool AllowsCriticalHits(TSubclassOf<UDamageType> DamageType);
    
};

