#pragma once
#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "AchievementHelpers.generated.h"

class UAchievementList;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UAchievementHelpers : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAchievementList* AchievementListCached;
    
public:
    UAchievementHelpers();
};

