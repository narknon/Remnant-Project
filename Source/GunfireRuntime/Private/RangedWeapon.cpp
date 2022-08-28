#include "RangedWeapon.h"
#include "Templates/SubclassOf.h"

class UParticleSystem;
class AActor;

void ARangedWeapon::TriggerSoundAwareness(float Radius) {
}

void ARangedWeapon::ToggleScopeInput(bool bRequiresAimInput) {
}

void ARangedWeapon::SetFireInput(FName FireInputName) {
}

void ARangedWeapon::ServerSetState_Implementation(uint8 InState) {
}
bool ARangedWeapon::ServerSetState_Validate(uint8 InState) {
    return true;
}

void ARangedWeapon::ServerFire_Implementation(FVector_NetQuantize from, const FReplicatedLocation& to, float WeaponSpread, uint32 RandomSeed, const FReplicatedHits& ClientHits) {
}
bool ARangedWeapon::ServerFire_Validate(FVector_NetQuantize from, const FReplicatedLocation& to, float WeaponSpread, uint32 RandomSeed, const FReplicatedHits& ClientHits) {
    return true;
}

void ARangedWeapon::Reload() {
}

void ARangedWeapon::PlayMuzzleFX(UParticleSystem* WeaponMuzzleFX, bool Attach) {
}

void ARangedWeapon::PlayFireAnimation(FName AnimationID) {
}

void ARangedWeapon::OnScopeInputPressed() {
}


void ARangedWeapon::OnPreFireEnd_Implementation() {
}

void ARangedWeapon::OnPreFireBegin_Implementation() {
}

void ARangedWeapon::OnFireEnd_Implementation() {
}

void ARangedWeapon::OnFireBegin_Implementation() {
}

void ARangedWeapon::OnFire_Implementation(const FVector& from, const FVector& to, float WeaponSpread) {
}

void ARangedWeapon::OnFinishLoadingScopePostProcess() {
}

void ARangedWeapon::OnDoubleClickScopeInputReleased() {
}

void ARangedWeapon::OnDoubleClickScopeInputPressed() {
}

void ARangedWeapon::MulticastSetStateNS_Implementation(uint8 InState) {
}

void ARangedWeapon::MulticastSetState_Implementation(uint8 InState) {
}

void ARangedWeapon::MulticastFire_Implementation(FVector_NetQuantize from, const FReplicatedLocation& to, float WeaponSpread, uint32 RandomSeed) {
}

bool ARangedWeapon::IsScopeInputEnabled() const {
    return false;
}

bool ARangedWeapon::IsReloading() const {
    return false;
}

bool ARangedWeapon::IsFiring() const {
    return false;
}

bool ARangedWeapon::IsBusy() const {
    return false;
}

bool ARangedWeapon::IsAimingWithScope() const {
    return false;
}

bool ARangedWeapon::IsAiming() const {
    return false;
}

bool ARangedWeapon::HasScope() const {
    return false;
}

FRangedWeaponMode ARangedWeapon::GetWeaponMode() const {
    return FRangedWeaponMode{};
}

int32 ARangedWeapon::GetSprayCount() const {
    return 0;
}

float ARangedWeapon::GetScopeFOV() const {
    return 0.0f;
}

float ARangedWeapon::GetRateOfFire() const {
    return 0.0f;
}

float ARangedWeapon::GetRange(bool bIncludeFalloff) const {
    return 0.0f;
}

FRandomStream ARangedWeapon::GetRandomStream() {
    return FRandomStream{};
}

FProjectileVisualizationContext ARangedWeapon::GetProjectileVisualization() {
    return FProjectileVisualizationContext{};
}

float ARangedWeapon::GetNormalizedSpread() {
    return 0.0f;
}

FHitResult ARangedWeapon::GetMuzzleObstruction() {
    return FHitResult{};
}

void ARangedWeapon::GetMuzzleFXPointAndDirection(FVector& MuzzlePoint, FVector& MuzzleDirection) {
}

int32 ARangedWeapon::GetMaxAmmo() const {
    return 0;
}

