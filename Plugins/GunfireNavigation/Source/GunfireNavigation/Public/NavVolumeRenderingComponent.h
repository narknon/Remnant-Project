#pragma once
#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "NavVolumeRenderingComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRENAVIGATION_API UNavVolumeRenderingComponent : public UPrimitiveComponent {
    GENERATED_BODY()
public:
    UNavVolumeRenderingComponent();
};

