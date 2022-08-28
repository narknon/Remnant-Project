#pragma once
#include "CoreMinimal.h"
#include "MiniMapActorRef.generated.h"

class AMiniMapDisplayActor;
class AActor;

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FMiniMapActorRef {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* RefActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AMiniMapDisplayActor* MiniMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 Context;
    
    FMiniMapActorRef();
};

