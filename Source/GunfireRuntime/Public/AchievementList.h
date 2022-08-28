#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "HierarchicalEditInterface.h"
#include "AchievementList.generated.h"

class UAchievementInfo;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UAchievementList : public UObject, public IHierarchicalEditInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UAchievementInfo*> Achievements;
    
    UAchievementList();
    
    // Fix for true pure virtual functions not being implemented
};

