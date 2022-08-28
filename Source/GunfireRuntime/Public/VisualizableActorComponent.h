#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VisualizableActorComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UVisualizableActorComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UVisualizableActorComponent();
};

