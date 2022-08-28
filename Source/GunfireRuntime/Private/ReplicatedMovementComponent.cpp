#include "ReplicatedMovementComponent.h"
#include "Net/UnrealNetwork.h"

void UReplicatedMovementComponent::ServerMoveUpdate_Implementation(const FReplicatedMovementInfo& Info) {
}
bool UReplicatedMovementComponent::ServerMoveUpdate_Validate(const FReplicatedMovementInfo& Info) {
    return true;
}

void UReplicatedMovementComponent::OnRep_MovementInfo() {
}

void UReplicatedMovementComponent::ClientAckMove_Implementation(uint16 MoveTime) {
}

void UReplicatedMovementComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UReplicatedMovementComponent, MovementInfo);
}

UReplicatedMovementComponent::UReplicatedMovementComponent() {
    this->BufferTime = 100;
    this->ExtrapolationSmoothTime = 0.04f;
    this->ExtrapolationTeleportThresh = 500.00f;
}

