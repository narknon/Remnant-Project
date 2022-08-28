#include "RemnantWeaponMod.h"

class UObject;
class ARemnantRangedWeapon;

bool ARemnantWeaponMod::ShowReticule_Implementation() {
    return false;
}

void ARemnantWeaponMod::SetMinHoldTime(float HoldTime) {
}

void ARemnantWeaponMod::OnUse_Implementation() {
}


void ARemnantWeaponMod::OnSecondaryActivate_Implementation() {
}

void ARemnantWeaponMod::OnPreviewStart_Implementation() {
}

void ARemnantWeaponMod::OnPreviewEnd_Implementation() {
}

void ARemnantWeaponMod::OnPreFireEnd_Implementation() {
}

void ARemnantWeaponMod::OnPreFireBegin_Implementation() {
}

void ARemnantWeaponMod::OnPreActivate_Implementation() {
}

void ARemnantWeaponMod::OnFireEnd_Implementation() {
}

void ARemnantWeaponMod::OnFireBegin_Implementation() {
}

void ARemnantWeaponMod::OnFire_Implementation(const FVector& from, const FVector& to, float WeaponSpread) {
}

void ARemnantWeaponMod::OnFinishLoadingAssets() {
}

void ARemnantWeaponMod::OnEndUse_Implementation() {
}


void ARemnantWeaponMod::OnDeactivate_Implementation() {
}


void ARemnantWeaponMod::OnCharacterHitTarget(const FDamageInfo& DamageInfo) {
}

void ARemnantWeaponMod::OnBeginUse_Implementation() {
}

void ARemnantWeaponMod::OnActivate_Implementation() {
}

void ARemnantWeaponMod::ModifyModPower(float Delta) {
}

bool ARemnantWeaponMod::IsUseState(FName State) const {
    return false;
}

bool ARemnantWeaponMod::IsPreviewing() const {
    return false;
}

ARemnantRangedWeapon* ARemnantWeaponMod::GetWeapon() const {
    return NULL;
}

FName ARemnantWeaponMod::GetUseState() const {
    return NAME_None;
}

UClass* ARemnantWeaponMod::GetModAssetAsClass(FName AssetName) const {
    return NULL;
}

UObject* ARemnantWeaponMod::GetModAsset(FName AssetName) const {
    return NULL;
}

float ARemnantWeaponMod::GetModActiveRemainingPct_Implementation() {
    return 0.0f;
}

bool ARemnantWeaponMod::GetClientAimVector(FVector& AimOrigin, FVector& AimEnd) {
    return false;
}

bool ARemnantWeaponMod::CanUse_Implementation() {
    return false;
}

bool ARemnantWeaponMod::CanDeactivateMod_Implementation() {
    return false;
}

bool ARemnantWeaponMod::CalculateClientAimVector_Implementation(FVector& AimOrigin, FVector& AimEnd) {
    return false;
}

bool ARemnantWeaponMod::AreAssetsLoaded() const {
    return false;
}

void ARemnantWeaponMod::ApplyDamageInfoToModPower(const FDamageInfo& DamageInfo, float ModPowerScalar, bool bForce, bool bIgnorePenalties) {
}

void ARemnantWeaponMod::AddModPower_Implementation(float Damage, float BonusModPowerMod) {
}

ARemnantWeaponMod::ARemnantWeaponMod() {
    this->PowerBasis = 100.00f;
    this->MaxCharges = 1;
    this->InputMode = EModInputMode::Press;
    this->PreviewAnimTags.AddDefaulted(1);
    this->bStowWeaponForPreview = true;
    this->MinimumHoldTime = 0.20f;
    this->bUseAllChargesOnConsume = false;
    this->bToggleable = true;
    this->bHasSecondaryAction = false;
    this->bRequiresAllowActionForUse = true;
    this->bBlocksActionsWhileInUse = true;
    this->bStowWeaponForUseAnimation = false;
}

