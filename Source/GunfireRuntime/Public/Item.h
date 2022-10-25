#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Actor.h"
#include "ItemDelegateDelegate.h"
#include "Engine/DataTable.h"
#include "InspectInfo.h"
#include "Item.generated.h"

class UPersistenceComponent;
class UTexture2D;
class USoundCue;
class UItemType;
class UItemCategory;
class UItemInstanceData;
class UParticleSystem;
class AImpactEffect;
class UParticleSystemComponent;
class UInventoryComponent;
class APawn;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AItem : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPersistenceComponent* PersistenceComp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemCategory> Category;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxStackCount;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, Instanced, SaveGame, ReplicatedUsing=OnRep_InstanceData, meta=(AllowPrivateAccess=true))
    UItemInstanceData* InstanceData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDataTableRowHandle Stats;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bNeedsQuantityToSelect;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Label;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Description;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText PickupDescription;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* Icon;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> LargeIcon;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* HUDIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Interactable;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseInteractInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText InteractLabel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName InteractIconName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* InteractIcon;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* PickupSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PickupChanceApplyModStatName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PickupModStatName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PickupScalarStatName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LootFxAttachNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* LootFxOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DoBounce;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BounceAnimRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* BounceFlipSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* BounceSound;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AImpactEffect> DroppedImpactEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    bool bOnGround;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemDelegate OnCollected;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UParticleSystemComponent* LootFxParticles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool Inspecting;
    
public:
    AItem();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ValidateAdd(UInventoryComponent* Inventory, int32 DesiredQuantity, int32& AllowedQuantity);
    
    UFUNCTION(BlueprintCallable)
    void SetQuantity(int32 Quantity);
    
    UFUNCTION(BlueprintCallable)
    void SetLevel(uint8 Level);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool PreAdd(UInventoryComponent* Inventory, int32 Quantity);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool PickupPreAdd(UInventoryComponent* Inventory, int32 Quantity, int32 Level);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_InstanceData(UItemInstanceData* PrevData);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPickupFailed();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPickedUp();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDropped();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void ModifyInspectInfo(AActor* Actor, UItemInstanceData* InInstanceData, UPARAM(Ref) FInspectInfo& Info, bool& Rtn);
    
protected:
    UFUNCTION(BlueprintCallable)
    void InitializeLootFxForLocalPawn(APawn* Pawn);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetQuantity();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    int32 GetMaxQuantity() const;
    
    UFUNCTION(BlueprintNativeEvent, BlueprintPure)
    uint8 GetLevel() const;
    
    UFUNCTION(BlueprintCallable)
    FInspectInfo GetInspectInfo(AActor* Actor, UItemInstanceData* InInstanceData, int32 LevelOverride);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void DropBounce();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void Bounce();
    
};

