#include "RemnantQuest.h"
#include "Net/UnrealNetwork.h"
#include "PersistenceComponent.h"
#include "PersistenceKeysComponent.h"

class ARemnantQuest;
class ARemnantCharacter;
class ARemnantPlayerController;
class USpawnTable;
class UInventoryComponent;

void ARemnantQuest::OnRep_Status() {
}

bool ARemnantQuest::IsLoaded() const {
    return false;
}

bool ARemnantQuest::HasLastCheckpoint() const {
    return false;
}

void ARemnantQuest::GiveRewardToPlayerController(ARemnantPlayerController* Player, USpawnTable* SpawnTable, FName SpawnTag, TArray<FName> AdditionalTags, ERemnantQuestRewardType RewardType, int32 RandomSeed, bool bSkipDuplicates) {
}

void ARemnantQuest::GiveRewardToPlayer(ARemnantCharacter* Player, USpawnTable* SpawnTable, FName SpawnTag, TArray<FName> AdditionalTags, ERemnantQuestRewardType RewardType) {
}

void ARemnantQuest::GiveReward(USpawnTable* SpawnTable, FName SpawnTag, TArray<FName> AdditionalTags, ERemnantQuestRewardType RewardType, bool bSkipDuplicates) {
}

ARemnantQuest* ARemnantQuest::GetRootQuest() {
    return NULL;
}

UInventoryComponent* ARemnantQuest::GetQuestInventory() {
    return NULL;
}

bool ARemnantQuest::GetObjectQuestValue(UClass* ObjectBP, int32& ObjectValue, float& OutSellScalar, int32& OutPickupValue) {
    return false;
}

int32 ARemnantQuest::GetLevel() {
    return 0;
}

FZoneLinkInfo ARemnantQuest::GetLastCheckpoint() const {
    return FZoneLinkInfo{};
}

FString ARemnantQuest::GetBiomeName() {
    return TEXT("");
}

TArray<FZoneLinkInfo> ARemnantQuest::GetAutoJoinZoneLinks_Implementation() {
    return TArray<FZoneLinkInfo>();
}

void ARemnantQuest::DeactivateQuest() {
}

void ARemnantQuest::AddQuestLootTags_Implementation(TArray<FName>& LootTags, bool& Rtn) {
}

void ARemnantQuest::ActivateQuest() {
}

void ARemnantQuest::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARemnantQuest, Level);
    DOREPLIFETIME(ARemnantQuest, Difficulty);
    DOREPLIFETIME(ARemnantQuest, SlotID);
    DOREPLIFETIME(ARemnantQuest, ZoneID);
    DOREPLIFETIME(ARemnantQuest, ParentQuestID);
    DOREPLIFETIME(ARemnantQuest, Status);
    DOREPLIFETIME(ARemnantQuest, LastCheckpointZoneID);
    DOREPLIFETIME(ARemnantQuest, LastCheckpointNameID);
}

ARemnantQuest::ARemnantQuest() {
    this->PersistenceComponent = CreateDefaultSubobject<UPersistenceComponent>(TEXT("Persistence"));
    this->PersistenceKeysComponent = CreateDefaultSubobject<UPersistenceKeysComponent>(TEXT("PersistenceKeys"));
    this->Type = ERemnantQuestType::Default;
    this->Rarity = ERemnantQuestRarity::Common;
    this->MaxUsageCount = 1;
    this->DebugState = ERemnantQuestDebugState::None;
    this->QuestGameMode = EQuestMode::Campaign;
    this->RequiredEntitlement = ELicensedContent::None;
    this->LevelMin = 0;
    this->LevelMax = 100;
    this->Level = 1;
    this->Difficulty = 1;
    this->SlotID = -1;
    this->ZoneID = -1;
    this->ParentQuestID = -1;
    this->Status = ERemnantQuestStatus::Unloaded;
    this->ItemValueTable = NULL;
    this->ParentQuestComponent = NULL;
    this->LastCheckpointZoneID = -2;
    this->ContainerLevel = NULL;
    this->Created = false;
}

