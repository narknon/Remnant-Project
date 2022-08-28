#pragma once
#include "CoreMinimal.h"
#include "Item.h"
#include "EquipmentAttachment.h"
#include "EquipmentModSlot.h"
#include "AnimationHandle.h"
#include "EquipmentDelegateDelegate.h"
#include "DamageInfo.h"
#include "Equipment.generated.h"

class ACharacterGunfire;
class USoundCue;
class UVisualComponent;
class UStatsComponent;
class AUIHud;
class UInventoryComponent;
class AEquipmentMod;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AEquipment : public AItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName VisualID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AnimationLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEquipmentAttachment> Attachments;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AutoEnableInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ShouldUnequip;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseEquipmentAnimTimings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FEquipmentModSlot> ModSlots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ActiveTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> CharacterAnimTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AdditionalAnimTag;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* EquipSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UStatsComponent* StatsComp;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEquipmentDelegate OnEquippedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEquipmentDelegate OnUnequippedEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAnimationHandle CurrentAnimHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacterGunfire* Character;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    ACharacterGunfire* CharacterReplicated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AEquipmentMod*> ModInstances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UVisualComponent* VisualComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsActiveReplicated: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    uint8 bIsInHandReplicated: 1;
    
public:
    AEquipment();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ValidateEquip(ACharacterGunfire* ToCharacter);
    
    UFUNCTION(BlueprintCallable)
    void Unequip();
    
    UFUNCTION(BlueprintCallable)
    void SetInputEnabled(bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    void SetInHand(bool InHand);
    
    UFUNCTION(BlueprintCallable)
    void SetAttachmentsVisible(bool Visible);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetInHand(bool InHand);
    
protected:
    UFUNCTION(BlueprintCallable)
    void ScaleStat(FName Stat, float Scalar, bool AutoInitValue);
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void PostSetupInventory();
    
protected:
    UFUNCTION(BlueprintCallable)
    void PostComputeStats();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void PostComputeCharacterStats();
    
public:
    UFUNCTION(BlueprintCallable)
    float PlayAnimation(FName AnimationID, float PlayRate, bool bCharacterOnly);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUnequipped();
    
protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void OnTakeDamage(const FDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPostComputeStats();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnNotInHand();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnInHand();
    
protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void OnHitTarget(const FDamageInfo& DamageInfo);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEquipped();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDetached();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDeactivated();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnComputeStats();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnActivated();
    
protected:
    UFUNCTION(BlueprintCallable)
    void ModifyStat(FName Stat, float Value);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsLocallyControlled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInHand() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEquipped() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActive() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActionAllowed() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void InstanceDataChanged();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStat(FName Stat);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetItemID();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetInventoryComponent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AUIHud* GetHud() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetEquipmentSlotIdx();
    
protected:
    UFUNCTION(BlueprintCallable)
    AEquipmentMod* GetEquipmentMod(uint8 Slot);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetCurrentAnimation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacterGunfire* GetCharacter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AEquipmentMod*> GetAttachedMods();
    
    UFUNCTION(BlueprintCallable)
    void Detach();
    
    UFUNCTION(BlueprintCallable)
    void Deactivate();
    
protected:
    UFUNCTION(BlueprintCallable)
    void ComputeStats();
    
    UFUNCTION(BlueprintCallable)
    void ComputeCharacterStats();
    
public:
    UFUNCTION(BlueprintCallable)
    void Activate();
    
protected:
    UFUNCTION(BlueprintCallable)
    void _NotifyTakeDamage(const FDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable)
    void _NotifyHitTarget(const FDamageInfo& DamageInfo);
    
};

