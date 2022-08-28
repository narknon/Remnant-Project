#pragma once
#include "CoreMinimal.h"
#include "ActorStateDecorator.h"
#include "CapsuleSizeStateDecorator.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UCapsuleSizeStateDecorator : public UActorStateDecorator {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CapsuleHalfHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CapsuleRadius;
    
public:
    UCapsuleSizeStateDecorator();
};

