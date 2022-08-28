#pragma once
#include "CoreMinimal.h"
#include "SceneVisual.h"
#include "RandomSkinMesh.h"
#include "RandomSkinnedMeshVisual.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API URandomSkinnedMeshVisual : public USceneVisual {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRandomSkinMesh> Meshes;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bResetMaterialsOnApply;
    
    URandomSkinnedMeshVisual();
};

