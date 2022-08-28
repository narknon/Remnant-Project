#include "Recipe.h"

FRecipe::FRecipe() {
    this->Type = ERecipeType::Craft;
    this->Item = NULL;
    this->ItemLevel = 0;
    this->ItemQuantity = 0;
    this->Ingredient1 = NULL;
    this->Ingredient1Quantity = 0;
    this->Ingredient2 = NULL;
    this->Ingredient2Quantity = 0;
    this->Ingredient3 = NULL;
    this->Ingredient3Quantity = 0;
    this->Ingredient4 = NULL;
    this->Ingredient4Quantity = 0;
}

