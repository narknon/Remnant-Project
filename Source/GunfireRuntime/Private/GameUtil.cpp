#include "GameUtil.h"
#include "Templates/SubclassOf.h"

class UForceFeedbackEffect;
class AActor;
class UCurveFloat;
class USceneComponent;
class ACharacter;
class USkeletalMeshComponent;
class APlayerController;
class UPoseableMeshComponent;
class ULevel;
class UObject;
class ULevelStreaming;
class USkinnedMeshComponent;
class UCameraShake;
class APawn;
class UBehaviorTree;
class UShapeComponent;
class UMaterialInterface;
class UAdvancedDecalComponent;
class UPrimitiveComponent;
class APlayerState;
class ALevelScriptActor;
class UGameViewportClientGunfire;
class UActorComponent;
class UWorld;
class APlayerStart;
class ACharacterGunfire;
class UDamageTypeGunfire;

FRotator UGameUtil::UE4ToAutodeskRotation(const FRotator& Rotation) {
    return FRotator{};
}

void UGameUtil::TransferPoseToSkeletalMesh(USkeletalMeshComponent* Source, USkeletalMeshComponent* Target) {
}

void UGameUtil::TransferPoseToPoseableMesh(USkeletalMeshComponent* Source, UPoseableMeshComponent* Target) {
}

bool UGameUtil::TestLineOfSightFromLocation(FVector Origin, AActor* to, const TArray<AActor*>& IgnoredActors) {
    return false;
}

bool UGameUtil::TestLineOfSight(AActor* from, AActor* to, const TArray<AActor*>& IgnoredActors) {
    return false;
}

bool UGameUtil::SweepCharacter(UObject* WorldContextObject, ACharacter* Character, const FVector& Start, const FVector& End, const TArray<AActor*>& IgnoredActors, const TArray<TEnumAsByte<ECollisionChannel>>& IgnoreChannels, const TArray<TEnumAsByte<ECollisionChannel>>& OverlapChannels, const TArray<TEnumAsByte<ECollisionChannel>>& BlockChannels, FHitResult& Hit, float RadiusOverride, float HalfHeightOverride, FVector SweepOffset, bool bMoveCharacter) {
    return false;
}

bool UGameUtil::StuckCheckForClass(UObject* WorldContextObject, FVector FeetLocation, TSubclassOf<ACharacter> CharacterClass, const TArray<AActor*>& IgnoredActors, float RadiusOverride) {
    return false;
}

bool UGameUtil::StuckCheck(UObject* WorldContextObject, FVector FeetLocation, const ACharacter* Character, const TArray<AActor*>& IgnoredActors, float RadiusOverride) {
    return false;
}

void UGameUtil::StreamInTextures(const FVector& Position) {
}

void UGameUtil::StopForceFeedback(const UObject* WorldContextObject, UForceFeedbackEffect* ForceFeedbackEffect, FName Tag, int32 PlayerIndex) {
}

void UGameUtil::StopCameraShake(const UObject* WorldContextObject, TSubclassOf<UCameraShake> CameraShake, bool bSkipBlendOut, int32 PlayerIndex) {
}

APawn* UGameUtil::SpawnAIEx(UObject* WorldContextObject, TSubclassOf<APawn> PawnClass, UBehaviorTree* BehaviorTree, FVector Location, FRotator Rotation, bool bNoCollisionFail, ELevelContextFallback LevelContextFallback, AActor* LevelContext) {
    return NULL;
}

UAdvancedDecalComponent* UGameUtil::SpawnAdvancedDecalAttached(UMaterialInterface* DecalMaterial, FVector DecalSize, USceneComponent* AttachToComponent, FName AttachPointName, FVector Location, FRotator Rotation, TEnumAsByte<EAttachLocation::Type> LocationType, float LifeSpan, UCurveFloat* EmissiveCurve, UCurveFloat* OpacityCurve, bool bSetLifespan) {
    return NULL;
}

UAdvancedDecalComponent* UGameUtil::SpawnAdvancedDecalAtLocation(const UObject* WorldContextObject, UMaterialInterface* DecalMaterial, FVector DecalSize, FVector Location, FRotator Rotation, float LifeSpan, UCurveFloat* EmissiveCurve, UCurveFloat* OpacityCurve, bool bSetLifespan) {
    return NULL;
}

