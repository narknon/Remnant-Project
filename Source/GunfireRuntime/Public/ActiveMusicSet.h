#pragma once
#include "CoreMinimal.h"
#include "ActiveMusicSet.generated.h"

class UMusicSet;
class UAudioComponent;
class UMusicManager;

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FActiveMusicSet {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMusicSet* MusicSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ReferenceCount;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CurrentState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DestinationState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UAudioComponent* IntroAudio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAudioComponent*> ActiveAudio;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, Transient, meta=(AllowPrivateAccess=true))
    UMusicManager* MusicManager;
    
    FActiveMusicSet();
};

