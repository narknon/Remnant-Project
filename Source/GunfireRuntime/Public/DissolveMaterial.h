#pragma once
#include "CoreMinimal.h"
#include "DissolveMaterial.generated.h"

class UMaterialInterface;
class UMaterialInstanceDynamic;

USTRUCT(BlueprintType)
struct FDissolveMaterial {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Material;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* DissolveMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UMaterialInstanceDynamic*> MaterialInstances;
    
    GUNFIRERUNTIME_API FDissolveMaterial();
};

