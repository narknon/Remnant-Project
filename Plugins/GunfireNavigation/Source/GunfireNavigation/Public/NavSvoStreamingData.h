#pragma once
#include "CoreMinimal.h"
#include "NavVolumeStreamingData.h"
#include "NavSvoStreamingData.generated.h"

UCLASS(Blueprintable)
class GUNFIRENAVIGATION_API UNavSvoStreamingData : public UNavVolumeStreamingData {
    GENERATED_BODY()
public:
    UNavSvoStreamingData();
};

