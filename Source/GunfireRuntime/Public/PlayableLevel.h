#pragma once
#include "CoreMinimal.h"
#include "LevelInstanceStateDelegateDelegate.h"
#include "GameFramework/Actor.h"
#include "UObject/NoExportTypes.h"
#include "EPlayableVisibleState.h"
#include "EPlayableLoadState.h"
#include "PlayableLevel.generated.h"

class UWorld;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API APlayableLevel : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTransform LevelTransform;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LevelName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString LevelPath;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelInstanceStateDelegate OnLevelPreloadedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelInstanceStateDelegate OnLevelLoadedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelInstanceStateDelegate OnLevelUnloadedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelInstanceStateDelegate OnLevelShownEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelInstanceStateDelegate OnLevelHiddenEvent;
    
    APlayableLevel();
    UFUNCTION(BlueprintCallable)
    void ChangeLevelState(EPlayableLoadState LoadState, EPlayableVisibleState VisibleState);
    
};