AActor* UGameUtil::SpawnActorEx(UObject* WorldContextObject, TSubclassOf<AActor> ActorClass, const FTransform& SpawnTransform, ESpawnActorCollisionHandlingMethod CollisionHandling, AActor* Owner, APawn* Instigator, bool Transient, ELevelContextFallback LevelContextFallback, AActor* LevelContext, ULevel* OverrideLevel) {
    return NULL;
}

void UGameUtil::SortObjectArray(TArray<UObject*>& Objects, const FObjectArraySortPredicate& Predicate) {
}

void UGameUtil::SortIntArray(TArray<int32>& IntArray) {
}

void UGameUtil::SortFloatArray(TArray<float>& FloatArray) {
}

void UGameUtil::SortActorArrayByDistance(FVector Location, TArray<AActor*>& ActorArray) {
}

bool UGameUtil::SnapToNavMesh(UObject* WorldContextObject, const FVector& Position, float Radius, FVector& SnappedPosition) {
    return false;
}

bool UGameUtil::SnapToGround(UObject* WorldContextObject, const FVector& Position, FVector& SnappedPosition, float Offset, float CastDistance, bool TraceComplex) {
    return false;
}

bool UGameUtil::SnapCharacterToGround(ACharacter* Character, const FVector& Position, const TArray<AActor*>& IgnoredActors, float Offset, float CastDistance) {
    return false;
}

void UGameUtil::ShowRandomMesh(AActor* Actor, FName Slot, bool AllowNone) {
}

void UGameUtil::ShowComponents(TArray<USceneComponent*> Components) {
}

bool UGameUtil::ShouldAsyncLoad() {
    return false;
}

void UGameUtil::SetVisible(AActor* Actor, bool Visible) {
}

void UGameUtil::SetVisibilityFlag(AActor* Actor, bool Active) {
}

void UGameUtil::SetTickableWhenPaused(AActor* Actor, bool TickWhenPaused) {
}

void UGameUtil::SetRenderCustomDepthForActor(AActor* Actor, bool bEnabled, uint8 Index, bool bPropagateToInventory) {
}

void UGameUtil::SetMaterialVectorParam(AActor* Actor, UMaterialInterface* Material, const FName& ParamName, FLinearColor Value) {
}

void UGameUtil::SetMaterialScalarParam(AActor* Actor, UMaterialInterface* Material, const FName& ParamName, float Value) {
}

void UGameUtil::SetComponentMaterialVectorParamForAll(UPrimitiveComponent* Component, const FName& ParamName, FLinearColor Value) {
}

void UGameUtil::SetComponentMaterialVectorParam(UPrimitiveComponent* Component, UMaterialInterface* Material, const FName& ParamName, FLinearColor Value) {
}

void UGameUtil::SetComponentMaterialScalarParamForAll(UPrimitiveComponent* Component, const FName& ParamName, float Value) {
}

void UGameUtil::SetComponentMaterialScalarParam(UPrimitiveComponent* Component, UMaterialInterface* Material, const FName& ParamName, float Value) {
}

void UGameUtil::SetAllMaterialsTo(AActor* Actor, UMaterialInterface* Material, TArray<FCachedMaterialState>& CachedMaterialStates, bool RecurseChildren) {
}

void UGameUtil::SetActorsVisible(TArray<AActor*> Actors, bool Visible) {
}

void UGameUtil::SetActive(AActor* Actor, bool Active) {
}

void UGameUtil::ResetCachedMaterials(const TArray<FCachedMaterialState>& MaterialStates) {
}

void UGameUtil::ResetActorDynamics(const AActor* Actor) {
}

void UGameUtil::RemoveTag(AActor* Actor, FName Tag) {
}

void UGameUtil::RemoveLevelInstanceByName(UObject* WorldContextObject, const FString& UniqueInstanceName) {
}

void UGameUtil::RemoveLevelInstance(UObject* WorldContextObject, ULevelStreaming* LevelInstance) {
}

void UGameUtil::PlayForceFeedback(const UObject* WorldContextObject, UForceFeedbackEffect* ForceFeedbackEffect, bool bLooping, bool bIgnoreTimeDilation, FName Tag, int32 PlayerIndex) {
}

