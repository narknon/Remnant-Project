#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ZoneConnection.h"
#include "RandomWorld.generated.h"

class UZone;

UCLASS(Blueprintable)
class REMNANT_API URandomWorld : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ZoneIDGen;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UZone*> Zones;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FZoneConnection> Connections;
    
    URandomWorld();
};

