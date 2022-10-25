#pragma once
#include "CoreMinimal.h"
#include "SequencerPlayerSettings.h"
#include "OnLocalPlayerFinishedLevelSequenceDelegate.generated.h"

class AController;
class AActor;
class ULevelSequence;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnLocalPlayerFinishedLevelSequence, AController*, Controller, FSequencerPlayerSettings, SequenceSettings, ULevelSequence*, CurrentSequence, AActor*, SequenceInstigator);

