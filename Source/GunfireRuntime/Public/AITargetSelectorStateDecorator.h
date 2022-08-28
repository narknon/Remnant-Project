#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "ActorStateDecorator.h"
#include "AITargetSelectorStateDecorator.generated.h"

class UAITargetSelector;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UAITargetSelectorStateDecorator : public UActorStateDecorator {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAITargetSelector> TargetSelector;
    
public:
    UAITargetSelectorStateDecorator();
};

