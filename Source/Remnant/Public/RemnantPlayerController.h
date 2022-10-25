#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "PlayerControllerGunfire.h"
#include "SequencerPlayerSettings.h"
#include "OnSetPawnEventDelegate.h"
#include "QuestRewardDelegateDelegate.h"
#include "OnLocalPlayerFinishedLevelSequenceDelegate.h"
#include "TravelCompleteDelegateDelegate.h"
#include "VisitedCoordinates.h"
#include "OnGivenLicensesEventDelegate.h"
#include "EPlayerTravelState.h"
#include "Engine/EngineTypes.h"
#include "RemnantQuestReward.h"
#include "RemnantClientInventoryChangeInfo.h"
#include "ZoneLinkInfo.h"
#include "ELicensedContent.h"
#include "EZoneTravelLock.h"
#include "Engine/NetSerialization.h"
#include "AchievementId.h"
#include "OnReceiveAccountAwardDelegateDelegate.h"
#include "ERemnantQuestRewardType.h"
#include "EAchievementUpdateType.h"
#include "UObject/NoExportTypes.h"
#include "EPingGenerationResult.h"
#include "ActionPing.h"
#include "RemnantPlayerController.generated.h"

class UActionBase;
class UWorld;
class URemnantArchetype;
class ARemnantQuest;
class UNetDriver;
class APawn;
class ACheckpoint;
class UAccountAward;
class UItemAward;
class AItem;
class UItemType;
class UProgressionComponent;
class ACharacterGunfire;
class AActor;
class UObject;
class USpawnTable;
class UInventoryComponent;
class AZoneActor;
class ULevelSequence;
class UEmote;

UCLASS(Blueprintable)
class REMNANT_API ARemnantPlayerController : public APlayerControllerGunfire {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSetPawnEvent OnSetPawn;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestRewardDelegate OnNotifyQuestReward;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTravelCompleteDelegate OnFinishTravelEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTravelCompleteDelegate OnBeginTravelEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UActionBase> TravelAction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 LevelsOnDuplicateTrait;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKeepPawnWhenTraveling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EPlayerTravelState TravelState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TravelCleanupDelay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftClassPtr<ARemnantQuest> IntroQuest;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName IntroQuestStartLink;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLocalPlayerFinishedLevelSequence OnLocalPlayerFinishedLevelSequence;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bPrimaryWeaponToggled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bJoiningMustSpectate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<int32> RequiredZones;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<int32> RequiredQuests;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle FinishTravelHandle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    URemnantArchetype* CachedArchetype;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 CurrentZoneID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 PendingDestinationZoneID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 DestinationZoneID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FName DestinationLink;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRemnantQuestReward> QueuedQuestRewards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FRemnantQuestReward> QueuedNotifyQueue;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FName MusicState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Respawning;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName LoadingState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PendingTravelState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CinematicState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FinalizeResetState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AliveResetState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName RespawnedResetState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DeadResetState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpectatingState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DyingState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName JoiningState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AudioListenerPlayerCamLerp;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AudioListenerPlayerOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> TeleportStates;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    APawn* DeadPawn;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsJoining;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<int32> PendingRewards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<int32> PendingCurrencyRewards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FRemnantClientInventoryChangeInfo> ClientValidatedInventoryExceptions;
    
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGivenLicensesEvent OnLicensesGiven;
    
    ARemnantPlayerController();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void UpdatePlayState();
    
    UFUNCTION(BlueprintCallable)
    void UpdatePerformanceLevel();
    
public:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void TravelPlayerTo(int32 DestZoneID, const FName& DestLink, bool bForce, bool bInstant);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SwapCharacter(const FZoneLinkInfo& StartingWaypoint);
    
