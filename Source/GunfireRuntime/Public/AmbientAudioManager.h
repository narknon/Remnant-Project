#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "AmbientSoundMix.h"
#include "AmbientAudioManager.generated.h"

class USoundMix;
class UInterpolatedSoundMix;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UAmbientAudioManager : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<USoundMix*, FAmbientSoundMix> ActiveMixes;
    
    UPROPERTY(EditAnywhere, Transient)
    TArray<TWeakObjectPtr<UInterpolatedSoundMix>> InactiveMixes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    USoundMix* BaseMix;
    
public:
    UAmbientAudioManager();
};

