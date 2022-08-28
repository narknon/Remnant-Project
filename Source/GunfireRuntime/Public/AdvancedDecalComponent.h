#pragma once
#include "CoreMinimal.h"
#include "Components/DecalComponent.h"
#include "AdvancedDecalComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UAdvancedDecalComponent : public UDecalComponent {
    GENERATED_BODY()
public:
    UAdvancedDecalComponent();
};

