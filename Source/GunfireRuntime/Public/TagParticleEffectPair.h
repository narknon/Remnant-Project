#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "TagParticleEffectPair.generated.h"

class UParticleSystem;
class UItemType;

USTRUCT(BlueprintType)
struct FTagParticleEffectPair {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UItemType> EquipmentType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName VisualTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UParticleSystem* PSTemplate;
    
    GUNFIRERUNTIME_API FTagParticleEffectPair();
};

