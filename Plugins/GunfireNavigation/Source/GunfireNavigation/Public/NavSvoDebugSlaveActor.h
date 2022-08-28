#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NavSvoDebugSlaveActor.generated.h"

class ANavSvoDebugActor;

UCLASS(Blueprintable, NotPlaceable)
class ANavSvoDebugSlaveActor : public AActor {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ANavSvoDebugActor* MasterActor;
    
public:
    ANavSvoDebugSlaveActor();
};

