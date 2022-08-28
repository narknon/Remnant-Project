#pragma once
#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "SoftCollisionCapsuleComponent.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API USoftCollisionCapsuleComponent : public UCapsuleComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SoftCharacterCollisionWeight;
    
    USoftCollisionCapsuleComponent();
};

