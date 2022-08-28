#pragma once
#include "CoreMinimal.h"
#include "SceneVisual.h"
#include "RandomStaticMesh.h"
#include "RandomStaticMeshVisual.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API URandomStaticMeshVisual : public USceneVisual {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRandomStaticMesh> Meshes;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetMaterialsOnApply;
    
    URandomStaticMeshVisual();
};