    UFUNCTION(BlueprintCallable)
    void SetReadyToTravel();
    
public:
    UFUNCTION(BlueprintCallable)
    void SetIntroComplete();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerWorldResetComplete();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUpdateUsingMultiplayerFeatures();
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUpdateLicensedContent(const TArray<ELicensedContent>& Licenses);
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUnlockItemAward(TSubclassOf<UItemAward> ItemAward, bool bDoNotify);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerUnlockAccountCurrency(TSubclassOf<AItem> CurrencyType, int32 Quantity, bool bDoNotify);
    
protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerStreamSwapCharacter(const TArray<uint8>& CharacterData);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerStreamCharacterFinalize();
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerStreamCharacter(const TArray<uint8>& CharacterData);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetCurrentLock(EZoneTravelLock NewLock, bool bNewIsSaving, bool bNewWantsTravelMenuAccess);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRespawnSwappedCharacter(int32 ZoneID, FName ZoneNameId);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRemoveTravelState();
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerRemoveItem(const FString& NameOfBP, int32 Quantity);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerReliableCameraLocationUpdate(FVector_NetQuantize CamLoc);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerReadyToTravel();
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerReadyForWorldReset();
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerHandleSkipIntro();
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerGiveItem(const FString& NameOfBP, int32 Quantity, int32 LevelOverride, bool bAutoEquip);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerFinalizeStreamSwapCharacter();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDestinationZoneLoaded();
    
    UFUNCTION(BlueprintCallable, Server, Unreliable, WithValidation)
    void ServerClearWaitingForZones(int32 SyncCounter);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerBeginPlay();
    
public:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAddExperience(UProgressionComponent* Progression, int32 Amount);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void Respawn(const FZoneLinkInfo& StartingWaypoint);
    
    UFUNCTION(BlueprintCallable)
    static void RemoveAccountAwardListener(const FOnReceiveAccountAwardDelegate& Event);
    
    UFUNCTION(BlueprintCallable)
    void RefreshAccountAwards();
    
    UFUNCTION(BlueprintCallable)
    void QueueValidClientSoftInventoryChange(TSoftClassPtr<AItem> ItemSoftRef, int32 Quantity, int32 ItemLevel, bool IsItemRemoval);
    
