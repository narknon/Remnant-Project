#include "UseableItem.h"

class AActor;

bool AUseableItem::ValidateUse_Implementation(AActor* Actor) {
    return false;
}

void AUseableItem::UseItem() {
}

void AUseableItem::Use_Implementation() {
}

void AUseableItem::ServerKeyPressed_Implementation() {
}
bool AUseableItem::ServerKeyPressed_Validate() {
    return true;
}

void AUseableItem::RemoveItem() {
}


void AUseableItem::MulticastSetState_Implementation(uint8 NewState) {
}

AUseableItem::AUseableItem() {
    this->Conditions = NULL;
    this->ActivationType = EUsableActivationType::Press;
    this->bConsumeInput = true;
    this->HoldTime = 0.00f;
}

