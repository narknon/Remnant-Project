#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Condition.h"
#include "Engine/EngineTypes.h"
#include "Engine/EngineTypes.h"
#include "PhysCastCondition.generated.h"

class AActor;

UCLASS(Abstract, Blueprintable)
class GUNFIRERUNTIME_API UPhysCastCondition : public UCondition {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TEnumAsByte<ECollisionChannel> TraceChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RefNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Distance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TraceComplex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<AActor>> ValidActorTypes;
    
    UPROPERTY(EditAnywhere)
    TArray<TEnumAsByte<EPhysicalSurface>> ValidSurfaceTypes;
    
    UPhysCastCondition();
};

