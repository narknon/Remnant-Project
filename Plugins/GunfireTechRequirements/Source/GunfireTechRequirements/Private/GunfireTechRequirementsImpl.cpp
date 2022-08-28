#include "GunfireTechRequirementsImpl.h"

class UCameraComponent;
class APlayerController;
class UGunfireTechRequirementsImpl;
class UObject;

void UGunfireTechRequirementsImpl::ShowSwitchPlatformGameProfile() {
}

void UGunfireTechRequirementsImpl::ShowOfflineMessage() {
}

void UGunfireTechRequirementsImpl::SetVoipEnabled(bool Enabled) {
}

void UGunfireTechRequirementsImpl::SetUsingMultiplayerFeatures(bool IsUsing) {
}

void UGunfireTechRequirementsImpl::SetPresenceLocation(EPresenceContent Location) {
}

void UGunfireTechRequirementsImpl::SetHasSeenLegalScreen() {
}

void UGunfireTechRequirementsImpl::SetActiveController(APlayerController* Controller) {
}

void UGunfireTechRequirementsImpl::PrepForPressAnyKeyDialog() {
}

void UGunfireTechRequirementsImpl::MuteVOIP(bool bMute) {
}

void UGunfireTechRequirementsImpl::MainMenuLoaded() {
}

bool UGunfireTechRequirementsImpl::IsVoipPTTEnabled() {
    return false;
}

bool UGunfireTechRequirementsImpl::IsVoipMuted() {
    return false;
}

bool UGunfireTechRequirementsImpl::IsVoipEnabled() {
    return false;
}

bool UGunfireTechRequirementsImpl::IsUsingMultiplayerFeatures() {
    return false;
}

bool UGunfireTechRequirementsImpl::IsProfileValid() {
    return false;
}

bool UGunfireTechRequirementsImpl::IsPremiumServiceAvailable() {
    return false;
}

bool UGunfireTechRequirementsImpl::IsFullGameAvailable() const {
    return false;
}

bool UGunfireTechRequirementsImpl::IsControllerConnected() {
    return false;
}

bool UGunfireTechRequirementsImpl::IsChatRestricted() {
    return false;
}

bool UGunfireTechRequirementsImpl::HasLicense(ELicensedContent License) const {
    return false;
}

bool UGunfireTechRequirementsImpl::HasCheckedOnlinePrivilege() {
    return false;
}

EPresenceContent UGunfireTechRequirementsImpl::GetPresenceLocation() {
    return EPresenceContent::MENU;
}

FString UGunfireTechRequirementsImpl::GetPlatformGameProfileUserName() {
    return TEXT("");
}

TArray<ELicensedContent> UGunfireTechRequirementsImpl::GetLicensedContent() {
    return TArray<ELicensedContent>();
}

UGunfireTechRequirementsImpl* UGunfireTechRequirementsImpl::GetGunfireTechRequirementsImpl(UObject* WorldContextObject) {
    return NULL;
}

void UGunfireTechRequirementsImpl::EnableVoipPTT(bool Enabled) {
}

void UGunfireTechRequirementsImpl::CustomLogin(EAlternateLoginType Type) {
}

void UGunfireTechRequirementsImpl::CheckOnlinePrivilege() {
}

void UGunfireTechRequirementsImpl::CheckOnlineCommunicationPrivilege() {
}

bool UGunfireTechRequirementsImpl::CanRequestCustomLogin() {
    return false;
}

void UGunfireTechRequirementsImpl::AnyKeyPressed(APlayerController* PlayerController) {
}

void UGunfireTechRequirementsImpl::AdjustCameraFoVForAspect(bool bIgnoreFovSlider, UCameraComponent* CameraComponent) {
}

void UGunfireTechRequirementsImpl::AddStatusChangedEvent(ETechReqStatusChange Event, float Delay) {
}

UGunfireTechRequirementsImpl::UGunfireTechRequirementsImpl() {
    this->NetworkFailReason = ETechReqStatusChange::Normal;
    this->PrivilegeFailReason = ETechReqStatusChange::Normal;
    this->bHasSeenLegalScreen = false;
}

