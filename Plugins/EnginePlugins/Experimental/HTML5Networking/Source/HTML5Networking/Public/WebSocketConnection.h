#pragma once
#include "CoreMinimal.h"
#include "Engine/NetConnection.h"
#include "WebSocketConnection.generated.h"

UCLASS(Blueprintable, NonTransient)
class HTML5NETWORKING_API UWebSocketConnection : public UNetConnection {
    GENERATED_BODY()
public:
    UWebSocketConnection();
};

