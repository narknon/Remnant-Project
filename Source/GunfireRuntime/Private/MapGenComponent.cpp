#include "MapGenComponent.h"
#include "Net/UnrealNetwork.h"

class UTileSet;
class AActor;
class AAudioCustomVolume;
class ULevel;
class UMapGenComponent;

void UMapGenComponent::OnStartedVisualLogger() {
}

void UMapGenComponent::OnRep_TilesBase() {
}

void UMapGenComponent::OnRep_MapACVClass() {
}

bool UMapGenComponent::IsTileVisited(int32 TileID) const {
    return false;
}

bool UMapGenComponent::IsTileActive(int32 TileID) const {
    return false;
}

bool UMapGenComponent::IsPositionInTile(const FVector& WorldPosition, const FTile& Tile) const {
    return false;
}

bool UMapGenComponent::IsEdgeOpen(AActor* Actor, float Tolerance) {
    return false;
}

UTileSet* UMapGenComponent::GetTileSet() {
    return NULL;
}

bool UMapGenComponent::GetTileForActor(AActor* Actor, FTile& Out) const {
    return false;
}

int32 UMapGenComponent::GetTileDistance(int32 TileID) const {
    return 0;
}

bool UMapGenComponent::GetTileAtPosition(const FVector& WorldPosition, FTile& Out) const {
    return false;
}

bool UMapGenComponent::GetSpawnTagsAtPosition(const FVector& WorldPosition, TArray<FName>& Out) const {
    return false;
}

ULevel* UMapGenComponent::GetMapGenLevelForActor(AActor* Actor) {
    return NULL;
}

int32 UMapGenComponent::GetMapGenDebugState() {
    return 0;
}

bool UMapGenComponent::GetMapGenAttributeForActor(EMapGenAttributeScope Scope, AActor* Actor, FName Key, FMapGenAttribute& Out) {
    return false;
}

AAudioCustomVolume* UMapGenComponent::GetMapACV() {
    return NULL;
}

float UMapGenComponent::GetLevelMaxSize(bool IncludeVista) const {
    return 0.0f;
}

FVector UMapGenComponent::GetLevelCenter(bool IncludeVista) const {
    return FVector{};
}

FBox UMapGenComponent::GetLevelBounds(bool IncludeVista) const {
    return FBox{};
}

bool UMapGenComponent::GetAttribute(EMapGenAttributeScope Scope, FName TileOrRegionID, FName Key, FMapGenAttribute& Out) {
    return false;
}

UMapGenComponent* UMapGenComponent::FindMapGenComponentForActor(AActor* Actor) {
    return NULL;
}

void UMapGenComponent::AddAttribute(FMapGenAttribute Attribute) {
}

void UMapGenComponent::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const {
    Super::GetLifetimeReplicatedProps(OutLifetimeProps);
    
    DOREPLIFETIME(UMapGenComponent, TemplateOverride);
    DOREPLIFETIME(UMapGenComponent, MapOffset);
    DOREPLIFETIME(UMapGenComponent, MapInstanceName);
    DOREPLIFETIME(UMapGenComponent, TilesBase);
    DOREPLIFETIME(UMapGenComponent, NoTiles);
    DOREPLIFETIME(UMapGenComponent, Attributes);
    DOREPLIFETIME(UMapGenComponent, ServerState);
    DOREPLIFETIME(UMapGenComponent, MapACVClass);
}

UMapGenComponent::UMapGenComponent() {
    this->Seed = -1;
    this->Level = 1;
    this->UseLoadedLevelAsTemplate = false;
    this->AutoInitialize = true;
    this->MapInstanceName = TEXT("Map");
    this->Settings = NULL;
    this->TemplateLevel = NULL;
    this->NavBounds = NULL;
    this->Generated = false;
    this->NoTiles = false;
    this->ServerState = EMapGenState::Uninitialized;
    this->MapACVClass = NULL;
    this->MapACV = NULL;
}

