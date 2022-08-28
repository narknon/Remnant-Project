#pragma once
#include "CoreMinimal.h"
#include "EquipmentModData.h"
#include "EquipmentMods.generated.h"

USTRUCT(BlueprintType)
struct FEquipmentMods {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FEquipmentModData> Mods;
    
    GUNFIRERUNTIME_API FEquipmentMods();
};

