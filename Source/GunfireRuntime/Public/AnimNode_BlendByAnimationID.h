#pragma once
#include "CoreMinimal.h"
#include "Animation/AnimNodeBase.h"
#include "AlphaBlend.h"
#include "Animation/AnimNodeBase.h"
#include "AnimNode_BlendByAnimationID_Animation.h"
#include "AnimNode_BlendByAnimationID_Anim.h"
#include "Animation/AnimationAsset.h"
#include "AnimNode_BlendByAnimationID.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FAnimNode_BlendByAnimationID : public FAnimNode_Base {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPoseLink BasePose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, EditFixedSize, meta=(AllowPrivateAccess=true))
    TArray<FPoseLink> BlendPose;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAnimNode_BlendByAnimationID_Animation> Animations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AnimationLayerID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAlphaBlendOption BlendType;
    
protected:
    UPROPERTY(EditAnywhere)
    FAnimNode_BlendByAnimationID_Anim ActiveAnims[4];
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBlendSampleData> PerBoneSampleData;
    
public:
    FAnimNode_BlendByAnimationID();
};

