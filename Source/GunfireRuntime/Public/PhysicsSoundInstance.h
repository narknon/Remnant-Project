#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "PhysicsSoundInstance.generated.h"

class UAudioComponent;

UCLASS(Blueprintable)
class UPhysicsSoundInstance : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAudioComponent* CurrentComponent;
    
    UPhysicsSoundInstance();
    UFUNCTION(BlueprintCallable)
    void OnImpactTimerExpired();
    
    UFUNCTION(BlueprintCallable)
    void AudioComponentFinished();
    
};

