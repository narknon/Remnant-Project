#include "Matchmaker.h"

class APlayerController;
class UObject;
class UMatchmaker;

void UMatchmaker::UpdateSession() {
}

void UMatchmaker::UpdateJoinability(bool isJoinable) {
}

void UMatchmaker::StartSession() {
}

void UMatchmaker::ShowSessionGamertagInfo(FBlueprintSessionResult SessionInfo) {
}

void UMatchmaker::SetSessionJoinability(bool isJoinable) {
}

void UMatchmaker::RejoinLastSession() {
}

void UMatchmaker::OnShowQueuedMatchmakingEventMessages() {
}

void UMatchmaker::OnSessionEndedEvent() {
}

void UMatchmaker::OnPlayerNameChanged() {
}

void UMatchmaker::OnMainMenuLoaded() {
}

void UMatchmaker::KickPlayer(APlayerController* PlayerController, bool Banned) {
}

void UMatchmaker::JoinSession(const FBlueprintSessionResult& SearchResult) {
}

bool UMatchmaker::IsSessionJoinable() {
    return false;
}

bool UMatchmaker::IsPresenceJoinURLValid() {
    return false;
}

bool UMatchmaker::IsOnline() {
    return false;
}

bool UMatchmaker::IsLocalCharacterSurvival() {
    return false;
}

bool UMatchmaker::IsLocalCharacterHardcore() {
    return false;
}

bool UMatchmaker::IsJoiningSession() const {
    return false;
}

bool UMatchmaker::IsFindingSessions() const {
    return false;
}

void UMatchmaker::InviteFriend() {
}

void UMatchmaker::Init(const UObject* WorldContextObject, APlayerController* PlayerController) {
}

FName UMatchmaker::GetSessionStateName() const {
    return NAME_None;
}

FSessionDetails UMatchmaker::GetSessionDetails(const FBlueprintSessionResult& Session) {
    return FSessionDetails{};
}

UMatchmaker* UMatchmaker::GetMatchmakerInstance(const UObject* WorldContextObject) {
    return NULL;
}

FString UMatchmaker::GetCurrentSessionDisplay() {
    return TEXT("");
}

void UMatchmaker::EndFindSessions() {
}

void UMatchmaker::DestroySession() {
}

void UMatchmaker::CreateSession(ESessionType SessionType, bool DisableJoinability) {
}

void UMatchmaker::ChangeSession(ESessionType NewSessionType, bool Force) {
}

bool UMatchmaker::CanRejoinLastSession() {
    return false;
}

bool UMatchmaker::CanJoinSessionGameMode(const UObject* WorldContextObject, const FBlueprintSessionResult& Session) {
    return false;
}

bool UMatchmaker::CanChangeSessiontype() {
    return false;
}

void UMatchmaker::BeginJoinPublicGame(ELastSearchType SearchType) {
}

void UMatchmaker::BeginFindSessions() {
}

UMatchmaker::UMatchmaker() {
    this->bMatchmakingDisabled = false;
    this->CurrentSessionType = ESessionType::Private;
}

