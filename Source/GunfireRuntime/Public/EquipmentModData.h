#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "EquipmentModData.generated.h"

class AEquipmentMod;

USTRUCT(BlueprintType)
struct FEquipmentModData {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, SaveGame)
    uint8 ModSlot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TSubclassOf<AEquipmentMod> Mod;
    
    UPROPERTY(EditAnywhere, SaveGame)
    uint8 ModLevel;
    
    GUNFIRERUNTIME_API FEquipmentModData();
};

