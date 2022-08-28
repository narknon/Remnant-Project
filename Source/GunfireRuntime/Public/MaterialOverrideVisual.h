#pragma once
#include "CoreMinimal.h"
#include "ActorVisual.h"
#include "MaterialOverrideVisual.generated.h"

class UMaterialInterface;

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UMaterialOverrideVisual : public UActorVisual {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Material;
    
    UMaterialOverrideVisual();
};

