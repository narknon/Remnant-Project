#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNotifies/AnimNotify_PlayParticleEffect.h"
#include "OptimizableNotifyInterface.h"
#include "ENotifyOptimizationType.h"
#include "Conditions.h"
#include "AnimNotify_StateParticleEffect.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class GUNFIRERUNTIME_API UAnimNotify_StateParticleEffect : public UAnimNotify_PlayParticleEffect, public IOptimizableNotifyInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsStateTransient;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSoftDestroy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ENotifyOptimizationType OptimizationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShowInPreview;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FConditions Conditions;
    
    UAnimNotify_StateParticleEffect();
    
    // Fix for true pure virtual functions not being implemented
};

