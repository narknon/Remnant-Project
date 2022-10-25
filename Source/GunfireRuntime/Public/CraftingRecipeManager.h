#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "RecipeList.h"
#include "UObject/NoExportTypes.h"
#include "CraftingRecipeManager.generated.h"

class UCraftingRecipe_Base;
class AItem;
class UCraftingRecipeManager;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UCraftingRecipeManager : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, FRecipeList> Recipes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FGuid, UCraftingRecipe_Base*> RecipeLookup;
    
public:
    UCraftingRecipeManager();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UCraftingRecipeManager* GetInstance(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static TSet<TSubclassOf<AItem>> GetAllMaterials(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void BuildRecipeList(UObject* WorldContextObject);
    
};

