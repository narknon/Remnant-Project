#include "CraftingComponent.h"
#include "Templates/SubclassOf.h"

class AActor;
class AItem;

void UCraftingComponent::UpgradeItem_Implementation(AActor* Source, int32 ItemID, FGuid RecipeID) {
}
bool UCraftingComponent::UpgradeItem_Validate(AActor* Source, int32 ItemID, FGuid RecipeID) {
    return true;
}

bool UCraftingComponent::HasRecipesOfType(AActor* Source, ERecipeType Type) {
    return false;
}

bool UCraftingComponent::HasAvailableUpgrades(const TArray<FName>& Tags) {
    return false;
}

bool UCraftingComponent::HasAvailableRecipes(const TArray<FName>& Tags) {
    return false;
}

bool UCraftingComponent::GetUpgrade(AActor* Source, int32 ItemID, FRecipeInfo& Info) {
    return false;
}

TArray<FRecipeInfo> UCraftingComponent::GetRecipesWithIngredient(AActor* Source, TSubclassOf<AItem> Ingredient, ERecipeType Type, int32 IngredientLevelRequirement) {
    return TArray<FRecipeInfo>();
}

TArray<FRecipeInfo> UCraftingComponent::GetRecipesForItem(AActor* Source, TSubclassOf<AItem> Item, ERecipeType Type, int32 ItemLevelRequirement) {
    return TArray<FRecipeInfo>();
}

TArray<FRecipeInfo> UCraftingComponent::GetRecipes(AActor* Source, ERecipeType Type) {
    return TArray<FRecipeInfo>();
}

FRecipeInfo UCraftingComponent::GetRecipeInfo(AActor* Source, FGuid RecipeID) {
    return FRecipeInfo{};
}

void UCraftingComponent::CraftItem_Implementation(AActor* Source, FGuid RecipeID) {
}
bool UCraftingComponent::CraftItem_Validate(AActor* Source, FGuid RecipeID) {
    return true;
}

UCraftingComponent::UCraftingComponent() {
}