float ARangedWeapon::GetFalloff(bool bPrimaryFalloffOnly) const {
    return 0.0f;
}

float ARangedWeapon::GetDamageScalar(float Distance) const {
    return 0.0f;
}

float ARangedWeapon::GetCurrentSpread() {
    return 0.0f;
}

float ARangedWeapon::GetBurstRateOfFire() const {
    return 0.0f;
}

int32 ARangedWeapon::GetBurstCount() const {
    return 0;
}

int32 ARangedWeapon::GetAmmoPerReload() const {
    return 0;
}

int32 ARangedWeapon::GetAmmoPerClip() const {
    return 0;
}

int32 ARangedWeapon::GetAmmoInClip() const {
    return 0;
}

int32 ARangedWeapon::GetAmmo() const {
    return 0;
}

void ARangedWeapon::GetAimVector(FVector& from, FVector& to, bool bApplyAimAssist, bool bOverrideTrajectoryMode, ERangedWeaponTrajectoryMode TrajectoryModeOverride) {
}

FVector ARangedWeapon::GetAimTargetLocation() {
    return FVector{};
}

FHitResult ARangedWeapon::GetAimTarget() {
    return FHitResult{};
}

AActor* ARangedWeapon::FireProjectile(AActor* Cause, const FVector& Origin, const FVector& End, float WeaponSpread, TSubclassOf<AActor> ProjectileBP, float Velocity, bool bGroup) {
    return NULL;
}

void ARangedWeapon::FillClip(int32 Amount) {
}

void ARangedWeapon::EndUse() {
}

void ARangedWeapon::DoInstantHit(const FVector& Origin, const FVector& End, float WeaponSpread) {
}

void ARangedWeapon::DoImpact(const FHitResult& Hit) {
}

void ARangedWeapon::ConsumeAmmo(int32 Amount) {
}

void ARangedWeapon::ClearDoubleClickTimer() {
}

bool ARangedWeapon::CanStopAiming() const {
    return false;
}

bool ARangedWeapon::CanReload() const {
    return false;
}

bool ARangedWeapon::CanFire() const {
    return false;
}

void ARangedWeapon::BeginUse() {
}

void ARangedWeapon::BeginReload() {
}

void ARangedWeapon::ApplySpread(float Scalar) {
}

void ARangedWeapon::ApplyRecoil_Implementation(float Scalar) {
}

void ARangedWeapon::AddAmmo(int32 Amount, bool NewFillClip) {
}

ARangedWeapon::ARangedWeapon() {
    this->Profile = NULL;
    this->Reticule = NULL;
    this->FireWhileAimingOnly = true;
    this->AllowActionOnFlinch = false;
    this->ReloadAfterStartLoop = false;
    this->TrajectoryMode = ERangedWeaponTrajectoryMode::SocketToAimTarget;
    this->MuzzleObstructionDistance = 300.00f;
    this->ProjectileToVisualize = NULL;
    this->AmmoType = NULL;
    this->FireInput = TEXT("Fire");
    this->ReloadInput = TEXT("Reload");
    this->ReloadOnRelease = false;
    this->AimInput = TEXT("Aim");
    this->MinimumAimTime = 0.00f;
    this->ScopeReticule = NULL;
    this->ScopeWidget = NULL;
    this->ScopeInSound = NULL;
    this->ScopeOutSound = NULL;
    this->bUseCameraWhenAimingWithScope = false;
    this->MinimumAimDelayForScope = 0.20f;
    this->ReadyTime = 0.25f;
    this->ReloadStartTime = 0.00f;
    this->ReloadLoopTime = 0.00f;
    this->ReloadEndTime = 0.00f;
    this->ReloadTime = 0.50f;
    this->ReloadSpeed = 1.00f;
    this->MuzzleFX = NULL;
    this->AttachMuzzleFX = true;
    this->OutOfAmmoSoundCue = NULL;
    this->UseLowAmmoSounds = false;
    this->LowAmmoCount = 0;
    this->BulletWhizBySoundCue = NULL;
    this->BulletWhizByRadius = 150.00f;
    this->AmmoPoolComponent = NULL;
    this->Muzzle = NULL;
}

