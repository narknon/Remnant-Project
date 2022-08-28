#pragma once
#include "CoreMinimal.h"
#include "SequencerPlayerSettings.h"
#include "OnSequencePlayingEventDelegate.generated.h"

class ULevelSequence;
class AActor;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_ThreeParams(FOnSequencePlayingEvent, FSequencerPlayerSettings, Settings, ULevelSequence*, CurrentSequence, AActor*, Instigator);

