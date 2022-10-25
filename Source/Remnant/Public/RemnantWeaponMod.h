#pragma once
#include "CoreMinimal.h"
#include "LoadableModAsset.h"
#include "EquipmentMod.h"
#include "DamageInfo.h"
#include "UObject/NoExportTypes.h"
#include "EModInputMode.h"
#include "RangedWeaponMode.h"
#include "RemnantWeaponMod.generated.h"

class ARemnantRangedWeapon;
class UObject;

UCLASS(Blueprintable)
class REMNANT_API ARemnantWeaponMod : public AEquipmentMod {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PowerBasis;
    
    UPROPERTY(EditAnywhere)
    uint8 MaxCharges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EModInputMode InputMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> PreviewAnimTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStowWeaponForPreview;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinimumHoldTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUseAllChargesOnConsume;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bToggleable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasSecondaryAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bRequiresAllowActionForUse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ModUsageTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBlocksActionsWhileInUse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRangedWeaponMode WeaponMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActivateAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DeactivateAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UseAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SecondaryUseAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UseState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UseCrouchState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStowWeaponForUseAnimation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActiveVisual;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> CharacterAnimTags;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLoadableModAsset> Assets;
    
public:
    ARemnantWeaponMod();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ShowReticule();
    
    UFUNCTION(BlueprintCallable)
    void SetMinHoldTime(float HoldTime);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnUse();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnStartCustomIdle();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnSecondaryActivate();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPreviewStart();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPreviewEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPreFireEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPreFireBegin();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPreActivate();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFireEnd();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFireBegin();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnFire(const FVector& from, const FVector& to, float WeaponSpread);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnFinishLoadingAssets();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnEndUse();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEndCustomIdle();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDeactivate();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnChargesChanged(int32 Charges);
    
    UFUNCTION(BlueprintCallable)
    void OnCharacterHitTarget(const FDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnBeginUse();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnActivate();
    
    UFUNCTION(BlueprintCallable)
    void ModifyModPower(float Delta);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUseState(FName State) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPreviewing() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARemnantRangedWeapon* GetWeapon() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetUseState() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UClass* GetModAssetAsClass(FName AssetName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UObject* GetModAsset(FName AssetName) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    float GetModActiveRemainingPct();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetClientAimVector(FVector& AimOrigin, FVector& AimEnd);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool CanUse();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool CanDeactivateMod();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CalculateClientAimVector(FVector& AimOrigin, FVector& AimEnd);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreAssetsLoaded() const;
    
    UFUNCTION(BlueprintCallable)
    void ApplyDamageInfoToModPower(const FDamageInfo& DamageInfo, float ModPowerScalar, bool bForce, bool bIgnorePenalties);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void AddModPower(float Damage, float BonusModPowerMod);
    
};