void UGameUtil::PlayCameraShake(const UObject* WorldContextObject, TSubclassOf<UCameraShake> CameraShake, float Scale, TEnumAsByte<ECameraAnimPlaySpace::Type> PlaySpace, FRotator UserPlaySpaceRot, int32 PlayerIndex) {
}

UObject* UGameUtil::LoadSoftReference(const TSoftObjectPtr<UObject>& SoftObjRef) {
    return NULL;
}

UClass* UGameUtil::LoadSoftClassReference(const TSoftClassPtr<UObject>& SoftClsRef) {
    return NULL;
}

UObject* UGameUtil::LoadObjectFromPath(FName Path) {
    return NULL;
}

void UGameUtil::LoadFileToString(const FString& File, FString& Contents, bool& bSuccessful) {
}

bool UGameUtil::LineTraceByChannelWithContext(UObject* WorldContextObject, const FVector& Start, const FVector& End, TEnumAsByte<ECollisionChannel> TraceChannel, bool TraceComplex, FHitResult& Hit) {
    return false;
}

void UGameUtil::LatentDestroyActor(AActor* Actor) {
}

bool UGameUtil::IsVisible(AActor* Actor) {
    return false;
}

bool UGameUtil::IsUsingTouchController() {
    return false;
}

bool UGameUtil::IsUsingKeyboardAndMouse() {
    return false;
}

bool UGameUtil::IsUsingGamepad() {
    return false;
}

bool UGameUtil::IsSwimmingUnderwater(const AActor* Actor) {
    return false;
}

bool UGameUtil::IsSwimmingOnSurface(const AActor* Actor) {
    return false;
}

bool UGameUtil::IsSwimming(const AActor* Actor) {
    return false;
}

bool UGameUtil::IsStereoEnabled() {
    return false;
}

bool UGameUtil::IsSoftDestroyed(AActor* Actor) {
    return false;
}

bool UGameUtil::IsSingleplayerGame(const UObject* WorldContextObject) {
    return false;
}

bool UGameUtil::IsShippingBuild() {
    return false;
}

bool UGameUtil::IsPlayingCinematic(const UObject* WorldContextObject) {
    return false;
}

bool UGameUtil::IsLocallyControlled(AActor* Actor) {
    return false;
}

bool UGameUtil::IsInWater(const ACharacter* Character) {
    return false;
}

bool UGameUtil::IsInEditor() {
    return false;
}

bool UGameUtil::IsHMDWorn() {
    return false;
}

bool UGameUtil::IsHDREnabled() {
    return false;
}

bool UGameUtil::IsChildOfSoftClasses(AActor* Actor, const TArray<TSoftClassPtr<AActor>>& Classes) {
    return false;
}

void UGameUtil::InvokeEvent(UObject* Object, FName EventName) {
}

TArray<USceneComponent*> UGameUtil::HideVisibleComponents(AActor* Actor, TSubclassOf<USceneComponent> ComponentClass, bool RecurseChildren) {
    return TArray<USceneComponent*>();
}

bool UGameUtil::HasAnyRootMotion(ACharacter* Character) {
    return false;
}

bool UGameUtil::HasAnyRenderedSlaveMeshes(const USkinnedMeshComponent* Mesh) {
    return false;
}

bool UGameUtil::GetWaterSubmergeDepth(AActor* Actor, float& OutSubmergeDepth) {
    return false;
}

FColor UGameUtil::GetUniqueColor(int32 ColorIndex) {
    return FColor{};
}

FString UGameUtil::GetScriptStack() {
    return TEXT("");
}

bool UGameUtil::GetPropertyValueAsFloat(UObject* Object, FName PropertyName, float& Value) {
    return false;
}

FName UGameUtil::GetPrefix(const FName& Name) {
    return NAME_None;
}

TArray<APlayerState*> UGameUtil::GetPlayerStates(const UObject* WorldContextObject) {
    return TArray<APlayerState*>();
}

TArray<APlayerController*> UGameUtil::GetPlayerControllers(const UObject* WorldContextObject) {
    return TArray<APlayerController*>();
}

