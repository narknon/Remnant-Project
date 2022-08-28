#include "CraftingRecipe_Base.h"

UCraftingRecipe_Base::UCraftingRecipe_Base() {
    this->Type = ERecipeType::Craft;
    this->Ingredient1 = NULL;
    this->Ingredient1Quantity = 1;
    this->Ingredient1LevelRequirement = 0;
    this->bIngredient1HideIfMissing = false;
    this->Ingredient2 = NULL;
    this->Ingredient2Quantity = 1;
    this->Ingredient2LevelRequirement = 0;
    this->bIngredient2HideIfMissing = false;
    this->Ingredient3 = NULL;
    this->Ingredient3Quantity = 1;
    this->Ingredient3LevelRequirement = 0;
    this->bIngredient3HideIfMissing = false;
    this->Ingredient4 = NULL;
    this->Ingredient4Quantity = 1;
    this->Ingredient4LevelRequirement = 0;
    this->bIngredient4HideIfMissing = false;
}

