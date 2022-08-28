#pragma once
#include "CoreMinimal.h"
#include "Conditions.h"
#include "Animation/AnimNotifies/AnimNotifyState_Trail.h"
#include "OptimizableNotifyInterface.h"
#include "ENotifyOptimizationType.h"
#include "AnimNotifyState_StateTrail.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GUNFIRERUNTIME_API UAnimNotifyState_StateTrail : public UAnimNotifyState_Trail, public IOptimizableNotifyInterface {
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
    
    UAnimNotifyState_StateTrail();
    
    // Fix for true pure virtual functions not being implemented
};

