#include "RemnantPlayerController.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

class AItem;
class UItemType;
class AActor;
class UProgressionComponent;
class UItemAward;
class URemnantArchetype;
class ARemnantQuest;
class UWorld;
class UNetDriver;
class ACharacterGunfire;
class UObject;
class USpawnTable;
class UInventoryComponent;
class UAccountAward;
class AZoneActor;
class APawn;
class ACheckpoint;
class ULevelSequence;
class UEmote;

void ARemnantPlayerController::UpdatePlayState() {
}

void ARemnantPlayerController::UpdatePerformanceLevel() {
}

void ARemnantPlayerController::TravelPlayerTo(int32 DestZoneID, const FName& DestLink, bool bForce, bool bInstant) {
}

void ARemnantPlayerController::SwapCharacter(const FZoneLinkInfo& StartingWaypoint) {
}

void ARemnantPlayerController::SetReadyToTravel() {
}

void ARemnantPlayerController::SetIntroComplete() {
}

void ARemnantPlayerController::ServerWorldResetComplete_Implementation() {
}
bool ARemnantPlayerController::ServerWorldResetComplete_Validate() {
    return true;
}

void ARemnantPlayerController::ServerUpdateUsingMultiplayerFeatures_Implementation() {
}
bool ARemnantPlayerController::ServerUpdateUsingMultiplayerFeatures_Validate() {
    return true;
}

void ARemnantPlayerController::ServerUpdateLicensedContent_Implementation(const TArray<ELicensedContent>& Licenses) {
}
bool ARemnantPlayerController::ServerUpdateLicensedContent_Validate(const TArray<ELicensedContent>& Licenses) {
    return true;
}

void ARemnantPlayerController::ServerUnlockItemAward_Implementation(TSubclassOf<UItemAward> ItemAward, bool bDoNotify) {
}
bool ARemnantPlayerController::ServerUnlockItemAward_Validate(TSubclassOf<UItemAward> ItemAward, bool bDoNotify) {
    return true;
}

void ARemnantPlayerController::ServerUnlockAccountCurrency_Implementation(TSubclassOf<AItem> CurrencyType, int32 Quantity, bool bDoNotify) {
}
bool ARemnantPlayerController::ServerUnlockAccountCurrency_Validate(TSubclassOf<AItem> CurrencyType, int32 Quantity, bool bDoNotify) {
    return true;
}

void ARemnantPlayerController::ServerStreamSwapCharacter_Implementation(const TArray<uint8>& CharacterData) {
}
bool ARemnantPlayerController::ServerStreamSwapCharacter_Validate(const TArray<uint8>& CharacterData) {
    return true;
}

void ARemnantPlayerController::ServerStreamCharacterFinalize_Implementation() {
}
bool ARemnantPlayerController::ServerStreamCharacterFinalize_Validate() {
    return true;
}

void ARemnantPlayerController::ServerStreamCharacter_Implementation(const TArray<uint8>& CharacterData) {
}
bool ARemnantPlayerController::ServerStreamCharacter_Validate(const TArray<uint8>& CharacterData) {
    return true;
}

void ARemnantPlayerController::ServerSetCurrentLock_Implementation(EZoneTravelLock NewLock, bool bNewIsSaving, bool bNewWantsTravelMenuAccess) {
}
bool ARemnantPlayerController::ServerSetCurrentLock_Validate(EZoneTravelLock NewLock, bool bNewIsSaving, bool bNewWantsTravelMenuAccess) {
    return true;
}

void ARemnantPlayerController::ServerRespawnSwappedCharacter_Implementation(int32 ZoneID, FName ZoneNameId) {
}
bool ARemnantPlayerController::ServerRespawnSwappedCharacter_Validate(int32 ZoneID, FName ZoneNameId) {
    return true;
}

void ARemnantPlayerController::ServerRemoveTravelState_Implementation() {
}
bool ARemnantPlayerController::ServerRemoveTravelState_Validate() {
    return true;
}

