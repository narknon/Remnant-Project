#include "ItemUtil.h"
#include "Templates/SubclassOf.h"

class AActor;
class AItem;
class UInventoryComponent;
class USpawnTable;

bool UItemUtil::ValidateDropPosition(AActor* Source, const FVector& Position, FVector& OutPosition, bool SnapToGround, bool TestStaticCollision) {
    return false;
}

AItem* UItemUtil::SpawnItem(AActor* Source, TSubclassOf<AItem> ItemBP, const FTransform& SpawnTransform, uint8 Quantity, bool Transient, bool DoDrop) {
    return NULL;
}

void UItemUtil::PreSpawnDroppedItem(AItem* Item, uint8 Quantity) {
}

void UItemUtil::PostSpawnDroppedItem(AItem* Item) {
}

FInspectInfo UItemUtil::GetInspectInfoFromInventory(AActor* InspectActor, UInventoryComponent* Inventory, int32 ItemID, int32 LevelOverride) {
    return FInspectInfo{};
}

FInspectInfo UItemUtil::GetInspectInfo(AActor* InspectActor, TSubclassOf<AItem> ItemBP, int32 Level) {
    return FInspectInfo{};
}

void UItemUtil::DropLoot(AActor* Source, USpawnTable* SpawnTable, const TArray<FName>& Tags, int32 Rating, bool bAsync, bool bForce, bool Transient) {
}

bool UItemUtil::DropItem(AActor* Source, TSubclassOf<AItem> ItemBP, uint8 Quantity, bool Force, bool Transient) {
    return false;
}

UItemUtil::UItemUtil() {
}

