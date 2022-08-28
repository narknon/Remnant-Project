#pragma once
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "MusicState.h"
#include "MusicStinger.h"
#include "MusicSet.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UMusicSet : public UDataAsset {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Priority;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeInTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeOutTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMusicState> States;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMusicStinger> Stingers;
    
    UMusicSet();
};

