#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "DamageSourceInterface.h"
#include "Item.h"
#include "EquipmentModData.h"
#include "InspectInfo.h"
#include "EquipmentMod.generated.h"

class AEquipmentMod;
class UInventoryComponent;
class AEquipment;
class AActor;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AEquipmentMod : public AItem, public IDamageSourceInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Hidden;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ReplicateMod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName VisualSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName VisualID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool CanBeRemoved;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    AEquipment* _Equipment;
    
    UPROPERTY(EditAnywhere, Replicated)
    uint8 _Slot;
    
    UPROPERTY(EditAnywhere, Replicated)
    uint8 _Level;
    
    AEquipmentMod();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    static bool UnequipMod(UInventoryComponent* Inventory, int32 ItemID, uint8 Slot, bool AddToInventory);
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void ScaleStat(FName Stat, float Scalar, bool AutoInitValue) const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPostComputeStats() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnDetached();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnComputeStats() const;
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnAttached();
    
    UFUNCTION(BlueprintCallable, BlueprintPure=false)
    void ModifyStat(FName Stat, float Value) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool HasItemOrEquippedMod(UInventoryComponent* Inventory, TSubclassOf<AItem> ItemBP);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetStat(FName Stat) const;
    
    UFUNCTION(BlueprintPure)
    uint8 GetSlot() const;
    
    UFUNCTION(BlueprintCallable)
    static FInspectInfo GetPreviewInspectInfoFromInventory(AActor* Actor, UInventoryComponent* Inventory, int32 ItemID, uint8 Slot, int32 ModItemID);
    
    UFUNCTION(BlueprintCallable)
    static FInspectInfo GetPreviewInspectInfo(AActor* Actor, UInventoryComponent* Inventory, int32 ItemID, uint8 Slot, TSubclassOf<AEquipmentMod> Mod, uint8 ModLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AEquipment* GetEquipment() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool FindEquippedModInInventory(UInventoryComponent* Inventory, TSubclassOf<AItem> Mod, int32& OutItemID, FEquipmentModData& OutModData);
    
    UFUNCTION(BlueprintCallable)
    static bool EquipModFromInventory(UInventoryComponent* Inventory, int32 ItemID, uint8 Slot, int32 ModItemID);
    
    UFUNCTION(BlueprintCallable)
    static bool EquipMod(UInventoryComponent* Inventory, int32 ItemID, uint8 Slot, TSubclassOf<AEquipmentMod> Mod, uint8 ModLevel);
    
    
    // Fix for true pure virtual functions not being implemented
};

