#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameSession.h"
#include "RemnantGameSession.generated.h"

UCLASS(Blueprintable)
class REMNANT_API ARemnantGameSession : public AGameSession {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumPublicConnections;
    
    ARemnantGameSession();
};

