#pragma once
#include "CoreMinimal.h"
#include "Engine/EngineTypes.h"
#include "StateTransientAnimNotify.h"
#include "EAnimImpactTraceDirection.h"
#include "EAnimImpactType.h"
#include "AnimNotify_ImpactEffect.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class GUNFIRERUNTIME_API UAnimNotify_ImpactEffect : public UStateTransientAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimImpactType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAnimImpactTraceDirection TraceDirection;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<ECollisionChannel> TraceChannel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TraceDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float UpTraceOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Bone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PlaySoundAttached;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxDistance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxAngleBetweenNormalAndTraceDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPlayAtAnyWaterSubmergeDepth;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStateTransient;
    
    UAnimNotify_ImpactEffect();
};

