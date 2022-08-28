#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/Actor.h"
#include "LevelCollectionStateDelegateDelegate.h"
#include "EPlayableVisibleState.h"
#include "EPlayableLoadState.h"
#include "PlayableLevelCollection.generated.h"

class APlayableLevel;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API APlayableLevelCollection : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TSubclassOf<APlayableLevel>> LevelClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<APlayableLevel*> Levels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelCollectionStateDelegate OnLevelCollectionPreloadedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelCollectionStateDelegate OnLevelCollectionLoadedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelCollectionStateDelegate OnLevelCollectionUnloadedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelCollectionStateDelegate OnLevelCollectionShownEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelCollectionStateDelegate OnLevelCollectionHiddenEvent;
    
    APlayableLevelCollection();
    UFUNCTION(BlueprintCallable)
    bool IsPreloaded();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APlayableLevel* GetPlayableLevelByPath(const FString& Path) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APlayableLevel* GetPlayableLevelByName(const FString& Name) const;
    
    UFUNCTION(BlueprintCallable)
    void ChangeCollectionState(EPlayableLoadState LoadState, EPlayableVisibleState VisibleState);
    
    UFUNCTION(BlueprintCallable)
    void AddPlayableLevel(APlayableLevel* Level);
    
};

