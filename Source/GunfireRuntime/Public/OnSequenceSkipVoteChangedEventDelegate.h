#pragma once
#include "CoreMinimal.h"
#include "OnSequenceSkipVoteChangedEventDelegate.generated.h"

class APlayerGunfire;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSequenceSkipVoteChangedEvent, const TArray<APlayerGunfire*>&, RelevantPlayers, bool, ShouldSkip);

