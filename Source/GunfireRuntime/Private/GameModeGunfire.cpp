#include "GameModeGunfire.h"
#include "Templates/SubclassOf.h"
#include "GameRules.h"

class APlayableLevelCollection;
class ULevelStreaming;
class APlayerController;
class APlayableLevel;
class AActor;
class UDamageTypeGunfire;
class UImpactDirection;

void AGameModeGunfire::RemoveLevelInstanceByName(const FString& UniqueInstanceName) const {
}

void AGameModeGunfire::RemoveLevelInstance(ULevelStreaming* LevelInstance) const {
}

void AGameModeGunfire::OnPlayerDied_Implementation(APlayerController* Player) {
}

APlayableLevelCollection* AGameModeGunfire::GetPlayableLevelCollection(const FName& CollectionName) {
    return NULL;
}

APlayableLevel* AGameModeGunfire::GetPlayableLevelByPath(const FString& Path, const FName& CollectionName) {
    return NULL;
}

APlayableLevel* AGameModeGunfire::GetPlayableLevelByName(const FString& Name, const FName& CollectionName) {
    return NULL;
}

void AGameModeGunfire::GetLevelInstance(const FString& UniqueInstanceName, ULevelStreaming*& LevelInstance) const {
}

void AGameModeGunfire::ApplyDamage(AActor* CauseActor, AActor* TargetActor, float Damage, float DamageMod, float DamageScalar, TSubclassOf<UDamageTypeGunfire> DamageType, TSubclassOf<UImpactDirection> ImpactDirection) {
}

void AGameModeGunfire::AddPlayableLevel(APlayableLevel* Level, const FName& CollectionName) {
}

void AGameModeGunfire::AddLevelInstance(const FString& UniqueInstanceName, const FString& PackageNameToLoad, const FTransform& LevelTransform, ULevelStreaming*& LevelInstance) {
}

AGameModeGunfire::AGameModeGunfire() {
    this->GameRulesClass = AGameRules::StaticClass();
    this->GameRules = NULL;
}

