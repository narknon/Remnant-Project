#include "ItemType.h"
#include "Templates/SubclassOf.h"

class UInventoryComponent;
class UItemType;
class AActor;

TArray<FItemQueryResult> UItemType::QueryRelevantItems(const TArray<UInventoryComponent*>& Inventories, const FItemQueryFilter& Filter, EItemQuerySortMethod SortMethod) {
    return TArray<FItemQueryResult>();
}

TArray<UInventoryComponent*> UItemType::GetRelevantInventoriesForType(AActor* Actor, TSubclassOf<UItemType> Type) {
    return TArray<UInventoryComponent*>();
}

UItemType::UItemType() {
    this->BaseType = NULL;
    this->ItemStats = NULL;
    this->CharacterStats = NULL;
    this->Icon = NULL;
}

