#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Components/ActorComponent.h"
#include "TileActiveDelegateDelegate.h"
#include "VisualLogger/VisualLoggerDebugSnapshotInterface.h"
#include "TileVisibleDelegateDelegate.h"
#include "TileBase.h"
#include "UObject/NoExportTypes.h"
#include "MapGenVoidDelegateDelegate.h"
#include "Tile.h"
#include "MapGenAttribute.h"
#include "EMapGenState.h"
#include "EMapGenAttributeScope.h"
#include "UObject/NoExportTypes.h"
#include "MapGenComponent.generated.h"

class AMapGenSettings;
class UWorld;
class APlayerController;
class ULevelStreaming;
class ARuntimeNavMeshBoundsVolume;
class UTileSet;
class AAudioCustomVolume;
class AMapTileInfo;
class AMapTileEdge;
class AActor;
class ULevel;
class UMapGenComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UMapGenComponent : public UActorComponent, public IVisualLoggerDebugSnapshotInterface {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Seed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> Template;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    FString TemplateOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseLoadedLevelAsTemplate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AutoInitialize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FVector MapOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FString MapInstanceName;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTileActiveDelegate OnSetTileActive;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTileVisibleDelegate OnSetTileVisible;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapGenVoidDelegate OnOverallVisibilityChange;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapGenVoidDelegate OnGenerationComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapGenVoidDelegate OnFullyLoaded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapGenVoidDelegate OnUnloaded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapGenVoidDelegate OnInitialized;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapGenVoidDelegate OnUninitialized;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMapGenVoidDelegate OnFailed;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AMapGenSettings* Settings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<APlayerController*> Players;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULevelStreaming* TemplateLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ARuntimeNavMeshBoundsVolume* NavBounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool Generated;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_TilesBase, meta=(AllowPrivateAccess=true))
    TArray<FTileBase> TilesBase;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    bool NoTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTile> Tiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<int32> PreviousVisibleTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    TArray<FMapGenAttribute> Attributes;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, Transient, meta=(AllowPrivateAccess=true))
    EMapGenState ServerState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, ReplicatedUsing=OnRep_MapACVClass, meta=(AllowPrivateAccess=true))
    TSubclassOf<AAudioCustomVolume> MapACVClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ULevelStreaming*> LevelsUnloading;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AMapTileInfo*> TemplateTiles;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AMapTileEdge*> TemplateEdges;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AAudioCustomVolume* MapACV;
    
public:
    UMapGenComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnStartedVisualLogger();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_TilesBase();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_MapACVClass();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTileVisited(int32 TileID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTileActive(int32 TileID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsPositionInTile(const FVector& WorldPosition, const FTile& Tile) const;
    
    UFUNCTION(BlueprintCallable)
    bool IsEdgeOpen(AActor* Actor, float Tolerance);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UTileSet* GetTileSet();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetTileForActor(AActor* Actor, FTile& Out) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTileDistance(int32 TileID) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetTileAtPosition(const FVector& WorldPosition, FTile& Out) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetSpawnTagsAtPosition(const FVector& WorldPosition, TArray<FName>& Out) const;
    
    UFUNCTION(BlueprintCallable)
    static ULevel* GetMapGenLevelForActor(AActor* Actor);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetMapGenDebugState();
    
public:
    UFUNCTION(BlueprintCallable)
    static bool GetMapGenAttributeForActor(EMapGenAttributeScope Scope, AActor* Actor, FName Key, FMapGenAttribute& Out);
    
    UFUNCTION(BlueprintCallable)
    AAudioCustomVolume* GetMapACV();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetLevelMaxSize(bool IncludeVista) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetLevelCenter(bool IncludeVista) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FBox GetLevelBounds(bool IncludeVista) const;
    
    UFUNCTION(BlueprintCallable)
    bool GetAttribute(EMapGenAttributeScope Scope, FName TileOrRegionID, FName Key, FMapGenAttribute& Out);
    
    UFUNCTION(BlueprintCallable)
    static UMapGenComponent* FindMapGenComponentForActor(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void AddAttribute(FMapGenAttribute Attribute);
    
    
    // Fix for true pure virtual functions not being implemented
};

