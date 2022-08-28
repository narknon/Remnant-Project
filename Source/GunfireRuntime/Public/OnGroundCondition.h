#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Condition.h"
#include "EGroundCheckType.h"
#include "Engine/EngineTypes.h"
#include "OnGroundCondition.generated.h"

class UGroundCheckParams;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UOnGroundCondition : public UCondition {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGroundCheckType GroundCheckType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CastDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinHitDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TraceCapsuleRadiusScale;
    
    UPROPERTY(EditAnywhere)
    TArray<TEnumAsByte<EPhysicalSurface>> ValidSurfaceTypes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGroundCheckParams> GroundCheckParams;
    
public:
    UOnGroundCondition();
};

