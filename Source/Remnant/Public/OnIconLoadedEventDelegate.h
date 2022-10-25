#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "OnIconLoadedEventDelegate.generated.h"

class UTexture2D;
class UEmote;

UDELEGATE(BlueprintCallable) DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnIconLoadedEvent, TSubclassOf<UEmote>, Emote, UTexture2D*, Icon);

