#include "ItemManager.h"

class UItemManager;
class UObject;
class AItem;

void UItemManager::GetItemsInRangeByType(const FVector& Position, float Radius, TSoftClassPtr<AItem> Type, TArray<AItem*>& OutItems) {
}

UItemManager* UItemManager::GetInstance(const UObject* WorldContextObject) {
    return NULL;
}

UItemManager::UItemManager() {
}

