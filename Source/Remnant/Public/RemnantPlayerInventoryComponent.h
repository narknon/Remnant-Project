#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "AutoUpgradeableItem.h"
#include "CheatProtectedItemParams.h"
#include "InventoryComponent.h"
#include "OnClientExceptionAddedDelegateDelegate.h"
#include "OnPickedUpDuplicateUniqueDelegate.h"
#include "ValidationTrackedItemParams.h"
#include "ClientValidatedItemInfo.h"
#include "AddedItemTypeTimeStamp.h"
#include "InventoryScalingInfo.h"
#include "RemnantPlayerInventoryComponent.generated.h"

class AItem;
class AActor;
class UItemType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantPlayerInventoryComponent : public UInventoryComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> UniqueMaterialRecipeTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAutoUpgradeableItem> AutoUpgradeableItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSoftClassPtr<AActor>> LimitInitialLevelClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<UItemType>> EquipmentVisualsSlotTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FCheatProtectedItemParams> TypesToValidate;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxValidItemAmountOverTime;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AddedItemTimeOutSeconds;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DoCurrencyOverTimeValidation;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DoCurrencyValidationOnRemove;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CurrencyQuantityTolerance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AItem> NullReferenceReplacementClass;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnClientExceptionAddedDelegate OnClientExceptionAddedOnServer;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPickedUpDuplicateUnique OnPickedUpDuplicateUnique;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<AItem>, FValidationTrackedItemParams> ValidationTrackedItems;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<AItem>, FClientValidatedItemInfo> ClientValidatedExceptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FAddedItemTypeTimeStamp> AddedItemQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FInventoryScalingInfo> LocalScalingInfo;
    
public:
    URemnantPlayerInventoryComponent();
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerOnClientExceptionUpdate(TSubclassOf<AItem> ItemBP, int32 Quantity);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnTrackedInstanceDataChanged();
    
public:
    UFUNCTION(BlueprintCallable)
    int32 ModifyLevelForNewItem(TSubclassOf<AItem> ItemBP, int32 ItemLevel);
    
    UFUNCTION(BlueprintCallable)
    void MarkClientSoftInventoryChangeValid(TSoftClassPtr<AItem> ItemSoftRef, int32 Quantity, int32 ItemLevel, bool IsItemRemoval);
    
    UFUNCTION(BlueprintCallable)
    void MarkClientInventoryChangeValid(TSubclassOf<AItem> ItemBP, int32 Quantity, int32 ItemLevel, bool IsItemRemoval);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsItemCheatProtected(TSubclassOf<AItem> ItemBP) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsCheatValidationEnabled() const;
    
    UFUNCTION(BlueprintCallable)
    static int32 GetLevelForNewItem(AActor* Actor, TSubclassOf<AItem> ItemBP, int32 ItemLevel);
    
protected:
    UFUNCTION(BlueprintCallable)
    void ClientValidationTimeOut();
    
    UFUNCTION(BlueprintCallable)
    void AddProtectionTimeOut();
    
};

