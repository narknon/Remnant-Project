#pragma once
#include "CoreMinimal.h"
#include "ActiveProfileSetDelegate.h"
#include "OnDLCEntitlementsUpdatedDelegate.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "ETechReqStatusChange.h"
#include "ControllerConnChangedDelegate.h"
#include "OnShowStatusEventMessageDelegate.h"
#include "FullGameAvailableEventDelegateDelegate.h"
#include "ActiveControllerSetDelegate.h"
#include "NetworkConnChangedDelegate.h"
#include "OnlinePrivilegeCheckedDelegateDelegate.h"
#include "OnMainMenuLoadedDelegate.h"
#include "OnWaitDialogDelegate.h"
#include "ActiveProfileLostDelegate.h"
#include "OnDLCInstallFinishedDelegate.h"
#include "OnLegalCompleteDelegate.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "EPresenceContent.h"
#include "ELicensedContent.h"
#include "EAlternateLoginType.h"
#include "GunfireTechRequirementsImpl.generated.h"

class APlayerController;
class UCameraComponent;
class UGunfireTechRequirementsImpl;
class UObject;

UCLASS(Blueprintable)
class GUNFIRETECHREQUIREMENTS_API UGunfireTechRequirementsImpl : public UGameInstanceSubsystem {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnShowStatusEventMessage OnShowStatusEventMessage;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FFullGameAvailableEventDelegate OnFullGameAvailable;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FControllerConnChanged OnControllerConnectionChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActiveControllerSet OnActiveControllerSet;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActiveProfileSet OnActiveProfileSet;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNetworkConnChanged OnStatusChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FNetworkConnChanged OnOnlineUnavailable;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnlinePrivilegeCheckedDelegate OnOnlinePrivilegeChecked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnMainMenuLoaded OnMainMenuLoaded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnWaitDialog OnWaitDialog;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FActiveProfileLost OnActiveProfileLost;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDLCInstallFinished OnDLCInstallFinished;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLegalComplete OnLegalComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDLCEntitlementsUpdated OnDLCEntitlementsUpdated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnWaitDialog OnWaitCustomLoginDialog;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyOnlineDelegate OnRequestCustomLogin;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyOnlineDelegate OnLoginCompleted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyOnlineDelegate OnExternalAuthFail;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<ETechReqStatusChange> StatusChangeEvents;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETechReqStatusChange NetworkFailReason;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ETechReqStatusChange PrivilegeFailReason;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bHasSeenLegalScreen;
    
    UGunfireTechRequirementsImpl();
    UFUNCTION(BlueprintCallable)
    void ShowSwitchPlatformGameProfile();
    
    UFUNCTION(BlueprintCallable)
    void ShowOfflineMessage();
    
    UFUNCTION(BlueprintCallable)
    void SetVoipEnabled(bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    void SetUsingMultiplayerFeatures(bool IsUsing);
    
    UFUNCTION(BlueprintCallable)
    void SetPresenceLocation(EPresenceContent Location);
    
    UFUNCTION(BlueprintCallable)
    void SetHasSeenLegalScreen();
    
    UFUNCTION(BlueprintCallable)
    void SetActiveController(APlayerController* Controller);
    
protected:
    UFUNCTION(BlueprintCallable)
    void PrepForPressAnyKeyDialog();
    
public:
    UFUNCTION(BlueprintCallable)
    void MuteVOIP(bool bMute);
    
    UFUNCTION(BlueprintCallable)
    void MainMenuLoaded();
    
    UFUNCTION(BlueprintCallable)
    bool IsVoipPTTEnabled();
    
    UFUNCTION(BlueprintCallable)
    bool IsVoipMuted();
    
    UFUNCTION(BlueprintCallable)
    bool IsVoipEnabled();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsUsingMultiplayerFeatures();
    
    UFUNCTION(BlueprintCallable)
    bool IsProfileValid();
    
    UFUNCTION(BlueprintCallable)
    bool IsPremiumServiceAvailable();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFullGameAvailable() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsControllerConnected();
    
    UFUNCTION(BlueprintCallable)
    bool IsChatRestricted();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasLicense(ELicensedContent License) const;
    
    UFUNCTION(BlueprintCallable)
    bool HasCheckedOnlinePrivilege();
    
    UFUNCTION(BlueprintCallable)
    EPresenceContent GetPresenceLocation();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FString GetPlatformGameProfileUserName();
    
    UFUNCTION(BlueprintCallable)
    TArray<ELicensedContent> GetLicensedContent();
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static UGunfireTechRequirementsImpl* GetGunfireTechRequirementsImpl(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    void EnableVoipPTT(bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    void CustomLogin(EAlternateLoginType Type);
    
    UFUNCTION(BlueprintCallable)
    void CheckOnlinePrivilege();
    
    UFUNCTION(BlueprintCallable)
    void CheckOnlineCommunicationPrivilege();
    
    UFUNCTION(BlueprintCallable)
    bool CanRequestCustomLogin();
    
protected:
    UFUNCTION(BlueprintCallable)
    void AnyKeyPressed(APlayerController* PlayerController);
    
public:
    UFUNCTION(BlueprintCallable)
    void AdjustCameraFoVForAspect(bool bIgnoreFovSlider, UCameraComponent* CameraComponent);
    
    UFUNCTION(BlueprintCallable)
    void AddStatusChangedEvent(ETechReqStatusChange Event, float Delay);
    
};

