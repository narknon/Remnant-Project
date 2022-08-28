#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TargetManager.generated.h"

class UTargetableComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UTargetManager : public UActorComponent {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<UTargetableComponent*> RegisteredComponents;
    
public:
    UTargetManager();
};

