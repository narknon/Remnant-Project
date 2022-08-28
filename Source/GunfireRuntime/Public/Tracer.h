#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tracer.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API ATracer : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Speed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxFlightTime;
    
    ATracer();
};