void ARemnantPlayerController::ServerRemoveItem_Implementation(const FString& NameOfBP, int32 Quantity) {
}
bool ARemnantPlayerController::ServerRemoveItem_Validate(const FString& NameOfBP, int32 Quantity) {
    return true;
}

void ARemnantPlayerController::ServerReliableCameraLocationUpdate_Implementation(FVector_NetQuantize CamLoc) {
}
bool ARemnantPlayerController::ServerReliableCameraLocationUpdate_Validate(FVector_NetQuantize CamLoc) {
    return true;
}

void ARemnantPlayerController::ServerReadyToTravel_Implementation() {
}
bool ARemnantPlayerController::ServerReadyToTravel_Validate() {
    return true;
}

void ARemnantPlayerController::ServerReadyForWorldReset_Implementation() {
}
bool ARemnantPlayerController::ServerReadyForWorldReset_Validate() {
    return true;
}

void ARemnantPlayerController::ServerHandleSkipIntro_Implementation() {
}
bool ARemnantPlayerController::ServerHandleSkipIntro_Validate() {
    return true;
}

void ARemnantPlayerController::ServerGiveItem_Implementation(const FString& NameOfBP, int32 Quantity, int32 LevelOverride, bool bAutoEquip) {
}
bool ARemnantPlayerController::ServerGiveItem_Validate(const FString& NameOfBP, int32 Quantity, int32 LevelOverride, bool bAutoEquip) {
    return true;
}

void ARemnantPlayerController::ServerFinalizeStreamSwapCharacter_Implementation() {
}
bool ARemnantPlayerController::ServerFinalizeStreamSwapCharacter_Validate() {
    return true;
}

void ARemnantPlayerController::ServerDestinationZoneLoaded_Implementation() {
}
bool ARemnantPlayerController::ServerDestinationZoneLoaded_Validate() {
    return true;
}

void ARemnantPlayerController::ServerClearWaitingForZones_Implementation(int32 SyncCounter) {
}
bool ARemnantPlayerController::ServerClearWaitingForZones_Validate(int32 SyncCounter) {
    return true;
}

void ARemnantPlayerController::ServerBeginPlay_Implementation() {
}
bool ARemnantPlayerController::ServerBeginPlay_Validate() {
    return true;
}

void ARemnantPlayerController::ServerAddExperience_Implementation(UProgressionComponent* Progression, int32 Amount) {
}
bool ARemnantPlayerController::ServerAddExperience_Validate(UProgressionComponent* Progression, int32 Amount) {
    return true;
}

void ARemnantPlayerController::Respawn(const FZoneLinkInfo& StartingWaypoint) {
}

void ARemnantPlayerController::RemoveAccountAwardListener(const FOnReceiveAccountAwardDelegate& Event) {
}

void ARemnantPlayerController::RefreshAccountAwards() {
}

void ARemnantPlayerController::QueueValidClientSoftInventoryChange(TSoftClassPtr<AItem> ItemSoftRef, int32 Quantity, int32 ItemLevel, bool IsItemRemoval) {
}

void ARemnantPlayerController::QueueValidClientInventoryChange(TSubclassOf<AItem> ItemBP, int32 Quantity, int32 ItemLevel, bool IsItemRemoval) {
}

void ARemnantPlayerController::QueueManualQuestReward(ARemnantQuest* Quest, const TArray<TSoftClassPtr<AItem>>& Items, bool bSkipDuplicates, bool bAutoEquip, ERemnantQuestRewardType RewardType, int32 Quantity, int32 LevelOverride, bool bIsArchetype, bool bWantsSaveOnAward) {
}

void ARemnantPlayerController::OnSessionDisconnected(UWorld* InWorld, UNetDriver* NetDriver) {
}



void ARemnantPlayerController::OnPlayStateChanged(FName PreviousState, FName NewState) {
}


void ARemnantPlayerController::OnPlayerDied(uint8 Reason, ACharacterGunfire* DeadCharacter, AActor* Cause) {
}




void ARemnantPlayerController::OnFinishPlayStateTransition(FName NewState) {
}




void ARemnantPlayerController::NetUpdateActiveCharacter() {
}

void ARemnantPlayerController::MarkRevived() {
}

