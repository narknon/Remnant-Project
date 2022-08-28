#pragma once
#include "CoreMinimal.h"
#include "PhysCastCondition.h"
#include "UObject/NoExportTypes.h"
#include "SphereCastCondition.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API USphereCastCondition : public UPhysCastCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Offset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Direction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
public:
    USphereCastCondition();
};

