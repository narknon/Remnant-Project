#pragma once
#include "CoreMinimal.h"
#include "PooledSceneComponent.h"
#include "PooledParticleSystemComponent.generated.h"

UCLASS(Blueprintable)
class UPooledParticleSystemComponent : public UPooledSceneComponent {
    GENERATED_BODY()
public:
    UPooledParticleSystemComponent();
};

