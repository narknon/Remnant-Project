#include "MiniMapDisplayActor.h"
#include "Net/UnrealNetwork.h"

class UMiniMapPanel;
class AMiniMapActor;
class AActor;
class UUserWidget;

float AMiniMapDisplayActor::WorldToMapScale(float NewScale) const {
    return 0.0f;
}

FVector AMiniMapDisplayActor::WorldToMapCoord(const FVector& Coord) const {
    return FVector{};
}

void AMiniMapDisplayActor::UnregisterMiniMapPanel(UMiniMapPanel* Panel) {
}

void AMiniMapDisplayActor::SetOriginLocation(const FVector& WorldLocation) {
}

void AMiniMapDisplayActor::SetOrigin(AMiniMapActor* OriginActor) {
}

void AMiniMapDisplayActor::SetMiniMapMode_Implementation(const EMiniMapMode Mode) {
}

void AMiniMapDisplayActor::SetIsIndicator(AMiniMapActor* Actor, bool Indicator) {
}

void AMiniMapDisplayActor::SetDisplayLevel(int32 NewLevel) {
}

void AMiniMapDisplayActor::ServerSetScale_Implementation(float NewScale) {
}
bool AMiniMapDisplayActor::ServerSetScale_Validate(float NewScale) {
    return true;
}

void AMiniMapDisplayActor::ServerSetPanOffset_Implementation(FVector Offset) {
}
bool AMiniMapDisplayActor::ServerSetPanOffset_Validate(FVector Offset) {
    return true;
}

void AMiniMapDisplayActor::ServerSelect_Implementation(const FMiniMapActorRef& Actor, bool MultiSelect, bool bStaySelected) {
}
bool AMiniMapDisplayActor::ServerSelect_Validate(const FMiniMapActorRef& Actor, bool MultiSelect, bool bStaySelected) {
    return true;
}

void AMiniMapDisplayActor::ServerScaleTo_Implementation(float NewScale, float Time) {
}
bool AMiniMapDisplayActor::ServerScaleTo_Validate(float NewScale, float Time) {
    return true;
}

void AMiniMapDisplayActor::ServerPanTo_Implementation(const FVector& Offset, float Time) {
}
bool AMiniMapDisplayActor::ServerPanTo_Validate(const FVector& Offset, float Time) {
    return true;
}

void AMiniMapDisplayActor::ServerDeSelectAll_Implementation() {
}
bool AMiniMapDisplayActor::ServerDeSelectAll_Validate() {
    return true;
}

void AMiniMapDisplayActor::ServerDeSelect_Implementation(const FMiniMapActorRef& Actor) {
}
bool AMiniMapDisplayActor::ServerDeSelect_Validate(const FMiniMapActorRef& Actor) {
    return true;
}

void AMiniMapDisplayActor::Select(AMiniMapActor* Actor, bool MultiSelect, bool bStaySelected) {
}

void AMiniMapDisplayActor::ScaleTo(float NewScale, float Time) {
}

void AMiniMapDisplayActor::Scale(float NewScale) {
}

void AMiniMapDisplayActor::Rotate(const FRotator& Rotation) {
}

void AMiniMapDisplayActor::RegisterMiniMapPanel(UMiniMapPanel* Panel) {
}

void AMiniMapDisplayActor::PanToActor(AActor* MiniMapActor, float Time) {
}

void AMiniMapDisplayActor::PanTo(const FVector& Offset, float Time) {
}

void AMiniMapDisplayActor::Pan(const FVector& Translation) {
}

void AMiniMapDisplayActor::OnScale_Implementation(float NewScale) {
}

void AMiniMapDisplayActor::OnRotate_Implementation(const FRotator& Rotation) {
}

void AMiniMapDisplayActor::OnRep_SelectedActors() {
}




void AMiniMapDisplayActor::OnPan_Implementation(const FVector& Translation) {
}

void AMiniMapDisplayActor::OnMiniMapActorRemoved(int32 ID) {
}

void AMiniMapDisplayActor::OnMiniMapActorLevelChanged(int32 ID, int32 NewLevel) {
}

