#pragma once
#include "CoreMinimal.h"
#include "Components/PrimitiveComponent.h"
#include "MapGenGizmo.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UMapGenGizmo : public UPrimitiveComponent {
    GENERATED_BODY()
public:
    UMapGenGizmo();
};

