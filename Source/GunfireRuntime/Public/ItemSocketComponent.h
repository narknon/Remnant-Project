#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/SceneComponent.h"
#include "UseItemInterface.h"
#include "ItemSocketSlot.h"
#include "ItemSocketEventDelegate.h"
#include "ItemSocketComponent.generated.h"

class AItem;
class ACharacterGunfire;
class UInventoryComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UItemSocketComponent : public USceneComponent, public IUseItemInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FItemSocketSlot Slot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Blocked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemSocketEvent OnItemSocketChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemSocketEvent OnItemSocketed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FItemSocketEvent OnItemUnsocketed;
    
    UItemSocketComponent();
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void RequestReturnItemToInventory(ACharacterGunfire* Subject);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void RequestAddItemFromInventoryById(UInventoryComponent* Inventory, int32 ItemID);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void RequestAddItemFromInventoryByClass(UInventoryComponent* Inventory, TSubclassOf<AItem> ItemClass);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void RequestAddItemFromInventory(ACharacterGunfire* Subject);
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void RemoveItem();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool IsValid(TSubclassOf<AItem> ItemClass) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFull() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsEmpty() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasInteractableSlot() const;
    
    UFUNCTION(BlueprintCallable)
    void ForceFill();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanAddItemOfClass(TSubclassOf<AItem> ItemClass) const;
    
protected:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void AddItem(TSubclassOf<AItem> ItemClass);
    
    
    // Fix for true pure virtual functions not being implemented
};

