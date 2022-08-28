#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AITacticalPointContainerInterface.h"
#include "AITacticalPoint.h"
#include "AITacticalPointData.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AAITacticalPointData : public AActor, public IAITacticalPointContainerInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAITacticalPoint> GeneratedPoints;
    
    AAITacticalPointData();
    
    // Fix for true pure virtual functions not being implemented
};

