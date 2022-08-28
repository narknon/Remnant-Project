#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNode_AssetPlayerBase.h"
#include "AnimNode_PlayAnimSetAnim.generated.h"

class UAnimSequenceBase;

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FAnimNode_PlayAnimSetAnim : public FAnimNode_AssetPlayerBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimSequenceBase* Sequence;
    
public:
    FAnimNode_PlayAnimSetAnim();
};

