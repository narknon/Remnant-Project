#pragma once
#include "CoreMinimal.h"
#include "AmbientAudioChannel.generated.h"

class UAmbientAudioComponent;

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FAmbientAudioChannel {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Export, Transient)
    TWeakObjectPtr<UAmbientAudioComponent> PrimaryComponent;
    
    FAmbientAudioChannel();
};

