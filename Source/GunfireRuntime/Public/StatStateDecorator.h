#pragma once
#include "CoreMinimal.h"
#include "StatDecoratorStat.h"
#include "ActorStateDecorator.h"
#include "StatStateDecorator.generated.h"

class AActor;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UStatStateDecorator : public UActorStateDecorator {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FStatDecoratorStat> StatsToModify;
    
public:
    UStatStateDecorator();
private:
    UFUNCTION(BlueprintCallable)
    void ComputeStats(AActor* Actor);
    
};

