#pragma once
#include "CoreMinimal.h"
#include "AIDirectorPlayer.generated.h"

class APlayerController;

USTRUCT(BlueprintType)
struct FAIDirectorPlayer {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APlayerController* Controller;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float Intensity;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float IntensityLastEventTime;
    
    GUNFIRERUNTIME_API FAIDirectorPlayer();
};

