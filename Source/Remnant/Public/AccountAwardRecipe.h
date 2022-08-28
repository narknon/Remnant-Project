#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "CraftingRecipe_Base.h"
#include "AccountAwardRecipe.generated.h"

class UAccountAward;

UCLASS(Blueprintable)
class REMNANT_API UAccountAwardRecipe : public UCraftingRecipe_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAccountAward> Award;
    
    UAccountAwardRecipe();
};

