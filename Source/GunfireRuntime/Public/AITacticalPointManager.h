#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AITacticalPointManager.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UAITacticalPointManager : public UActorComponent {
    GENERATED_BODY()
public:
    UAITacticalPointManager();
};

