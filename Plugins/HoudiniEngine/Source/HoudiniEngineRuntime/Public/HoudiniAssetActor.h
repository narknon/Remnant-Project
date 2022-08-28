#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "HoudiniAssetActor.generated.h"

class UHDAComponent;

UCLASS(Blueprintable)
class HOUDINIENGINERUNTIME_API AHoudiniAssetActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UHDAComponent* HoudiniAssetComponent;
    
    AHoudiniAssetActor();
};

