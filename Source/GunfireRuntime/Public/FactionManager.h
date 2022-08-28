#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FactionManager.generated.h"

class UFactionManager;
class UFactionComponent;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UFactionManager : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FactionOverridePropogationRadius;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TArray<UFactionComponent*> FactionComponents;
    
public:
    UFactionManager();
    UFUNCTION(BlueprintCallable)
    static UFactionManager* GetFactionManager(UObject* WorldContextObject);
    
};

