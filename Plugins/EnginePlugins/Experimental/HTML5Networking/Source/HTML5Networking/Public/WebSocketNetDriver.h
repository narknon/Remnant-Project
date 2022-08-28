#pragma once
#include "CoreMinimal.h"
#include "Engine/NetDriver.h"
#include "WebSocketNetDriver.generated.h"

UCLASS(Blueprintable, NonTransient)
class HTML5NETWORKING_API UWebSocketNetDriver : public UNetDriver {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 WebSocketPort;
    
    UWebSocketNetDriver();
};

