#include "Grenade.h"
#include "Net/UnrealNetwork.h"
#include "Components/SkeletalMeshComponent.h"
#include "WeaponAffinityComponent.h"

class AActor;
class AGrenade;

bool AGrenade::ValidateUse_Implementation() {
    return false;
}

void AGrenade::Throw() {
}

void AGrenade::ServerThrowPressed_Implementation(FVector_NetQuantize TargetLocation) {
}
bool AGrenade::ServerThrowPressed_Validate(FVector_NetQuantize TargetLocation) {
    return true;
}

void AGrenade::ServerKeyPressed_Implementation(FVector_NetQuantize TargetLocation) {
}
bool AGrenade::ServerKeyPressed_Validate(FVector_NetQuantize TargetLocation) {
    return true;
}

void AGrenade::OnRep_State(EGrenadeState PreviousState) {
}

void AGrenade::MulticastThrown_Implementation() {
}

void AGrenade::MulticastPlayThrowAnim_Implementation() {
}

void AGrenade::MulticastPlayEquipAnim_Implementation() {
}

float AGrenade::GetTotalGrenadeLifeSpan() const {
    return 0.0f;
}

float AGrenade::GetRemainingGrenadeLifeSpan() const {
    return 0.0f;
}

float AGrenade::GetRange() const {
    return 0.0f;
}

bool AGrenade::GetDetonatesWhenStoppedMoving() const {
    return false;
}

float AGrenade::GetDamageRadius() const {
    return 0.0f;
}

float AGrenade::GetDamage() const {
    return 0.0f;
}

void AGrenade::CalculateGrenadePath(AActor* Projectile, AActor* Thrower, AGrenade* GrenadeItem, const FVector& StartLocation, const FVector& StartVelocity, float SimulationTime, TArray<FPredictProjectilePathPointData>& OutPath, int32& OutNumBounces) {
}

void AGrenade::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AGrenade, State);
}

AGrenade::AGrenade() {
    this->ActivationType = EUsableActivationType::Press;
    this->bConsumeInput = true;
    this->HoldTime = 0.00f;
    this->ThrowInput = TEXT("Fire");
    this->DrawPathVisualization = false;
    this->ProximityVisualActorBP = NULL;
    this->Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
    this->WeaponAffinity = CreateDefaultSubobject<UWeaponAffinityComponent>(TEXT("WeaponAffinity"));
    this->SpawnedGrenadeBP = NULL;
    this->MaxBounces = 10;
    this->StopSpeed = 300.00f;
    this->EnergyLossAlongNormal = 0.50f;
    this->EnergyLossAgainstNormal = 0.75f;
    this->TraceRadius = 20.00f;
    this->ThrowSpeed = 3000.00f;
    this->GravityZ = -980.00f;
    this->MinimumTargetDistance = 200.00f;
    this->State = EGrenadeState::Inactive;
}

