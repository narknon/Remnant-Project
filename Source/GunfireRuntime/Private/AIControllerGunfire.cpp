#include "AIControllerGunfire.h"
#include "Templates/SubclassOf.h"
#include "PathSharingFilter_Default.h"
#include "AIDefaultTargetSelector.h"
#include "PathFollowingComponentGunfire.h"

class UObject;
class AActor;
class ACharacterGunfire;
class AAIPathPoint;
class AAIControllerGunfire;

void AAIControllerGunfire::UpdateAwareness(float DeltaSeconds) {
}

void AAIControllerGunfire::UnlockCurrentTarget() {
}

void AAIControllerGunfire::SetSpawnLocation(FVector SpawnLocation) {
}

void AAIControllerGunfire::SetRelevantActorFilterClass(TSubclassOf<AActor> FilterClass) {
}

void AAIControllerGunfire::SetCurrentTarget(AActor* Actor, bool bLockOn) {
}

void AAIControllerGunfire::SendAwarenessSignal(EAwarenessSignal Type, AActor* Source, const FVector& Position, float Radius, bool UseSourceForLastKnownPosition, bool bApplySightRangeBonus) {
}

void AAIControllerGunfire::ResetThreat() {
}

void AAIControllerGunfire::ResetAwareness() {
}

void AAIControllerGunfire::OnSetTacticalPoint_Implementation(const FAITacticalPoint& NewTacticalPoint) {
}

void AAIControllerGunfire::OnFactionChanged(ACharacterGunfire* InCharacter) {
}

void AAIControllerGunfire::OnClearTacticalPoint_Implementation() {
}

void AAIControllerGunfire::LockCurrentTarget() {
}

bool AAIControllerGunfire::HasLineOfSightToAnyPlayer() const {
    return false;
}

bool AAIControllerGunfire::HasLineOfSight(AActor* Actor) const {
    return false;
}

AActor* AAIControllerGunfire::GetThreatLeader() const {
    return NULL;
}

bool AAIControllerGunfire::GetTargetChangedThisFrame() const {
    return false;
}

bool AAIControllerGunfire::GetTacticalPointValid() {
    return false;
}

FAITacticalPoint AAIControllerGunfire::GetTacticalPoint() const {
    return FAITacticalPoint{};
}

AActor* AAIControllerGunfire::GetPathTarget(FVector& TargetPos, FName PathTargetName) const {
    return NULL;
}

AAIPathPoint* AAIControllerGunfire::GetPathPoint() const {
    return NULL;
}

TArray<AAIControllerGunfire*> AAIControllerGunfire::GetNearbyAI(const UObject* WorldContextObject, FVector Origin, float Radius, TArray<AAIControllerGunfire*> IgnoreList) {
    return TArray<AAIControllerGunfire*>();
}

AActor* AAIControllerGunfire::GetCurrentTarget() const {
    return NULL;
}

void AAIControllerGunfire::AddThreat(AActor* ThreatCharacter, float Amount, bool bApplySightRangeBonus) {
}

void AAIControllerGunfire::AddPersistentTarget(AActor* Target) {
}

AAIControllerGunfire::AAIControllerGunfire(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer.SetDefaultSubobjectClass<UPathFollowingComponentGunfire>(TEXT("PathFollowingComponent"))) {
    this->NavigationFilter = UPathSharingFilter_Default::StaticClass();
    this->bSeeksTargets = true;
    this->Persistent = false;
    this->SightRange = 2000.00f;
    this->SightAngle = 180.00f;
    this->LostSightRange = 4000.00f;
    this->BonusLostSightRange = 500.00f;
    this->NearSightRange = 300.00f;
    this->bNearSightRequiresLoS = true;
    this->SphereLOSRadius = 10.00f;
    this->HearingScalar = 1.00f;
    this->HearingOcclusionScalar = 0.75f;
    this->ThreatWindow = 45.00f;
    this->ThreatBonus = 0.75f;
    this->AlertTimeout = 60.00f;
    this->AlertGiveUpDistance = 100.00f;
    this->AlertGiveUpTimeout = 10.00f;
    this->AwareDistanceThreshold = 300.00f;
    this->AwarePulseRadius = 500.00f;
    this->EvaluateFriendlyTargets = false;
    this->ForceEvaluatePlayers = false;
    this->PathToLastKnownPosition = false;
    this->PerceptionScalar = 1.00f;
    this->CoverAimAdjustDistance = 70.00f;
    this->DefaultTargetSelector = UAIDefaultTargetSelector::StaticClass();
    this->CurrentTargetSelector = NULL;
    this->NodePathStatus = ENodePathStatus::Idle;
    this->RelevantActorClass = NULL;
    this->TacticalPointIsValid = false;
    this->PathToActor = NULL;
    this->PathPoint = NULL;
}

