#include "Builder.h"

void ABuilder::TryPlace() {
}

void ABuilder::ServerTryPlace_Implementation() {
}
bool ABuilder::ServerTryPlace_Validate() {
    return true;
}

void ABuilder::ExitBuilder() {
}

ABuilder::ABuilder() {
    this->HighlightMaterial = NULL;
    this->PawnToDeploy = NULL;
}

