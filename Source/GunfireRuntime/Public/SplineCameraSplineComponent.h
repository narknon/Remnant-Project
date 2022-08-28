#pragma once
#include "CoreMinimal.h"
#include "Components/SplineComponent.h"
#include "SplineCameraSplineComponent.generated.h"

UCLASS(Blueprintable, NotPlaceable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API USplineCameraSplineComponent : public USplineComponent {
    GENERATED_BODY()
public:
    USplineCameraSplineComponent();
};

