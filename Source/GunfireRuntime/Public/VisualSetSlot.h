#pragma once
#include "CoreMinimal.h"
#include "VisualSetNode.h"
#include "VisualSetSlot.generated.h"

class UVisualID;

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UVisualSetSlot : public UVisualSetNode {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SlotID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UVisualID*> VisualIDs;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool HardReferenceAssets;
    
    UVisualSetSlot();
};