bool ARemnantPlayerController::IsPlayerDead() const {
    return false;
}

bool ARemnantPlayerController::IsIntroQuestDisabled(const UObject* WorldContextObject) {
    return false;
}

bool ARemnantPlayerController::IsIntroQuestComplete(const UObject* WorldContextObject) {
    return false;
}

bool ARemnantPlayerController::HasServerBegunPlay() const {
    return false;
}

bool ARemnantPlayerController::HasLicense(ELicensedContent License) {
    return false;
}

bool ARemnantPlayerController::HasGivenLicenses() {
    return false;
}


void ARemnantPlayerController::GiveQuestRewards(ARemnantQuest* Quest, USpawnTable* SpawnTable, TArray<FName> SpawnTags, ERemnantQuestRewardType RewardType, int32 RandomSeed, bool bSkipDuplicates) {
}

void ARemnantPlayerController::GiveAccountAward(TSubclassOf<UAccountAward> NewAward) {
}

float ARemnantPlayerController::GetTimeSinceLastInput() {
    return 0.0f;
}

bool ARemnantPlayerController::GetTargetZoneLink(FZoneLinkInfo& OutZoneLink, bool bSkipTravelDestination) {
    return false;
}

UInventoryComponent* ARemnantPlayerController::GetRelevantInventoryComponentForItemType(TSubclassOf<UItemType> ItemType) {
    return NULL;
}

UInventoryComponent* ARemnantPlayerController::GetRelevantInventoryComponentForItem(TSubclassOf<AItem> Item) {
    return NULL;
}

UInventoryComponent* ARemnantPlayerController::GetPlayerInventory() {
    return NULL;
}

AZoneActor* ARemnantPlayerController::GetCurrentZone() {
    return NULL;
}

EZoneTravelLock ARemnantPlayerController::GetCurrentTravelLock() const {
    return EZoneTravelLock::None;
}

APawn* ARemnantPlayerController::GetCurrentOrDeadPawn() const {
    return NULL;
}

EPingGenerationResult ARemnantPlayerController::GatherPing(FActionPing& OutPing) {
    return EPingGenerationResult::Success;
}

void ARemnantPlayerController::EnableWidgetComponentInteraction(bool bEnabled) {
}

int32 ARemnantPlayerController::ComputePowerLevel() {
    return 0;
}

int32 ARemnantPlayerController::ComputeItemLevel() {
    return 0;
}

void ARemnantPlayerController::ClientUpdateUsingMultiplayerFeatures_Implementation(bool bEnabled) {
}

void ARemnantPlayerController::ClientUpdateFogOfWar_Implementation(int32 ZoneID, const FVisitedCoordinates& VisitedCoordinatesMap) {
}

void ARemnantPlayerController::ClientUpdateAchievement_Implementation(FAchievementId AchievementName, int32 Progress, EAchievementUpdateType Type) {
}

void ARemnantPlayerController::ClientSetWaitingForZones_Implementation(int32 SyncCounter) {
}

void ARemnantPlayerController::ClientSetMusicState_Implementation(FName State) {
}

void ARemnantPlayerController::ClientOnSessionChanged_Implementation() {
}

void ARemnantPlayerController::ClientNotifyQuestReward_Implementation(const FRemnantQuestReward& QuestReward) {
}

void ARemnantPlayerController::ClientLoadDestinationZone_Implementation(int32 DestZoneID) {
}

void ARemnantPlayerController::ClientIncrementBossCounter_Implementation() {
}

void ARemnantPlayerController::ClientHandleDeceased_Implementation(bool bExitToMenu) {
}

void ARemnantPlayerController::ClientGiveAccountAward_Implementation(TSubclassOf<UAccountAward> NewAward) {
}

void ARemnantPlayerController::ClientFinishWorldReset_Implementation(ACheckpoint* ActivatedCheckpoint) {
}

void ARemnantPlayerController::ClientFinishTravel_Implementation(FTransform Destination) {
}

void ARemnantPlayerController::ClientBeginWorldReset_Implementation(ACheckpoint* ActivatedCheckpoint, bool bWasDead) {
}

