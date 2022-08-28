#include "RemnantGameInstance.h"

void URemnantGameInstance::OnOnlinePrivilegeChecked() {
}

void URemnantGameInstance::OnMainMenuLoaded() {
}

void URemnantGameInstance::OnDeviceChanged(int32 ControllerId, EInputDevice NewDevice) {
}

void URemnantGameInstance::OnActiveProfileSet() {
}

bool URemnantGameInstance::IsDemo() {
    return false;
}

ERemnantDemoMode URemnantGameInstance::GetDemoMode() {
    return ERemnantDemoMode::None;
}

void URemnantGameInstance::DoJoinViaPresence() {
}

void URemnantGameInstance::DoAuth() {
}


URemnantGameInstance::URemnantGameInstance() {
    this->CharacterManager = NULL;
}