APlayerController* UGameUtil::GetPlayerControllerForActor(AActor* Actor) {
    return NULL;
}

EPlatform UGameUtil::GetPlatformSubType() {
    return EPlatform::Unknown;
}

EPlatform UGameUtil::GetPlatform() {
    return EPlatform::Unknown;
}

ACharacter* UGameUtil::GetOwningCharacter(AActor* Actor) {
    return NULL;
}

UObject* UGameUtil::GetOwner(UObject* Object) {
    return NULL;
}

bool UGameUtil::GetObjectPath(UObject* Object, FString& Path) {
    return false;
}

int32 UGameUtil::GetNumConnectedPlayers(const UObject* WorldContextObject) {
    return 0;
}

bool UGameUtil::GetNodeTransform(const AActor* Actor, const FName& NodeName, FTransform& Transform, TEnumAsByte<ERelativeTransformSpace> TransformSpace) {
    return false;
}

ELocalizationLanguage UGameUtil::GetLocalizationLanguage() {
    return ELocalizationLanguage::en;
}

ALevelScriptActor* UGameUtil::GetLevelScriptActor(ULevel* Level) {
    return NULL;
}

FString UGameUtil::GetLevelPathName(ULevel* Level) {
    return TEXT("");
}

ULevelStreaming* UGameUtil::GetLevelInstance(UObject* WorldContextObject, const FString& UniqueInstanceName) {
    return NULL;
}

ULevel* UGameUtil::GetLevelForActor(AActor* Actor) {
    return NULL;
}

UGameViewportClientGunfire* UGameUtil::GetGameViewport(const UObject* WorldContextObject) {
    return NULL;
}

int64 UGameUtil::GetFrameCounter() {
    return 0;
}

int32 UGameUtil::GetCurrentPlatformVRam() {
    return 0;
}

UActorComponent* UGameUtil::GetComponentByTag(AActor* Actor, const FName& Tag) {
    return NULL;
}

UActorComponent* UGameUtil::GetComponentByName(AActor* Actor, const FName& NodeName) {
    return NULL;
}

bool UGameUtil::GetClosestUnblockedPointBetweenActors(const AActor* Target, const AActor* Source, TEnumAsByte<ECollisionChannel> TraceChannel, TEnumAsByte<ECollisionChannel> CollisionChannel, FVector& OutClosestPoint) {
    return false;
}

float UGameUtil::GetClosestPointInActor(const AActor* Actor, const FVector& Point, TEnumAsByte<ECollisionChannel> TraceChannel, FVector& OutClosestPoint) {
    return 0.0f;
}

FString UGameUtil::GetCleanLevelStreamingName(const UWorld* World, const ULevelStreaming* Level, bool AppendBaseName) {
    return TEXT("");
}

FString UGameUtil::GetCleanLevelPackageName(const UWorld* World, const FString& LevelPackagePath, bool AppendBaseName) {
    return TEXT("");
}

EBuildType UGameUtil::GetBuildType() {
    return EBuildType::Debug;
}

int32 UGameUtil::GetBuildNumber() {
    return 0;
}

bool UGameUtil::GetBoneTransform(const USkeletalMeshComponent* SkeletalMesh, FName BoneName, FTransform& Transform, TEnumAsByte<ERelativeTransformSpace> TransformSpace) {
    return false;
}

bool UGameUtil::GetBoneRefTransform(const USkeletalMeshComponent* SkeletalMesh, FName BoneName, FTransform& Transform) {
    return false;
}

AActor* UGameUtil::GetBestWaterBounds(AActor* Actor, bool bConstrainToFluidFilled) {
    return NULL;
}

bool UGameUtil::GetAttachSocketName(USceneComponent* Mesh, FName& OutSocketName) {
    return false;
}

void UGameUtil::GetActorsWithTagEx(const UObject* WorldContextObject, FName Tag, TArray<AActor*>& OutResults) {
}

void UGameUtil::GetActorsInRangeEx(const UObject* WorldContextObject, const FVector& Position, float MinRange, float MaxRange, UClass* FilterClass, const FActorQueryFilter& Filter, TArray<FActorQueryResult>& OutResults) {
}

