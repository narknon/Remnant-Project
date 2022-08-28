#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "StaticProceduralMesh.generated.h"

class USceneComponent;
class UArrowComponent;
class UProceduralMeshComponent;
class UStaticMeshComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AStaticProceduralMesh : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    USceneComponent* Scene;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UArrowComponent* Arrow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UProceduralMeshComponent* InitialProceduralMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UStaticMeshComponent* FinalStaticMesh;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsUsingStaticMesh;
    
    AStaticProceduralMesh();
};

