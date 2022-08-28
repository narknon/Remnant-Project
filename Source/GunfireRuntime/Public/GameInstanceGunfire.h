#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SaveEventDelegate.h"
#include "Engine/GameInstance.h"
#include "OnLocalPlayerPawnControlledDelegate.h"
#include "OnFadeIntoLevelCompletedDelegateDelegate.h"
#include "OnGameInstanceStartDelegate.h"
#include "UObject/NoExportTypes.h"
#include "EFadeDirection.h"
#include "GameInstanceGunfire.generated.h"

class UAssetCache;
class UWorld;
class UMapLoader;
class APawn;
class UAmbientAudioManager;
class UPathSharingManager;
class UObject;
class UGameInstanceGunfire;

UCLASS(Blueprintable, NonTransient)
class GUNFIRERUNTIME_API UGameInstanceGunfire : public UGameInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UWorld> MainMenuLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UMapLoader> MapLoaderClass;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UAssetCache> AssetCacheClass;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnFadeIntoLevelCompletedDelegate OnFadeIntoLevelCompletedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLocalPlayerPawnControlled OnLocalPlayerPawnControlledEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnGameInstanceStart OnGameInstanceStart;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSaveEvent OnSaveStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSaveEvent OnSaveFinished;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APawn* LocalPlayerPawn;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAmbientAudioManager* AmbientAudioManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UPathSharingManager* PathSharingManager;
    
public:
    UGameInstanceGunfire();
    UFUNCTION(BlueprintCallable)
    void QuitToMainMenu();
    
    UFUNCTION(BlueprintCallable)
    void OnShutdown();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPreQuitToMainMenu();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSaving() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInGameplay() const;
    
    UFUNCTION(BlueprintCallable)
    bool ImmediatelyFadeScreen(bool bIsFaded, FLinearColor FadeColor, bool bFadeAudio);
    
    UFUNCTION(BlueprintCallable)
    static APawn* GetLocalPlayerPawn(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static UGameInstanceGunfire* GetInstance(const UObject* pWorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static UAssetCache* GetAssetCache();
    
    UFUNCTION(BlueprintCallable)
    bool FadeScreen(EFadeDirection FadeDirection, float FadeTime, FLinearColor FadeColor, bool bFadeAudio, bool bReset);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanSave() const;
    
};

