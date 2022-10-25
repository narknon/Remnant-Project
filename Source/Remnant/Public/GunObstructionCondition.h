#pragma once
#include "CoreMinimal.h"
#include "EGunObstructionTypes.h"
#include "Condition.h"
#include "GunObstructionCondition.generated.h"

UCLASS(Blueprintable)
class REMNANT_API UGunObstructionCondition : public UCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGunObstructionTypes Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bInObstructedState;
    
public:
    UGunObstructionCondition();
};

