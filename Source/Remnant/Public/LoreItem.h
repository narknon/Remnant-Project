#pragma once
#include "CoreMinimal.h"
#include "Item.h"
#include "LorePage.h"
#include "LoreItem.generated.h"

class UObject;

UCLASS(Blueprintable)
class REMNANT_API ALoreItem : public AItem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AutoOpenUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool OverrideHideReadUI;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLorePage> Pages;
    
    ALoreItem();
    UFUNCTION(BlueprintCallable)
    static void LoreNotify(UObject* WorldContextObject, const FLorePage& Page);
    
};

