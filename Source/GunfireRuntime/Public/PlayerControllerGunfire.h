#pragma once
#include "CoreMinimal.h"
#include "OnStartedVisualLoggerDelegate.h"
#include "GameFramework/PlayerController.h"
#include "SpectateTargetChangedDelegateDelegate.h"
#include "CinematicDelegateDelegate.h"
#include "ELevelTransition.h"
#include "PlayerControllerGunfire.generated.h"

class AActor;
class UPlayStateComponent;
class ULevelSequence;
class APawn;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API APlayerControllerGunfire : public APlayerController {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnStartedVisualLogger OnStartedVisualLogger;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_SpectateTarget, meta=(AllowPrivateAccess=true))
    AActor* SpectateActor;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSpectateTargetChangedDelegate OnSpectateTargetChanged;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    UPlayStateComponent* PlayState;
    
    APlayerControllerGunfire();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void SpectateTarget(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void SpectatePrevPlayer();
    
    UFUNCTION(BlueprintCallable)
    void SpectateNextPlayer();
    
    UFUNCTION(BlueprintCallable)
    void SetGameInputEnabled(bool bEnabled);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUnlockAllTraits(int32 StartingLevel);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSpectateTarget(AActor* Actor);
    
    UFUNCTION(Server, Unreliable, WithValidation)
    void ServerRequestTime(uint16 ClientTime);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerOnLevelTransition(int32 LevelID, ELevelTransition TransitionType);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDropItem(const FString& NameOfBP, int32 Quantity, int32 LevelOverride, int32 Stacks);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDoAction(const FString& NameOfBP, bool bApplyToTarget);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerBeginSpectate();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAddTrait(const FString& NameOfBP, int32 Level);
    
    UFUNCTION(BlueprintCallable)
    void RestoreSpectateViewTarget();
    
    UFUNCTION(BlueprintCallable)
    void ResetPauseRefCount();
    
    UFUNCTION(BlueprintCallable)
    static void RemoveCinematicListener(const FCinematicDelegate& Event);
    
protected:
    UFUNCTION(BlueprintCallable)
    void QuitGame();
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ProposeToSkipCutscene(ULevelSequence* InSequence);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnRep_SpectateTarget();
    
public:
    UFUNCTION(NetMulticast, Reliable)
    void MulticastUnlockAchievement(uint8 Idx, uint8 Type, int32 Amount);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInCinematic() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsGameInputEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetSpectateTarget();
    
    UFUNCTION(BlueprintCallable)
    APawn* GetRelevantViewTarget();
    
    UFUNCTION(BlueprintCallable)
    APawn* GetRelevantPawn();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetPlayerIdentifier() const;
    
    UFUNCTION(Client, Unreliable)
    void ClientTimeReply(uint16 ServerTime, uint16 ClientTime);
    
    UFUNCTION(BlueprintCallable)
    void BeginSpectate();
    
    UFUNCTION(BlueprintCallable)
    void BeginPlaying();
    
    UFUNCTION(BlueprintCallable)
    static void AddCinematicListener(const FCinematicDelegate& Event);
    
};

