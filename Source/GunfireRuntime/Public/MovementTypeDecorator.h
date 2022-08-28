#pragma once
#include "CoreMinimal.h"
#include "ActorStateDecorator.h"
#include "Engine/EngineTypes.h"
#include "MovementTypeDecorator.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UMovementTypeDecorator : public UActorStateDecorator {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EMovementMode> NewMovementMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool RestoreOnExit;
    
public:
    UMovementTypeDecorator();
};