    UFUNCTION(BlueprintCallable)
    void QueueValidClientInventoryChange(TSubclassOf<AItem> ItemBP, int32 Quantity, int32 ItemLevel, bool IsItemRemoval);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void QueueManualQuestReward(ARemnantQuest* Quest, const TArray<TSoftClassPtr<AItem>>& Items, bool bSkipDuplicates, bool bAutoEquip, ERemnantQuestRewardType RewardType, int32 Quantity, int32 LevelOverride, bool bIsArchetype, bool bWantsSaveOnAward);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnSessionDisconnected(UWorld* InWorld, UNetDriver* NetDriver);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnServerFinalizeTravel();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnReadyToTravel(int32 PendingZoneID);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPlayStateChanged(FName PreviousState, FName NewState);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPlayInEditor();
    
protected:
    UFUNCTION()
    void OnPlayerDied(uint8 Reason, ACharacterGunfire* DeadCharacter, AActor* Cause);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFinishWorldReset(ACheckpoint* ActivatedCheckpoint);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFinishTravelLoad();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFinishTravel();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnFinishPlayStateTransition(FName NewState);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnDeceased();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBeginWorldReset(ACheckpoint* ActivatedCheckpoint, bool bWasDead);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBeginTravel(int32 PendingZoneID);
    
protected:
    UFUNCTION(BlueprintCallable)
    void NetUpdateActiveCharacter();
    
public:
    UFUNCTION(BlueprintCallable)
    void MarkRevived();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPlayerDead() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsIntroQuestDisabled(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static bool IsIntroQuestComplete(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasServerBegunPlay() const;
    
    UFUNCTION(BlueprintCallable)
    bool HasLicense(ELicensedContent License);
    
    UFUNCTION(BlueprintCallable)
    bool HasGivenLicenses();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void HandleSkipIntro();
    
public:
    UFUNCTION(BlueprintCallable)
    void GiveQuestRewards(ARemnantQuest* Quest, USpawnTable* SpawnTable, TArray<FName> SpawnTags, ERemnantQuestRewardType RewardType, int32 RandomSeed, bool bSkipDuplicates);
    
    UFUNCTION(BlueprintCallable)
    void GiveAccountAward(TSubclassOf<UAccountAward> NewAward);
    
    UFUNCTION(BlueprintCallable)
    float GetTimeSinceLastInput();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    bool GetTargetZoneLink(FZoneLinkInfo& OutZoneLink, bool bSkipTravelDestination);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetRelevantInventoryComponentForItemType(TSubclassOf<UItemType> ItemType);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetRelevantInventoryComponentForItem(TSubclassOf<AItem> Item);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UInventoryComponent* GetPlayerInventory();
    
    UFUNCTION(BlueprintCallable)
    AZoneActor* GetCurrentZone();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    EZoneTravelLock GetCurrentTravelLock() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APawn* GetCurrentOrDeadPawn() const;
    
    UFUNCTION(BlueprintCallable)
    EPingGenerationResult GatherPing(FActionPing& OutPing);
    
    UFUNCTION(BlueprintCallable)
    void EnableWidgetComponentInteraction(bool bEnabled);
    
    UFUNCTION(BlueprintCallable)
    int32 ComputePowerLevel();
    
    UFUNCTION(BlueprintCallable)
    int32 ComputeItemLevel();
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientUpdateUsingMultiplayerFeatures(bool bEnabled);
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientUpdateFogOfWar(int32 ZoneID, const FVisitedCoordinates& VisitedCoordinatesMap);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientUpdateAchievement(FAchievementId AchievementName, int32 Progress, EAchievementUpdateType Type);
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetWaitingForZones(int32 SyncCounter);
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientSetMusicState(FName State);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientOnSessionChanged();
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientNotifyQuestReward(const FRemnantQuestReward& QuestReward);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientLoadDestinationZone(int32 DestZoneID);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientIncrementBossCounter();
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientHandleDeceased(bool bExitToMenu);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientGiveAccountAward(TSubclassOf<UAccountAward> NewAward);
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientFinishWorldReset(ACheckpoint* ActivatedCheckpoint);
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientFinishTravel(FTransform Destination);
    
public:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientBeginWorldReset(ACheckpoint* ActivatedCheckpoint, bool bWasDead);
    
protected:
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientBeginTravel(bool bRespawning, int32 PendingZoneID);
    
public:
    UFUNCTION(BlueprintCallable)
    void ClearTravelLock(EZoneTravelLock Lock);
    
    UFUNCTION(BlueprintCallable)
    void ClearPawn(bool SetCurrentAsDead, bool ShouldClearDeadPawn);
    
    UFUNCTION(BlueprintCallable)
    void ClearDeadPawn();
    
protected:
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void ClearCachedArchetype();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool CanRespawnPlayers() const;
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void BroadcastPing(const FActionPing& PingRequest);
    
    UFUNCTION(BlueprintCallable)
    void BroadcastFinishedLevelSequence(FSequencerPlayerSettings DummySettings, ULevelSequence* CurrentSequence, AActor* SequenceInstigator);
    
    UFUNCTION(BlueprintCallable)
    void BroadcastEmote(TSubclassOf<UEmote> Emote);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void BroadcastClientFinishedLevelSequence(FSequencerPlayerSettings SequenceSettings, ULevelSequence* CurrentSequence, AActor* SequenceInstigator);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void AwardArchetype(URemnantArchetype* ArchetypeClass, ARemnantQuest* Quest, ERemnantQuestRewardType RewardType, bool bUseWhitelist, TArray<TSubclassOf<AItem>> WhitelistClasses, bool bAddTraits);
    
    UFUNCTION(BlueprintCallable)
    EPingGenerationResult AttemptPing();
    
    UFUNCTION(BlueprintCallable)
    void ApplyTravelLock(EZoneTravelLock Lock);
    
    UFUNCTION(BlueprintCallable)
    static void AddAccountAwardListener(const FOnReceiveAccountAwardDelegate& Event);
    
};

