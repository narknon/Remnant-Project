#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "HoudiniMeshSplitInstancerComponent.generated.h"

class UStaticMesh;
class UStaticMeshComponent;
class UMaterialInterface;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class HOUDINIENGINERUNTIME_API UHoudiniMeshSplitInstancerComponent : public USceneComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, SkipSerialization, meta=(AllowPrivateAccess=true))
    TArray<UStaticMeshComponent*> Instances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SkipSerialization, meta=(AllowPrivateAccess=true))
    UMaterialInterface* OverrideMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SkipSerialization, meta=(AllowPrivateAccess=true))
    UStaticMesh* InstancedMesh;
    
public:
    UHoudiniMeshSplitInstancerComponent();
};

