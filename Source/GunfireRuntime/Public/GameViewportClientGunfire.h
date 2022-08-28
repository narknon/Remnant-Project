#pragma once
#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "GameViewportFocusDelegateDelegate.h"
#include "GameViewportClientGunfire.generated.h"

UCLASS(Blueprintable, NonTransient)
class GUNFIRERUNTIME_API UGameViewportClientGunfire : public UGameViewportClient {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameViewportFocusDelegate OnGameViewportFocusEvent;
    
    UGameViewportClientGunfire();
};

