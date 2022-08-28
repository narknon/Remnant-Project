#pragma once
#include "CoreMinimal.h"
#include "VisualMaterialReplacement.h"
#include "VisualMaterialParam.h"
#include "RandomStaticMesh.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType)
struct FRandomStaticMesh {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UStaticMesh> Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> VisualTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AnimSoundTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVisualMaterialReplacement> MaterialReplacements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVisualMaterialParam> MaterialParams;
    
    GUNFIRERUNTIME_API FRandomStaticMesh();
};

