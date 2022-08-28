#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "UObject/NoExportTypes.h"
#include "InspectInfo.h"
#include "ItemUtil.generated.h"

class AActor;
class AItem;
class UInventoryComponent;
class USpawnTable;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UItemUtil : public UObject {
    GENERATED_BODY()
public:
    UItemUtil();
    UFUNCTION(BlueprintCallable)
    static bool ValidateDropPosition(AActor* Source, const FVector& Position, FVector& OutPosition, bool SnapToGround, bool TestStaticCollision);
    
    UFUNCTION(BlueprintCallable)
    static AItem* SpawnItem(AActor* Source, TSubclassOf<AItem> ItemBP, const FTransform& SpawnTransform, uint8 Quantity, bool Transient, bool DoDrop);
    
    UFUNCTION(BlueprintCallable)
    static void PreSpawnDroppedItem(AItem* Item, uint8 Quantity);
    
    UFUNCTION(BlueprintCallable)
    static void PostSpawnDroppedItem(AItem* Item);
    
    UFUNCTION(BlueprintCallable)
    static FInspectInfo GetInspectInfoFromInventory(AActor* InspectActor, UInventoryComponent* Inventory, int32 ItemID, int32 LevelOverride);
    
    UFUNCTION(BlueprintCallable)
    static FInspectInfo GetInspectInfo(AActor* InspectActor, TSubclassOf<AItem> ItemBP, int32 Level);
    
    UFUNCTION(BlueprintCallable)
    static void DropLoot(AActor* Source, USpawnTable* SpawnTable, const TArray<FName>& Tags, int32 Rating, bool bAsync, bool bForce, bool Transient);
    
    UFUNCTION(BlueprintCallable)
    static bool DropItem(AActor* Source, TSubclassOf<AItem> ItemBP, uint8 Quantity, bool Force, bool Transient);
    
};

