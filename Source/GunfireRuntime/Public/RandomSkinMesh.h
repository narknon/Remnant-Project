#pragma once
#include "CoreMinimal.h"
#include "VisualMaterialReplacement.h"
#include "VisualMaterialParam.h"
#include "RandomSkinMesh.generated.h"

class USkeletalMesh;

USTRUCT(BlueprintType)
struct FRandomSkinMesh {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<USkeletalMesh> Mesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> VisualTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AnimSoundTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVisualMaterialReplacement> MaterialReplacements;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVisualMaterialParam> MaterialParams;
    
    GUNFIRERUNTIME_API FRandomSkinMesh();
};