void ARemnantPlayerController::ClientBeginTravel_Implementation(bool bRespawning, int32 PendingZoneID) {
}

void ARemnantPlayerController::ClearTravelLock(EZoneTravelLock Lock) {
}

void ARemnantPlayerController::ClearPawn(bool SetCurrentAsDead, bool ShouldClearDeadPawn) {
}

void ARemnantPlayerController::ClearDeadPawn() {
}

void ARemnantPlayerController::ClearCachedArchetype() {
}

bool ARemnantPlayerController::CanRespawnPlayers_Implementation() const {
    return false;
}

void ARemnantPlayerController::BroadcastPing_Implementation(const FActionPing& PingRequest) {
}
bool ARemnantPlayerController::BroadcastPing_Validate(const FActionPing& PingRequest) {
    return true;
}

void ARemnantPlayerController::BroadcastFinishedLevelSequence(FSequencerPlayerSettings DummySettings, ULevelSequence* CurrentSequence, AActor* SequenceInstigator) {
}

void ARemnantPlayerController::BroadcastEmote(TSubclassOf<UEmote> Emote) {
}

void ARemnantPlayerController::BroadcastClientFinishedLevelSequence_Implementation(FSequencerPlayerSettings SequenceSettings, ULevelSequence* CurrentSequence, AActor* SequenceInstigator) {
}
bool ARemnantPlayerController::BroadcastClientFinishedLevelSequence_Validate(FSequencerPlayerSettings SequenceSettings, ULevelSequence* CurrentSequence, AActor* SequenceInstigator) {
    return true;
}

void ARemnantPlayerController::AwardArchetype(URemnantArchetype* ArchetypeClass, ARemnantQuest* Quest, ERemnantQuestRewardType RewardType, bool bUseWhitelist, TArray<TSubclassOf<AItem>> WhitelistClasses, bool bAddTraits) {
}

EPingGenerationResult ARemnantPlayerController::AttemptPing() {
    return EPingGenerationResult::Success;
}

void ARemnantPlayerController::ApplyTravelLock(EZoneTravelLock Lock) {
}

void ARemnantPlayerController::AddAccountAwardListener(const FOnReceiveAccountAwardDelegate& Event) {
}

void ARemnantPlayerController::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARemnantPlayerController, bPrimaryWeaponToggled);
    DOREPLIFETIME(ARemnantPlayerController, bJoiningMustSpectate);
    DOREPLIFETIME(ARemnantPlayerController, RequiredZones);
    DOREPLIFETIME(ARemnantPlayerController, RequiredQuests);
    DOREPLIFETIME(ARemnantPlayerController, MusicState);
}

ARemnantPlayerController::ARemnantPlayerController() {
    this->TravelAction = NULL;
    this->LevelsOnDuplicateTrait = 1;
    this->bKeepPawnWhenTraveling = true;
    this->TravelState = EPlayerTravelState::Idle;
    this->TravelCleanupDelay = 1.50f;
    this->IntroQuestStartLink = TEXT("Start");
    this->bPrimaryWeaponToggled = false;
    this->bJoiningMustSpectate = false;
    this->CachedArchetype = NULL;
    this->CurrentZoneID = -1;
    this->PendingDestinationZoneID = -1;
    this->DestinationZoneID = -1;
    this->Respawning = false;
    this->LoadingState = TEXT("Loading");
    this->PendingTravelState = TEXT("PendingTravel");
    this->CinematicState = TEXT("Cinematic");
    this->FinalizeResetState = TEXT("FinalizeWorldReset");
    this->AliveResetState = TEXT("AliveWorldReset");
    this->RespawnedResetState = TEXT("RespawnedResetState");
    this->DeadResetState = TEXT("DeadResetState");
    this->SpectatingState = TEXT("Spectating");
    this->DyingState = TEXT("Dying");
    this->JoiningState = TEXT("Joining");
    this->AudioListenerPlayerCamLerp = 0.30f;
    this->AudioListenerPlayerOffset = 0.00f;
    this->DeadPawn = NULL;
    this->bIsJoining = true;
}

