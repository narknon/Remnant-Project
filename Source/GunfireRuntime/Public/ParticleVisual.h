#pragma once
#include "CoreMinimal.h"
#include "SceneVisual.h"
#include "ParticleVisual.generated.h"

class UParticleSystem;

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UParticleVisual : public USceneVisual {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UParticleSystem> ParticleSystem;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 Attached: 1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool TrySoftDestroy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SocketName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ActorParameterName;
    
    UParticleVisual();
};

