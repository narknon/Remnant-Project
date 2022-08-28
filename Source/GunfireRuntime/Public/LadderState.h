#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TraversalState.h"
#include "LadderState.generated.h"

class ULadderParams;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API ULadderState : public UTraversalState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<ULadderParams> LadderParams;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GrabHeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GrabOffset;
    
public:
    ULadderState();
};

