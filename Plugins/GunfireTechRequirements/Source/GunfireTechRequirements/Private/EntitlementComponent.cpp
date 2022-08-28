#include "EntitlementComponent.h"

class UObject;

void UEntitlementComponent::ShowRevokedDialog() {
}

void UEntitlementComponent::RevokeLicense_Implementation() {
}

bool UEntitlementComponent::HasEntitlement(UObject* WorldContextObject, UObject* Object, bool NotifyIfUnlicensed) {
    return false;
}

ELicensedContent UEntitlementComponent::GetRequiredLicense(UObject* Object) {
    return ELicensedContent::PreOrderGladiator;
}

void UEntitlementComponent::CheckLicense() {
}

UEntitlementComponent::UEntitlementComponent() {
    this->RequiredLicense = ELicensedContent::DLC1;
    this->RevokeType = ERevokeType::Default;
}

