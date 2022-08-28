#pragma once
#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "OnStopCameraFadeDelegateDelegate.h"
#include "PlayerCameraManagerGunfire.generated.h"

UCLASS(Blueprintable, NonTransient)
class GUNFIRERUNTIME_API APlayerCameraManagerGunfire : public APlayerCameraManager {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnStopCameraFadeDelegate OnStopCameraFadeEvent;
    
    APlayerCameraManagerGunfire();
    UFUNCTION(BlueprintCallable)
    void SetFadeLock(bool Enabled);
    
};

