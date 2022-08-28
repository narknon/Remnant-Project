#pragma once
#include "CoreMinimal.h"
#include "Condition.h"
#include "ENavAreaFlag.h"
#include "AINavLinkCondition.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UAINavLinkCondition : public UCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(EditAnywhere)
    TEnumAsByte<ENavAreaFlag::Type> AreaFlag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LookAheadDistance;
    
public:
    UAINavLinkCondition();
};

