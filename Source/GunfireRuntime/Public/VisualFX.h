#pragma once
#include "CoreMinimal.h"
#include "VisualSetNode.h"
#include "VisualFXEntry.h"
#include "VisualFX.generated.h"


UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UVisualFX : public UVisualSetNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UVisualFXEntry*> Entries;
    
    UVisualFX();
};

