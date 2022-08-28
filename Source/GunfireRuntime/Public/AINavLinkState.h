#pragma once
#include "CoreMinimal.h"
#include "AnimActorState.h"
#include "UObject/NoExportTypes.h"
#include "AINavLinkState.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UAINavLinkState : public UAnimActorState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool SnapStartPositionToGround;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Offset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LerpTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CollisionEnableWindow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StopMovementOnExit;
    
public:
    UAINavLinkState();
};

