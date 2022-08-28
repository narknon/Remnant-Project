#pragma once
#include "CoreMinimal.h"
#include "VisualSetNode.h"
#include "VisualFX.generated.h"

class UVisualFXEntry;

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UVisualFX : public UVisualSetNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UVisualFXEntry*> Entries;
    
    UVisualFX();
};

