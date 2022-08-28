#pragma once
#include "CoreMinimal.h"
#include "SceneVisual.h"
#include "VisualMaterialReplacement.h"
#include "VisualMaterialParam.h"
#include "StaticMeshVisual.generated.h"

class UStaticMesh;

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UStaticMeshVisual : public USceneVisual {
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
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetMaterialsOnApply;
    
    UStaticMeshVisual();
};