void AMiniMapDisplayActor::OnMiniMapActorAdded(int32 ID) {
}


void AMiniMapDisplayActor::MulticastSelectDeselect_Implementation(const FMiniMapActorRef& Actor) {
}

float AMiniMapDisplayActor::MapToWorldScale(float NewScale) const {
    return 0.0f;
}

FVector AMiniMapDisplayActor::MapToWorldCoord(const FVector& Coord) const {
    return FVector{};
}

bool AMiniMapDisplayActor::IsSelected(AMiniMapActor* Actor) const {
    return false;
}

bool AMiniMapDisplayActor::IsActorOnMiniMap(AActor* RefActor) const {
    return false;
}

void AMiniMapDisplayActor::InitMap(AActor* MiniMapRefActor) {
}

TArray<UUserWidget*> AMiniMapDisplayActor::GetWidgetsForActor(const FMiniMapEntry& MiniMapActor) const {
    return TArray<UUserWidget*>();
}

FBox AMiniMapDisplayActor::GetTotalBoundingBox() {
    return FBox{};
}

TArray<AMiniMapActor*> AMiniMapDisplayActor::GetSelectedActors() const {
    return TArray<AMiniMapActor*>();
}

AMiniMapActor* AMiniMapDisplayActor::GetSelectedActor() {
    return NULL;
}

void AMiniMapDisplayActor::GetMiniMapScreenWindow(FVector2D& OutOffset, float& OutScale) const {
}

FTransform AMiniMapDisplayActor::GetMiniMapScreenTransform(FMiniMapEntry& ReferenceActor) const {
    return FTransform{};
}

AActor* AMiniMapDisplayActor::GetMiniMapRefActor() const {
    return NULL;
}

TArray<FMiniMapActorInfo> AMiniMapDisplayActor::GetMinimapActors() const {
    return TArray<FMiniMapActorInfo>();
}

AMiniMapActor* AMiniMapDisplayActor::GetMiniMapActorFor(AActor* Actor) {
    return NULL;
}

AMiniMapActor* AMiniMapDisplayActor::GetLockedActor() const {
    return NULL;
}

int32 AMiniMapDisplayActor::GetDisplayLevel() const {
    return 0;
}

bool AMiniMapDisplayActor::GetActorByContext(int32 Context, FMiniMapEntry& OutMiniMapActor) const {
    return false;
}

bool AMiniMapDisplayActor::GetActor(AActor* RefActor, FMiniMapEntry& OutMiniMapActor) const {
    return false;
}

void AMiniMapDisplayActor::DeSelectAll() {
}

void AMiniMapDisplayActor::DeSelect(AMiniMapActor* Actor) {
}

void AMiniMapDisplayActor::CenterToOrigin() {
}

void AMiniMapDisplayActor::Center(AMiniMapActor* ActorToCenterOn, bool bLock) {
}

void AMiniMapDisplayActor::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(AMiniMapDisplayActor, Origin);
    DOREPLIFETIME(AMiniMapDisplayActor, CurrentScale);
    DOREPLIFETIME(AMiniMapDisplayActor, CurrentPanOffset);
    DOREPLIFETIME(AMiniMapDisplayActor, CurrentRotationOffset);
    DOREPLIFETIME(AMiniMapDisplayActor, SelectedActors);
}

AMiniMapDisplayActor::AMiniMapDisplayActor() {
    this->DisplayRange = 100.00f;
    this->MiniMapMode = EMiniMapMode::Mini;
    this->DefaultScaleMini = 1.00f;
    this->DefaultScaleFull = 1.00f;
    this->AutoInit = false;
    this->DisplayRangeVertical = -1.00f;
    this->MiniMapStyle = EMiniMapStyle::Is3D;
    this->HorizontalDisplayPower = 1.00f;
    this->ScaleMin = 0.00f;
    this->ScaleMax = 1.00f;
    this->bShouldClampPanOffset = true;
    this->NumChangeVisibilityPerFrame = 3;
    this->CurrentScale = 1.00f;
    this->LockedActor = NULL;
    this->MiniMapManager = NULL;
}