void UGameUtil::GetActorsInRange(const UObject* WorldContextObject, const FVector& Position, float MinRange, float MaxRange, UClass* FilterClass, const FActorQueryFilter& Filter, TArray<AActor*>& OutResults) {
}

void UGameUtil::GetActorBoundsSafe(AActor* Actor, bool bOnlyCollidingComponents, FVector& Origin, FVector& Extents) {
}

void UGameUtil::ForceGarbageCollection() {
}

AActor* UGameUtil::FinishSpawningDeferredActor(AActor* Actor, const FTransform& SpawnTransform) {
    return NULL;
}

bool UGameUtil::FindTeleportPositionNear(AActor* Actor, float Distance, FVector& OutPosition, bool InFOVOnly) {
    return false;
}

APlayerStart* UGameUtil::FindPlayerStart(UObject* WorldContextObject, const FName& PlayerStartTag) {
    return NULL;
}

void UGameUtil::EnableStereo(bool bEnable) {
}

void UGameUtil::DrawDebugArrow(const UObject* WorldContextObject, const FVector& LineStart, const FVector& LineEnd, const FVector& ArrowAxis, const FRotator& BasisRotation, const FLinearColor& Color, const float Thickness, const float Duration, const float ArrowSize) {
}

bool UGameUtil::DoesPathIntersectWithBounds(const ACharacterGunfire* Character, const FVector& Origin, const FVector& Extents) {
    return false;
}

bool UGameUtil::DoesGameHaveFocus(UObject* WorldContextObject) {
    return false;
}

void UGameUtil::DebugDrawShapeWithOrientation(const UObject* WorldContextObject, const UShapeComponent* Shape, const FColor& Color, FVector Location, FRotator Rotation, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness) {
}

void UGameUtil::DebugDrawShape(const UObject* WorldContextObject, const UShapeComponent* Shape, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness) {
}

void UGameUtil::DebugDrawCollision(const UObject* WorldContextObject, const UPrimitiveComponent* Primitive, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Thickness) {
}

void UGameUtil::CustomError(AActor* ErrorContext, const FString& Message) {
}

bool UGameUtil::CheckInputAction(const APlayerController* PlayerController, const FName& ActionName) {
    return false;
}

void UGameUtil::CenterViewportCursor(const APlayerController* PlayerController) {
}

FVector UGameUtil::CalculateTraversableTeleportLocation(UObject* WorldContextObject, ACharacter* Character, FVector AimStart, FVector AimEnd, float AimObstacleTolerance, float GroundDistance, float CliffTolerance, bool bConstrainToLedges, float ProbeDistance, float StuckCheckHeightOffset, float FlatSurfaceDistance, bool bDebugDraw) {
    return FVector{};
}

void UGameUtil::ApplyLinearImpulseToActorAtLocation(AActor* Actor, TSubclassOf<UDamageTypeGunfire> DType, const FVector& Direction, const FVector& Location) {
}

void UGameUtil::ApplyLinearImpulseToActor(AActor* Actor, TSubclassOf<UDamageTypeGunfire> DType, const FVector& Direction) {
}

void UGameUtil::AddTag(AActor* Actor, FName Tag) {
}

ULevelStreaming* UGameUtil::AddLevelInstance(UObject* WorldContextObject, const FString& UniqueInstanceName, const FString& PackageNameToLoad, const FTransform& LevelTransform, bool BlockOnLoad, bool ShouldBeLoaded, bool ShouldBeVisible, TSubclassOf<ULevelStreaming> LevelStreamingOverride) {
    return NULL;
}

UActorComponent* UGameUtil::AddComponent(AActor* Actor, TSubclassOf<UActorComponent> ComponentClass, FName Name, FName AttachSocketName, USceneComponent* AttachParent, EAttachmentRule AttachRule, bool bWeldSimulatedBodies, FVector RelativeLocation, FRotator RelativeRotation, bool bSkipAttachment) {
    return NULL;
}

void UGameUtil::ActivateSceneComponents(AActor* Actor, FName Slot, FName Tag, bool ActivateChildren, bool UseVisibility) {
}

void UGameUtil::ActivateSceneComponent(USceneComponent* SceneComponent, bool Active, bool ActivateChildren, bool UseVisibility) {
}

UGameUtil::UGameUtil() {
}

