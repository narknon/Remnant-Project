#pragma once
#include "CoreMinimal.h"
#include "ActorStateDecorators.generated.h"

class UActorStateDecorator;

USTRUCT(BlueprintType)
struct FActorStateDecorators {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UActorStateDecorator*> Decorators;
    
    GUNFIRERUNTIME_API FActorStateDecorators();
};

