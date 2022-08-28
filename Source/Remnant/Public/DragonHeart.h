#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UseableItem.h"
#include "DragonHeart.generated.h"

class AItem;

UCLASS(Blueprintable)
class REMNANT_API ADragonHeart : public AUseableItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumCharges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AItem> UpgradeItemBP;
    
    ADragonHeart();
    UFUNCTION(BlueprintCallable)
    void Regenerate();
    
    UFUNCTION(BlueprintCallable)
    int32 GetMaxCurrentQuantity();
    
};

