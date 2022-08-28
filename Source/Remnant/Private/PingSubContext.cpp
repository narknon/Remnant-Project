#include "PingSubContext.h"

bool UPingSubContext::IsValidForPingType(EPingType Type) const {
    return false;
}

UPingSubContext::UPingSubContext() {
    this->PingType = 255;
    this->TownLock = ETownLock::NoLock;
    this->Icon = NULL;
    this->WorldIconOverride = NULL;
    this->ShouldOverrideWorldColor = false;
}

