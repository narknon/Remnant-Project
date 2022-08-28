#pragma once
#include "CoreMinimal.h"
#include "ActorStateDecorator.h"
#include "AIMoveForwardStateDecorator.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UAIMoveForwardStateDecorator : public UActorStateDecorator {
    GENERATED_BODY()
public:
    UAIMoveForwardStateDecorator();
};

