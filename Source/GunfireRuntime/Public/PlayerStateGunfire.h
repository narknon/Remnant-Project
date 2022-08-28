#pragma once
#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "PlayerStatePawnChangedDelegate.h"
#include "PlayerTalkingChangedDelegate.h"
#include "PlayerNameChangedDelegate.h"
#include "PlayerStateGunfire.generated.h"

class APawn;
class ACharacterGunfire;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API APlayerStateGunfire : public APlayerState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerStatePawnChanged OnPawnChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerTalkingChanged OnTalkingChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FPlayerNameChanged OnPlayerNameChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APawn* CachedPawn;
    
public:
    APlayerStateGunfire();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APawn* GetPlayerPawn() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacterGunfire* GetPlayerCharacter() const;
    
    UFUNCTION(BlueprintCallable)
    bool GetIsTalking();
    
};

