#pragma once
#include "CoreMinimal.h"
#include "VisualMaterialReplacement.generated.h"

class UMaterialInterface;

USTRUCT(BlueprintType)
struct FVisualMaterialReplacement {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SlotName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Material;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAllMeshes;
    
    GUNFIRERUNTIME_API FVisualMaterialReplacement();
};

