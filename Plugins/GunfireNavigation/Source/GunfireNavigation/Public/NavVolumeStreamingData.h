#pragma once
#include "CoreMinimal.h"
#include "AI/Navigation/NavigationDataChunk.h"
#include "NavVolumeStreamingData.generated.h"

class ULevel;

UCLASS(Abstract, Blueprintable)
class GUNFIRENAVIGATION_API UNavVolumeStreamingData : public UNavigationDataChunk {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULevel* Level;
    
    UNavVolumeStreamingData();
};

