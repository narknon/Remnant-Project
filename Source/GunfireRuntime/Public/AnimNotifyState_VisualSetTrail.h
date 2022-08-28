#pragma once
#include "CoreMinimal.h"
#include "AnimNotifyState_StateTrail.h"
#include "TagParticleEffectPair.h"
#include "AnimNotifyState_VisualSetTrail.generated.h"

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GUNFIRERUNTIME_API UAnimNotifyState_VisualSetTrail : public UAnimNotifyState_StateTrail {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTagParticleEffectPair> ParticleSystems;
    
    UAnimNotifyState_VisualSetTrail();
};

