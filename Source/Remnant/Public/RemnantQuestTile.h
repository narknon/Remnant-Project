#pragma once
#include "CoreMinimal.h"
#include "RemnantQuestComponent.h"
#include "TileSpawnList.h"
#include "QuestTileDependency.h"
#include "QuestTileActiveDelegateDelegate.h"
#include "TileCoord.h"
#include "MapGenAttribute.h"
#include "RemnantQuestTile.generated.h"

class UTileSet;
class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantQuestTile : public URemnantQuestComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TileNameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTileSet* OverrideTileSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> SupportedTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    FName OverrideTileTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTileSpawnList> OverrideSpawnLists;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FQuestTileDependency> TileDependencies;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Exclusive;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Flags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    int32 TileID;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FQuestTileActiveDelegate OnSetTileActive;
    
    URemnantQuestTile();
protected:
    UFUNCTION(BlueprintCallable)
    void SetTileActive(int32 ID, bool Active);
    
public:
    UFUNCTION(BlueprintCallable)
    AActor* GetZoneLink(FName ZoneLinkNameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTileCoord GetTileCoord();
    
    UFUNCTION(BlueprintCallable)
    bool GetTileAttribute(FName Key, FMapGenAttribute& Out);
    
};

