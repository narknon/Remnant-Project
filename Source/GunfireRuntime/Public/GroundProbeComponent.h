#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GroundProbeComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UGroundProbeComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UGroundProbeComponent();
};

