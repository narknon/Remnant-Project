#include "MiniMapActor.h"

class AActor;
class AMiniMapDisplayActor;

void AMiniMapActor::UpdateLevelVisibility_Implementation(int32 DisplayLevel, int32 MyLevel) {
}

void AMiniMapActor::SetShown(bool bShown) {
}

void AMiniMapActor::Select(bool MultiSelect, bool bStaySelected) {
}

void AMiniMapActor::OnShown_Implementation() {
}

void AMiniMapActor::OnSelected_Implementation() {
}

void AMiniMapActor::OnMiniMapSet_Implementation(AMiniMapDisplayActor* MiniMapActor) {
}

void AMiniMapActor::OnHidden_Implementation() {
}

void AMiniMapActor::OnDeSelected_Implementation() {
}

bool AMiniMapActor::IsSelected() const {
    return false;
}

AActor* AMiniMapActor::GetRefActor() const {
    return NULL;
}

AActor* AMiniMapActor::GetMiniMapRefActor() const {
    return NULL;
}

AMiniMapDisplayActor* AMiniMapActor::GetMiniMap() const {
    return NULL;
}

bool AMiniMapActor::GetIsActorVisibleOnMiniMap() const {
    return false;
}

int32 AMiniMapActor::GetContext() const {
    return 0;
}

void AMiniMapActor::DeSelect() {
}

void AMiniMapActor::DebugSetContext(int32 Value) {
}

void AMiniMapActor::Center(bool bLock) {
}

bool AMiniMapActor::CanSelect_Implementation() const {
    return false;
}

AMiniMapActor::AMiniMapActor() {
    this->Context = 0;
    this->RefActor = NULL;
    this->MiniMap = NULL;
    this->SnappedToEdge = false;
}

