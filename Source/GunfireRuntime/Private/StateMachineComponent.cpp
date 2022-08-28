#include "StateMachineComponent.h"
#include "Net/UnrealNetwork.h"

class UActorState;
class AActor;

void UStateMachineComponent::SetWindow(const FName& Name) {
}

bool UStateMachineComponent::SetState(const FName& NameID, bool bOnlySetIfValid) {
    return false;
}

void UStateMachineComponent::SetEvent(const FName& Name) {
}

void UStateMachineComponent::ServerSetTraversalState_Implementation(FStateID StateID, float Heading, const FVector& Position, uint8 CurrentClientAck) {
}
bool UStateMachineComponent::ServerSetTraversalState_Validate(FStateID StateID, float Heading, const FVector& Position, uint8 CurrentClientAck) {
    return true;
}

void UStateMachineComponent::ServerSetState_Implementation(FStateID StateID, float LockDirection, uint8 CurrentClientAck) {
}
bool UStateMachineComponent::ServerSetState_Validate(FStateID StateID, float LockDirection, uint8 CurrentClientAck) {
    return true;
}

void UStateMachineComponent::ServerSetInteractiveResult_Implementation(uint8 State, float MashValue) {
}
bool UStateMachineComponent::ServerSetInteractiveResult_Validate(uint8 State, float MashValue) {
    return true;
}

void UStateMachineComponent::ServerDoInteractive_Implementation(const FName& NameID, AActor* Other) {
}
bool UStateMachineComponent::ServerDoInteractive_Validate(const FName& NameID, AActor* Other) {
    return true;
}

bool UStateMachineComponent::ResetStateToDefault(bool bOnlySetIfValid) {
    return false;
}

void UStateMachineComponent::ProcessStateMachine(float DeltaTime) {
}

void UStateMachineComponent::OnRep_InteractiveInfo() {
}

void UStateMachineComponent::OnRep_CurrentStateID() {
}

void UStateMachineComponent::OnPostComputeStats() {
}

void UStateMachineComponent::MulticastDoFlinch_Implementation(FName NameID, FName HitLocation) {
}

bool UStateMachineComponent::IsWindowSet(const FName& Name) {
    return false;
}

bool UStateMachineComponent::IsInterruptible() const {
    return false;
}

bool UStateMachineComponent::IsEventSet(const FName& Name) {
    return false;
}

void UStateMachineComponent::InitAnimInstance() {
}

bool UStateMachineComponent::InInteractive() {
    return false;
}

FName UStateMachineComponent::GetStateName() {
    return NAME_None;
}

AActor* UStateMachineComponent::GetInteractiveOther() const {
    return NULL;
}

HitReactionType UStateMachineComponent::GetHitReactionType() {
    return HitReactionType::Flinch;
}

float UStateMachineComponent::GetElapsedStateTime() const {
    return 0.0f;
}

FString UStateMachineComponent::GetDebugInfo(int32 DebugLevel) {
    return TEXT("");
}

UActorState* UStateMachineComponent::GetCurrentState() {
    return NULL;
}

bool UStateMachineComponent::DoInteractive(const FName& NameID, AActor* Other) {
    return false;
}

void UStateMachineComponent::ClientSetState_Implementation(FStateID State, float LockDirection, uint8 CurrentClientAck) {
}

void UStateMachineComponent::ClientDoInteractive_Implementation(FInteractiveInfo Info, FStateID State, uint8 NewClientAck) {
}

void UStateMachineComponent::ClientAbortInteractive_Implementation() {
}

void UStateMachineComponent::ClearWindow(const FName& Name, bool bClearAll) {
}

void UStateMachineComponent::BeginLerp(float Time, bool LerpPosition, bool LerpRotation) {
}

void UStateMachineComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UStateMachineComponent, StartState);
    DOREPLIFETIME(UStateMachineComponent, InteractiveInfo);
    DOREPLIFETIME(UStateMachineComponent, CurrentStateID);
}

UStateMachineComponent::UStateMachineComponent() {
    this->StateMachine = NULL;
    this->AnimationLayer = TEXT("Base");
    this->FlinchAnimationLayer = TEXT("Flinch");
    this->Secondary = false;
    this->Character = NULL;
    this->CurrentState = NULL;
    this->AnimInstance = NULL;
}

