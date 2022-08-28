#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "AchievementInfo.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UAchievementInfo : public UObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AchievementId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 UnlockAmount;
    
    UAchievementInfo();
    
    // Fix for true pure virtual functions not being implemented
};

