#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Equipment.h"
#include "DeployableAttributes.h"
#include "Builder.generated.h"

class UMaterial;
class APawn;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API ABuilder : public AEquipment {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FDeployableAttributes DeployableAttributes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterial* HighlightMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<APawn> PawnToDeploy;
    
    ABuilder();
    UFUNCTION(BlueprintCallable)
    void TryPlace();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerTryPlace();
    
    UFUNCTION(BlueprintCallable)
    void ExitBuilder();
    
};

