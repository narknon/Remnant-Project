#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AIPointOfInterestManager.generated.h"

class AAIPointOfInterest;
class UAIPointOfInterestManager;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UAIPointOfInterestManager : public UActorComponent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAIPointOfInterest*> PointsOfInterest;
    
public:
    UAIPointOfInterestManager();
    UFUNCTION(BlueprintCallable)
    static UAIPointOfInterestManager* GetInstance(UObject* WorldContextObject);
    
};

