#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Equipment.h"
#include "DamageSourceInterface.h"
#include "WeaponBase.generated.h"

class UDamageTypeGunfire;
class AImpactEffect;
class AActor;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AWeaponBase : public AEquipment, public IDamageSourceInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UDamageTypeGunfire> DamageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AImpactEffect> ImpactEffect;
    
    AWeaponBase();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetProcChance() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    TSubclassOf<AImpactEffect> GetImpactEffect();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetAttackSpeed();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void ComputeDamage(AActor* Actor, float& Damage, float& AttackRating);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AttemptProc(float BonusChance) const;
    
    
    // Fix for true pure virtual functions not being implemented
};

