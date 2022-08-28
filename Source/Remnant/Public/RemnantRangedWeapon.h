#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "RangedWeaponVoidDelegateDelegate.h"
#include "RangedWeapon.h"
#include "RangedWeaponPowerDelegateDelegate.h"
#include "RangedWeaponActiveDelegateDelegate.h"
#include "EModActiveState.h"
#include "UObject/NoExportTypes.h"
#include "Engine/NetSerialization.h"
#include "RemnantRangedWeapon.generated.h"

class ARemnantWeaponMod;
class UWeaponAffinityComponent;
class UActionBase;

UCLASS(Blueprintable)
class REMNANT_API ARemnantRangedWeapon : public ARangedWeapon {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ARemnantWeaponMod> DefaultMod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UWeaponAffinityComponent* WeaponAffinity;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AltFireInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Power, meta=(AllowPrivateAccess=true))
    float Power;
    
    UPROPERTY(EditAnywhere, ReplicatedUsing=OnRep_Charges)
    uint8 Charges;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRangedWeaponPowerDelegate OnPowerChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRangedWeaponPowerDelegate OnChargesChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRangedWeaponVoidDelegate OnUseMod;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRangedWeaponVoidDelegate OnUseModFail;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRangedWeaponActiveDelegate OnActivateMod;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ModActive, meta=(AllowPrivateAccess=true))
    EModActiveState ActiveState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    int32 ActiveModActionID;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AdditionalRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AdditionalDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector AdditionalRelativeOffsets;
    
    ARemnantRangedWeapon();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void UseMod();
    
public:
    UFUNCTION(BlueprintCallable)
    void UseCharge();
    
    UFUNCTION(BlueprintCallable)
    void UseAllCharges();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool ShouldModCancelUse() const;
    
public:
    UFUNCTION(BlueprintCallable)
    void SetModActive(EModActiveState ModState, int32 ActionID, bool bForceNotify);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUseWithAim(FVector_NetQuantize AimOrigin, FVector_NetQuantize AimEnd);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUse();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Power();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ModActive();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Charges();
    
    UFUNCTION(BlueprintCallable)
    void OnFinishWeaponModeAnimation();
    
    UFUNCTION(BlueprintCallable)
    void OnFinishUseState(const FName& StateName, const FName& PreviousStateName);
    
    UFUNCTION(BlueprintCallable)
    void OnFinishUseAnimation();
    
    UFUNCTION(BlueprintCallable)
    void OnAltFireReleased();
    
    UFUNCTION(BlueprintCallable)
    void OnAltFirePressed();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnActivateSecondary();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnActivate();
    
    UFUNCTION(BlueprintCallable)
    void OnActionRemoved(UActionBase* Action);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastUse();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsModActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARemnantWeaponMod* GetWeaponMod() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetPower() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EModActiveState GetModActiveState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetModActiveRemainingPct() const;
    
    UFUNCTION(BlueprintPure)
    uint8 GetCharges() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void DelayedDeactivate();
    
};

