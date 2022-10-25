#include "CraftingRecipeManager.h"
#include "Templates/SubclassOf.h"

class UObject;
class AItem;
class UCraftingRecipeManager;

UCraftingRecipeManager* UCraftingRecipeManager::GetInstance(UObject* WorldContextObject) {
    return NULL;
}

TSet<TSubclassOf<AItem>> UCraftingRecipeManager::GetAllMaterials(UObject* WorldContextObject) {
    return TSet<TSubclassOf<AItem>>();
}

void UCraftingRecipeManager::BuildRecipeList(UObject* WorldContextObject) {
}

UCraftingRecipeManager::UCraftingRecipeManager() {
}

