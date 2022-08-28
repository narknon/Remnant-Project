#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "CraftingRecipe_Base.h"
#include "CraftingRecipe.generated.h"

class AItem;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UCraftingRecipe : public UCraftingRecipe_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AItem> Item;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ItemLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ItemQuantity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ItemTag;
    
    UCraftingRecipe();
};

