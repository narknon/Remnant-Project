#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PlayerGunfire.h"
#include "DialogInitiatorInterface.h"
#include "GunObstructionParameters.h"
#include "EGender.h"
#include "OnPossessedByDelegate.h"
#include "PersistentBuff.h"
#include "UObject/NoExportTypes.h"
#include "PersistenceKey.h"
#include "VisualComponent.h"
#include "RemnantCharacter.generated.h"

class USkeletalMesh;
class UEmotesComponent;
class URemnantPlayerInventoryComponent;
class AActor;
class UItemType;
class UVisualComponent;
class UAnimInstance;
class ACheckpoint;
class ARemnantPlayerController;
class APawn;
class UDamageClass;
class ASpawnPoint;
class UActionBuff;
class UUserSetting;
class UGameUserSettingsGunfire;
class ACharacterGunfire;
class ARangedWeapon;
class USavedCharacter;

UCLASS(Blueprintable)
class REMNANT_API ARemnantCharacter : public APlayerGunfire, public IDialogInitiatorInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVisualComponent* VisualComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URemnantPlayerInventoryComponent* Inventory;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UEmotesComponent* Emotes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAnimInstance> FemaleAnimInstanceClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeletalMesh* FemaleSkeletalMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVisualSet* FemaleVisualSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    EGender Gender;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPossessedBy OnPossessedBy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bHasAggro;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=UpdatePlayerInfoTag, meta=(AllowPrivateAccess=true))
    int32 ControllerIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 LastUsedItemId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CurrentPlayerInfoTag;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ShowHelmet, meta=(AllowPrivateAccess=true))
    bool ShowHelmet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HelmetSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ShowHelmetOption;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_GrabbedCheckpoint, meta=(AllowPrivateAccess=true))
    ACheckpoint* GrabbedCheckpoint;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> PrimaryWeaponType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ObstructedAdditionalDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ObstructedAdditionalRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGunObstructionParameters StandingParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGunObstructionParameters StandingExtentParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGunObstructionParameters CrouchingParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGunObstructionParameters CrouchExtentParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Deactivated, meta=(AllowPrivateAccess=true))
    bool bDeactivated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ARemnantPlayerController* OldController;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FPersistentBuff> PersistentBuffs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bOnlyExitDialogFromHostileDamage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bManualIgnoreDamageExitingDialog;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UDamageClass>> ExitDialogDamageClasses;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APawn* LocalValidationPawn;
    
public:
    ARemnantCharacter();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void UpdatePlayerInfoTag();
    
    UFUNCTION(BlueprintCallable)
    void UpdatePersistentBuffs();
    
    UFUNCTION(BlueprintCallable)
    void TeleportToSpawnPoint(AActor* SpawnPoint);
    
    UFUNCTION(BlueprintCallable)
    void SetSpawnPoint(ASpawnPoint* SpawnPoint);
    
    UFUNCTION(BlueprintCallable)
    void SetOldController(ARemnantPlayerController* PreviousController);
    
    UFUNCTION(BlueprintCallable)
    void SetHelmetShown(bool bShow);
    
    UFUNCTION(BlueprintCallable)
    void SetGrabbedCheckpoint(ACheckpoint* NewCheckpoint);
    
    UFUNCTION(BlueprintCallable)
    void SetDeactivated();
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetHelmetShown(bool bShow);
    
public:
    UFUNCTION(BlueprintCallable)
    void ResetAmmoInClip();
    
    UFUNCTION(BlueprintCallable)
    void RemovePersistentBuff(const UActionBuff* Buff);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnShowHelmetOptionChanged(UUserSetting* AppliedSetting, UGameUserSettingsGunfire* UserSettings);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRespawnAfterDeath();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_ShowHelmet();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_GrabbedCheckpoint(ACheckpoint* Previous);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Deactivated();
    
public:
    UFUNCTION()
    void OnCharacterDied(uint8 Reason, ACharacterGunfire* Character, AActor* Cause);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsReviving() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsDead() const;
    
    UFUNCTION(BlueprintCallable)
    void InitializePersistentBuffs();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARemnantPlayerController* GetOldController() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARangedWeapon* GetCurrentRangedWeapon() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    USavedCharacter* GetCharacterInfo();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetAge() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 ComputePowerLevel() const;
    
    UFUNCTION(BlueprintCallable)
    int32 ComputeOffenseLevel();
    
    UFUNCTION(BlueprintCallable)
    int32 ComputeDefenseLevel();
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientTeleportToSpawnPoint(ASpawnPoint* SpawnPoint);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientTeleport(FTransform Transform);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetSpawnPoint(const FPersistenceKey& SpawnPointID);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientRemoveAllPings();
    
    UFUNCTION(BlueprintCallable)
    void AddPersistentBuff(const UActionBuff* Buff);
    
    
    // Fix for true pure virtual functions not being implemented
};

