#include "RemnantCharacter.h"
#include "Net/UnrealNetwork.h"
#include "EmotesComponent.h"
#include "VisualComponent.h"
#include "RemnantPlayerInventoryComponent.h"

class ACharacterGunfire;
class AActor;
class UGameUserSettingsGunfire;
class ASpawnPoint;
class UActionBuff;
class ARemnantPlayerController;
class ACheckpoint;
class UUserSetting;
class ARangedWeapon;
class USavedCharacter;

void ARemnantCharacter::UpdatePlayerInfoTag() {
}

void ARemnantCharacter::UpdatePersistentBuffs() {
}

void ARemnantCharacter::TeleportToSpawnPoint(AActor* SpawnPoint) {
}

void ARemnantCharacter::SetSpawnPoint(ASpawnPoint* SpawnPoint) {
}

void ARemnantCharacter::SetOldController(ARemnantPlayerController* PreviousController) {
}

void ARemnantCharacter::SetHelmetShown(bool bShow) {
}

void ARemnantCharacter::SetGrabbedCheckpoint(ACheckpoint* NewCheckpoint) {
}

void ARemnantCharacter::SetDeactivated() {
}

void ARemnantCharacter::ServerSetHelmetShown_Implementation(bool bShow) {
}
bool ARemnantCharacter::ServerSetHelmetShown_Validate(bool bShow) {
    return true;
}

void ARemnantCharacter::ResetAmmoInClip() {
}

void ARemnantCharacter::RemovePersistentBuff(const UActionBuff* Buff) {
}

void ARemnantCharacter::OnShowHelmetOptionChanged(UUserSetting* AppliedSetting, UGameUserSettingsGunfire* UserSettings) {
}


void ARemnantCharacter::OnRep_ShowHelmet() {
}

void ARemnantCharacter::OnRep_GrabbedCheckpoint(ACheckpoint* Previous) {
}

void ARemnantCharacter::OnRep_Deactivated() {
}

void ARemnantCharacter::OnCharacterDied(uint8 Reason, ACharacterGunfire* Character, AActor* Cause) {
}

bool ARemnantCharacter::IsReviving() const {
    return false;
}

bool ARemnantCharacter::IsDead() const {
    return false;
}

void ARemnantCharacter::InitializePersistentBuffs() {
}

ARemnantPlayerController* ARemnantCharacter::GetOldController() const {
    return NULL;
}

ARangedWeapon* ARemnantCharacter::GetCurrentRangedWeapon() const {
    return NULL;
}

USavedCharacter* ARemnantCharacter::GetCharacterInfo() {
    return NULL;
}

int32 ARemnantCharacter::GetAge() const {
    return 0;
}

int32 ARemnantCharacter::ComputePowerLevel() const {
    return 0;
}

int32 ARemnantCharacter::ComputeOffenseLevel() {
    return 0;
}

int32 ARemnantCharacter::ComputeDefenseLevel() {
    return 0;
}

void ARemnantCharacter::ClientTeleportToSpawnPoint_Implementation(ASpawnPoint* SpawnPoint) {
}

void ARemnantCharacter::ClientTeleport_Implementation(FTransform Transform) {
}

void ARemnantCharacter::ClientSetSpawnPoint_Implementation(const FPersistenceKey& SpawnPointID) {
}

void ARemnantCharacter::ClientRemoveAllPings_Implementation() {
}

void ARemnantCharacter::AddPersistentBuff(const UActionBuff* Buff) {
}

void ARemnantCharacter::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ARemnantCharacter, Gender);
    DOREPLIFETIME(ARemnantCharacter, bHasAggro);
    DOREPLIFETIME(ARemnantCharacter, ControllerIndex);
    DOREPLIFETIME(ARemnantCharacter, ShowHelmet);
    DOREPLIFETIME(ARemnantCharacter, GrabbedCheckpoint);
    DOREPLIFETIME(ARemnantCharacter, bDeactivated);
}

ARemnantCharacter::ARemnantCharacter() {
    this->VisualComp = CreateDefaultSubobject<UVisualComponent>(TEXT("VisualComp"));
    this->Inventory = CreateDefaultSubobject<URemnantPlayerInventoryComponent>(TEXT("Inventory"));
    this->Emotes = CreateDefaultSubobject<UEmotesComponent>(TEXT("Emotes"));
    this->FemaleAnimInstanceClass = NULL;
    this->FemaleSkeletalMesh = NULL;
    this->FemaleVisualSet = NULL;
    this->Gender = EGender::Female;
    this->bHasAggro = false;
    this->ControllerIndex = -1;
    this->LastUsedItemId = -1;
    this->ShowHelmet = true;
    this->HelmetSlot = TEXT("Helmet");
    this->ShowHelmetOption = TEXT("ShowHelmet");
    this->GrabbedCheckpoint = NULL;
    this->PrimaryWeaponType = NULL;
    this->ObstructedAdditionalDistance = 10.00f;
    this->ObstructedAdditionalRadius = 0.50f;
    this->bDeactivated = false;
    this->OldController = NULL;
    this->bOnlyExitDialogFromHostileDamage = true;
    this->bManualIgnoreDamageExitingDialog = false;
    this->LocalValidationPawn = NULL;
}

