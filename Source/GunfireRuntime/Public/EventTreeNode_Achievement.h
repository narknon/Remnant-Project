#pragma once
#include "CoreMinimal.h"
#include "EventTreeNode.h"
#include "AchievementId.h"
#include "EAchievementUpdateType.h"
#include "EventTreeNode_Achievement.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UEventTreeNode_Achievement : public UEventTreeNode {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAchievementId Achievement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAchievementUpdateType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Amount;
    
public:
    UEventTreeNode_Achievement();
};

