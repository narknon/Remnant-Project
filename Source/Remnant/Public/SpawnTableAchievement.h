#pragma once
#include "CoreMinimal.h"
#include "AchievementId.h"
#include "SpawnTableEntry.h"
#include "EAchievementUpdateType.h"
#include "SpawnTableAchievement.generated.h"

UCLASS(Blueprintable)
class REMNANT_API USpawnTableAchievement : public USpawnTableEntry {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FAchievementId Achievement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EAchievementUpdateType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Amount;
    
    USpawnTableAchievement();
};

