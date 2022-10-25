#pragma once
#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "OnPlayerStateDelegateDelegate.h"
#include "GameStateGunfire.generated.h"

class AGameStateGunfire;
class UTimeDilationManager;
class UObject;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AGameStateGunfire : public AGameState {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UTimeDilationManager* TimeDilationManager;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlayerStateDelegate OnPlayerJoined;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPlayerStateDelegate OnPlayerLeft;
    
    AGameStateGunfire();
protected:
    UFUNCTION(BlueprintCallable)
    void StartMatch();
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static AGameStateGunfire* GetGunfireGameState(const UObject* WorldContextObject);
    
};

