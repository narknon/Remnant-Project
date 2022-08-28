#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "DeployableAttributes.h"
#include "DeployableComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UDeployableComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDeployableAttributes Attributes;
    
    UDeployableComponent();
};

