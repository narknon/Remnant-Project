#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AIAwarenessComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UAIAwarenessComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UAIAwarenessComponent();
};

