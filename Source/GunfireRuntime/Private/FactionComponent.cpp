#include "FactionComponent.h"
#include "Net/UnrealNetwork.h"
#include "Templates/SubclassOf.h"

class UFaction;
class AActor;

void UFactionComponent::TakeDamage(const FDamageInfo& DamageInfo) {
}

void UFactionComponent::SetFactionOverride(TSubclassOf<UFaction> Faction, EAffiliation Affiliation) {
}

void UFactionComponent::SetFaction(TSubclassOf<UFaction> NewFaction) {
}

bool UFactionComponent::GetFactionOverride(TSubclassOf<UFaction> Faction, EAffiliation& Affiliation) {
    return false;
}

TSubclassOf<UFaction> UFactionComponent::GetFaction() const {
    return NULL;
}

EAffiliation UFactionComponent::GetAffiliation(AActor* OtherActor) {
    return EAffiliation::SuperFriendly;
}

void UFactionComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UFactionComponent, FactionOverrides);
}

UFactionComponent::UFactionComponent() {
    this->CachedFaction = NULL;
}

