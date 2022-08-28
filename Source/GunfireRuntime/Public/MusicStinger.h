#pragma once
#include "CoreMinimal.h"
#include "MusicStinger.generated.h"

class USoundCue;

USTRUCT(BlueprintType)
struct FMusicStinger {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USoundCue* Stinger;
    
    GUNFIRERUNTIME_API FMusicStinger();
};

