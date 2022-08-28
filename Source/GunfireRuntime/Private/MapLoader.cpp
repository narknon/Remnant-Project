#include "MapLoader.h"
#include "Templates/SubclassOf.h"

class UWorld;
class UObject;
class UPlayableMap;
class UMapLoader;

void UMapLoader::TravelToTransitionMap() {
}

void UMapLoader::TravelToNextMap() {
}

bool UMapLoader::OpenMapByName(UObject* WorldContextObject, const FString& MapName) {
    return false;
}

bool UMapLoader::OpenMap(UObject* WorldContextObject, TSubclassOf<UPlayableMap> Map) {
    return false;
}

void UMapLoader::OnPlayerEnterTransitionMap(UWorld* LoadedWorld) {
}

void UMapLoader::OnPlayerEnterNextMapDelayed() {
}

void UMapLoader::OnNextMapVisible() {
}

void UMapLoader::OnFadeScreenCompleted() {
}

void UMapLoader::LoadNotStreamableLevels() {
}

FString UMapLoader::GetNotStreamableMapSuffix() {
    return TEXT("");
}

UMapLoader* UMapLoader::GetMapLoader(UObject* WorldContextObject) {
    return NULL;
}

UMapLoader::UMapLoader() {
    this->TransitionLevel = NULL;
    this->FadeTime = 1.00f;
    this->bShouldWaitToFadeIntoLevel = false;
    this->GameInstance = NULL;
    this->CurrentWorld = NULL;
    this->NextWorld = NULL;
}

