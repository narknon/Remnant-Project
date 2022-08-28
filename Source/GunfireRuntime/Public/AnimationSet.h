#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "AnimationID.h"
#include "AnimationSet.generated.h"

class UAnimationSet;
class USkeleton;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UAnimationSet : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UAnimationSet* Template;
    
    UPROPERTY(AssetRegistrySearchable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USkeleton* Skeleton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAnimationID> AnimationsIDs;
    
    UAnimationSet();
};

