#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "MapSettings.generated.h"

class UPlayableMap;

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FMapSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPlayableMap> Map;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bBlockLoad;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bServeAsTransition;
    
    FMapSettings();
};

