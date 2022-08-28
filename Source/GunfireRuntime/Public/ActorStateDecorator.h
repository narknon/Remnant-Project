#pragma once
#include "CoreMinimal.h"
#include "StateMachineSubobject.h"
#include "ActorStateDecorator.generated.h"

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API UActorStateDecorator : public UStateMachineSubobject {
    GENERATED_BODY()
public:
    UActorStateDecorator();
};

