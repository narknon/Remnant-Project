#include "WeaponComponent.h"

class AActor;
class UStatsComponent;

void UWeaponComponent::NotifyHitTarget_Implementation(const FDamageInfo& DamageInfo) {
}

void UWeaponComponent::ModifyInspectInfo(AActor* Actor, const FInspectInfo& In, FInspectInfo& Out) {
}

void UWeaponComponent::ModifyDamage_Implementation(FDamageInfo& Info, bool& Rtn) {
}

void UWeaponComponent::ComputeStats_Implementation(UStatsComponent* Stats) {
}

UWeaponComponent::UWeaponComponent() {
}

