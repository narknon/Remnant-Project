#include "InputDeviceManager.h"

class UInputDeviceManager;
class UObject;

void UInputDeviceManager::ResetKeyboardIconCache() {
}

void UInputDeviceManager::OnImageSetLoaded() {
}

bool UInputDeviceManager::IsUsingAltImageSet() {
    return false;
}

UInputDeviceManager* UInputDeviceManager::GetInstance() {
    return NULL;
}

UObject* UInputDeviceManager::GetImage(FName NameID) {
    return NULL;
}

EInputDevice UInputDeviceManager::GetCurrentDeviceInUse(int32 ControllerId) {
    return EInputDevice::None;
}

UInputDeviceManager::UInputDeviceManager() {
    this->ImageSet = NULL;
}

