#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "DamageInfo.h"
#include "UIHudComponent.h"
#include "EDisabledWeaponVisuals.h"
#include "UObject/NoExportTypes.h"
#include "UIHudReticuleComponent.generated.h"

class ARangedWeapon;
class UItemType;
class UReticule;
class ACharacterGunfire;
class AMeleeWeapon;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UUIHudReticuleComponent : public UUIHudComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> WeaponType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> MeleeWeaponType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UReticule* DefaultReticule;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor HitColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor HitCriticalColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpreadBlendRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EDisabledWeaponVisuals DisabledWeaponVisuals;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor DisabledColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLimitToAimAssistRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GhostReticuleSmoothingRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxGhostReticuleOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CenterToGhostReticuleTolerance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AllowGhostReticuleOnCharacters;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacterGunfire* CachedCharacter;
    
public:
    UUIHudReticuleComponent();
protected:
    UFUNCTION(BlueprintCallable)
    void OnNotifyHitTarget(const FDamageInfo& DamageInfo);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARangedWeapon* GetRangedWeapon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AMeleeWeapon* GetMeleeWeapon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHitAlpha() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentSpread() const;
    
};

