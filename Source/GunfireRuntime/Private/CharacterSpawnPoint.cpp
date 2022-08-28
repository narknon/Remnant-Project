#include "CharacterSpawnPoint.h"
#include "Templates/SubclassOf.h"
#include "Components/CapsuleComponent.h"
#include "Components/SphereComponent.h"

class AActor;
class ACharacterGunfire;
class UPrimitiveComponent;

void ACharacterSpawnPoint::Spawn(float InDelay, bool IsRespawn, bool bUseDeferredOptimization) {
}

void ACharacterSpawnPoint::ResumeSpawner() {
}

void ACharacterSpawnPoint::ResetSpawn(bool ResetOneTimeEvents, bool ResetSpawnTimer, bool DestroySpawnedActors) {
}

void ACharacterSpawnPoint::RemoveCharacterProxy(AActor* Actor) {
}


void ACharacterSpawnPoint::PauseSpawner() {
}

void ACharacterSpawnPoint::OnTriggerEndOverlap(AActor* OverlappedActor, AActor* OtherActor) {
}

void ACharacterSpawnPoint::OnTriggerBeginOverlap(AActor* OverlappedActor, AActor* OtherActor) {
}

void ACharacterSpawnPoint::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex) {
}

void ACharacterSpawnPoint::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
}

void ACharacterSpawnPoint::OnProxyDestroyed(AActor* DestroyedActor) {
}

void ACharacterSpawnPoint::OnCharacterDestroyed(AActor* DestroyedActor) {
}

void ACharacterSpawnPoint::OnCharacterDead(uint8 Reason, ACharacterGunfire* Character, AActor* Cause) {
}

int32 ACharacterSpawnPoint::GetNumAliveSpawns() {
    return 0;
}

TSubclassOf<ACharacterGunfire> ACharacterSpawnPoint::GetEnemyTypeOverride_Implementation() {
    return NULL;
}

void ACharacterSpawnPoint::EnableSpawnPoint(bool InEnabled) {
}

bool ACharacterSpawnPoint::CanSpawnFromTriggers_Implementation() {
    return false;
}

bool ACharacterSpawnPoint::CanSpawnFromDelay_Implementation() {
    return false;
}

bool ACharacterSpawnPoint::CanSpawn() const {
    return false;
}

bool ACharacterSpawnPoint::CanRespawn() const {
    return false;
}

void ACharacterSpawnPoint::AddCharacterProxy(AActor* Actor) {
}

ACharacterSpawnPoint::ACharacterSpawnPoint() {
    this->bStartEnabled = true;
    this->EnemyType = NULL;
    this->VisualComponent = NULL;
    this->ArrowComponent = NULL;
    this->CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CharacterMeshCapsule"));
    this->PerceptionScalar = 1.00f;
    this->PatrolPath = NULL;
    this->SpawnPath = NULL;
    this->bApplyThreat = false;
    this->ThreatToApply = 1.00f;
    this->DelaySetting = ESpawnDelayType::DelayedSpawnAndTriggers;
    this->SpawnDelayMin = 0.00f;
    this->SpawnDelayMax = 0.00f;
    this->DesiredCharacters = 0;
    this->bUsesDeferredSpawnOptimization = true;
    this->bSpawnFromTrigger = false;
    this->bOneTimeTrigger = true;
    this->bSpawnOnProximity = false;
    this->bOneTimeProximity = true;
    this->SpawnSphereRadius = 0.00f;
    this->Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("ProximitySpawningSphere"));
    this->SpawnedCharacter = NULL;
    this->bUseEditorVisuals = true;
    this->MaxRespawns = 0;
    this->RespawnDelayMin = 0.00f;
    this->RespawnDelayMax = 0.00f;
    this->bSpawningEnabled = false;
    this->SpawnCount = 0;
    this->bIsPaused = false;
    this->SpawnPointManager = NULL;
}

