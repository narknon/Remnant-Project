#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "UObject/Object.h"
#include "OnBeginLoadingNextMapDelegate.h"
#include "UObject/NoExportTypes.h"
#include "MapSettings.h"
#include "MapLoader.generated.h"

class UWorld;
class UPlayableMap;
class ULevel;
class UGameInstanceGunfire;
class UMapLoader;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UMapLoader : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnBeginLoadingNextMap OnBeginLoadingNextMap;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UPlayableMap> TransitionLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FMapSettings> MapSettings;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor FadeColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FadeTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldWaitToFadeIntoLevel;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UGameInstanceGunfire* GameInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ULevel*> CurrentLevels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<ULevel*> NextLevels;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWorld* CurrentWorld;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UWorld* NextWorld;
    
public:
    UMapLoader();
protected:
    UFUNCTION(BlueprintCallable)
    void TravelToTransitionMap();
    
    UFUNCTION(BlueprintCallable)
    void TravelToNextMap();
    
public:
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool OpenMapByName(UObject* WorldContextObject, const FString& MapName);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool OpenMap(UObject* WorldContextObject, TSubclassOf<UPlayableMap> Map);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnPlayerEnterTransitionMap(UWorld* LoadedWorld);
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerEnterNextMapDelayed();
    
    UFUNCTION(BlueprintCallable)
    void OnNextMapVisible();
    
    UFUNCTION(BlueprintCallable)
    void OnFadeScreenCompleted();
    
    UFUNCTION(BlueprintCallable)
    void LoadNotStreamableLevels();
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static FString GetNotStreamableMapSuffix();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UMapLoader* GetMapLoader(UObject* WorldContextObject);
    
};

