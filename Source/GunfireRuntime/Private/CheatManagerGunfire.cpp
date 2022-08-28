#include "CheatManagerGunfire.h"

void UCheatManagerGunfire::UnlockAllTraits(int32 StartingLevel) {
}

void UCheatManagerGunfire::ToggleSecondaryFlyCamera() {
}

void UCheatManagerGunfire::TogglePrimaryFlyCamera() {
}

void UCheatManagerGunfire::ToggleFollowPlayer() {
}

void UCheatManagerGunfire::TakeScreenShotWithDimensions(int32 ResX, int32 ResY) {
}

void UCheatManagerGunfire::TakeScreenShotCurrentResolutionScaled(int32 ScaleResolution) {
}

void UCheatManagerGunfire::SpawnCharacter(const FString& NameOfCharBP) {
}

void UCheatManagerGunfire::SetPlayerState(FName NewState) {
}

void UCheatManagerGunfire::SetPlayerNormalizedHealth(float NewHealth) {
}

void UCheatManagerGunfire::SetKillRadius(float NewKillRadius) {
}

void UCheatManagerGunfire::SendCommandToConsole(const FString& Command) {
}

void UCheatManagerGunfire::RemoveItem(const FString& NameOfBP, int32 Quantity) {
}

void UCheatManagerGunfire::OnUseDebugCommandKey() {
}

void UCheatManagerGunfire::OnReleaseDebugCommandKey() {
}

void UCheatManagerGunfire::KillNearbyEnemies() {
}

void UCheatManagerGunfire::IncreasePlayerLevel(int32 NumLevel) {
}

void UCheatManagerGunfire::GiveItem(const FString& NameOfBP, int32 Quantity, int32 LevelOverride, bool bAutoEquip) {
}

void UCheatManagerGunfire::GiveAllItems(const FString& NameOfClassBP, int32 Quantity, int32 LevelOverride, bool bOnlyUnique) {
}

TArray<FString> UCheatManagerGunfire::GetInputDescriptorForCheat(FName ActionName) {
    return TArray<FString>();
}

TArray<FString> UCheatManagerGunfire::GetConsoleCommands(const FString& Category) {
    return TArray<FString>();
}

FText UCheatManagerGunfire::GetConsoleCommandDescription(const FString& Command) {
    return FText::GetEmpty();
}

TArray<FString> UCheatManagerGunfire::GetConsoleCommandCategories() {
    return TArray<FString>();
}

TArray<FCheatInputAction> UCheatManagerGunfire::GetAllCheats() {
    return TArray<FCheatInputAction>();
}

void UCheatManagerGunfire::ForceCrash() {
}

void UCheatManagerGunfire::ExecuteCheat(FName ActionName) {
}

void UCheatManagerGunfire::EnablePrimaryFlyCamera() {
}

void UCheatManagerGunfire::DropItem(const FString& NameOfBP, int32 Quantity, int32 LevelOverride, int32 Stacks) {
}

void UCheatManagerGunfire::DoAction(const FString& NameOfBP, bool bApplyToTarget) {
}

void UCheatManagerGunfire::ClearAllDialogs() {
}

bool UCheatManagerGunfire::AreCheatsEnabled() {
    return false;
}

void UCheatManagerGunfire::AddTrait(const FString& NameOfBP, int32 Level) {
}

UCheatManagerGunfire::UCheatManagerGunfire() {
}

