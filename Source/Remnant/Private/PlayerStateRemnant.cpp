#include "PlayerStateRemnant.h"
#include "Net/UnrealNetwork.h"

void APlayerStateRemnant::SetIsLocalPlayerTarget(bool IsTarget) {
}

void APlayerStateRemnant::ServerSetChatRestricted_Implementation(bool ChatRestricted) {
}
bool APlayerStateRemnant::ServerSetChatRestricted_Validate(bool ChatRestricted) {
    return true;
}

void APlayerStateRemnant::OnRep_Traveling() {
}

void APlayerStateRemnant::OnRep_ChatRestricted() {
}

bool APlayerStateRemnant::IsTraveling() const {
    return false;
}

bool APlayerStateRemnant::IsChatRestricted() {
    return false;
}

void APlayerStateRemnant::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(APlayerStateRemnant, bTraveling);
    DOREPLIFETIME(APlayerStateRemnant, bIsChatRestricted);
    DOREPLIFETIME(APlayerStateRemnant, bIsHost);
}

APlayerStateRemnant::APlayerStateRemnant() {
    this->bTraveling = false;
    this->bIsChatRestricted = false;
    this->bIsLocalPlayerTarget = false;
    this->bIsHost = false;
}

