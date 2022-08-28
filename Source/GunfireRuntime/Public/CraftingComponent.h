#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "UObject/NoExportTypes.h"
#include "ERecipeType.h"
#include "RecipeInfo.h"
#include "CraftingComponent.generated.h"

class AItem;
class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UCraftingComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> RecipeTags;
    
    UCraftingComponent();
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void UpgradeItem(AActor* Source, int32 ItemID, FGuid RecipeID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasRecipesOfType(AActor* Source, ERecipeType Type);
    
    UFUNCTION(BlueprintCallable)
    bool HasAvailableUpgrades(const TArray<FName>& Tags);
    
    UFUNCTION(BlueprintCallable)
    bool HasAvailableRecipes(const TArray<FName>& Tags);
    
    UFUNCTION(BlueprintCallable)
    bool GetUpgrade(AActor* Source, int32 ItemID, FRecipeInfo& Info);
    
    UFUNCTION(BlueprintCallable)
    TArray<FRecipeInfo> GetRecipesWithIngredient(AActor* Source, TSubclassOf<AItem> Ingredient, ERecipeType Type, int32 IngredientLevelRequirement);
    
    UFUNCTION(BlueprintCallable)
    TArray<FRecipeInfo> GetRecipesForItem(AActor* Source, TSubclassOf<AItem> Item, ERecipeType Type, int32 ItemLevelRequirement);
    
    UFUNCTION(BlueprintCallable)
    TArray<FRecipeInfo> GetRecipes(AActor* Source, ERecipeType Type);
    
    UFUNCTION(BlueprintCallable)
    FRecipeInfo GetRecipeInfo(AActor* Source, FGuid RecipeID);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void CraftItem(AActor* Source, FGuid RecipeID);
    
};

