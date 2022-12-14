#pragma once
#include "CoreMinimal.h"
#include "VisualSceneComponent.generated.h"

class AActor;
class USceneComponent;
class UActorVisual;

USTRUCT(BlueprintType)
struct FVisualSceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* SceneComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UActorVisual* Visual;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* Actor;
    
    GUNFIRERUNTIME_API FVisualSceneComponent();
};

