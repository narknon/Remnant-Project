#include "SpawnedGrenade.h"
#include "Net/UnrealNetwork.h"
#include "Components/SkeletalMeshComponent.h"

class AGrenade;


void ASpawnedGrenade::OnRep_GrenadeRepData() {
}


float ASpawnedGrenade::GetGrenadeLifeSpan() const {
    return 0.0f;
}

AGrenade* ASpawnedGrenade::GetGrenadeItemCDO() const {
    return NULL;
}

void ASpawnedGrenade::Detonate() {
}

void ASpawnedGrenade::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(ASpawnedGrenade, GrenadeRepData);
}

ASpawnedGrenade::ASpawnedGrenade() {
    this->Grenade = NULL;
    this->Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
}

