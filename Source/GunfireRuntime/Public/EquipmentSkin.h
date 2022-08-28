#pragma once
#include "CoreMinimal.h"
#include "Item.h"
#include "EquipmentSkin.generated.h"

class AEquipmentSkin;
class UInventoryComponent;
class AEquipment;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AEquipmentSkin : public AItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<AEquipment> EquipmentBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName VisualID;
    
    AEquipmentSkin();
    UFUNCTION(BlueprintCallable)
    static bool IsSkinEquipped(UInventoryComponent* Inventory, int32 SkinID);
    
    UFUNCTION(BlueprintCallable)
    static TArray<int32> GetSkinsForItem(UInventoryComponent* Inventory, int32 ItemID);
    
    UFUNCTION(BlueprintCallable)
    static AEquipmentSkin* GetSkinForBP(UInventoryComponent* Inventory, TSoftClassPtr<AEquipment> ItemBP);
    
    UFUNCTION(BlueprintCallable)
    static void EquipSkin(UInventoryComponent* Inventory, int32 ItemID, int32 SkinID);
    
};

