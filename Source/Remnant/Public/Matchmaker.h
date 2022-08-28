#pragma once
#include "CoreMinimal.h"
#include "OnStateFailDelegate.h"
#include "UObject/Object.h"
#include "OnSessionsFoundDelegate.h"
#include "FindSessionsCallbackProxy.h"
#include "ESessionType.h"
#include "Net/OnlineBlueprintCallProxyBase.h"
#include "OnShowMatchmakingEventMessageDelegate.h"
#include "OnWaitDialogDelegate.h"
#include "OnRegisterPlayerDelegate.h"
#include "OnUnregisterPlayerDelegate.h"
#include "SessionDetails.h"
#include "ELastSearchType.h"
#include "Matchmaker.generated.h"

class APlayerController;
class UMatchmaker;

UCLASS(Blueprintable)
class REMNANT_API UMatchmaker : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FBlueprintSessionResult> FoundSessions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bMatchmakingDisabled;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnStateFail OnStateFailed;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnSessionsFound OnSessionsFound;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyOnlineDelegate OnSessionCreated;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyOnlineDelegate OnSessionStarted;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyOnlineDelegate OnSessionEnded;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyOnlineDelegate OnSessionJoined;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyOnlineDelegate OnSessionJoinAttempt;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyOnlineDelegate OnSessionJoinAttemptRetry;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FEmptyOnlineDelegate OnSessionJoinAttemptsFailed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ESessionType CurrentSessionType;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnShowMatchmakingEventMessage OnShowMatchmakingEventMessage;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnWaitDialog OnWaitDialog;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnRegisterPlayer OnRegisterPlayer;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnUnregisterPlayer OnUnregisterPlayer;
    
    UMatchmaker();
    UFUNCTION(BlueprintCallable)
    void UpdateSession();
    
    UFUNCTION(BlueprintCallable)
    void UpdateJoinability(bool isJoinable);
    
    UFUNCTION(BlueprintCallable)
    void StartSession();
    
    UFUNCTION(BlueprintCallable)
    void ShowSessionGamertagInfo(FBlueprintSessionResult SessionInfo);
    
    UFUNCTION(BlueprintCallable)
    void SetSessionJoinability(bool isJoinable);
    
    UFUNCTION(BlueprintCallable)
    void RejoinLastSession();
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnShowQueuedMatchmakingEventMessages();
    
    UFUNCTION(BlueprintCallable)
    void OnSessionEndedEvent();
    
    UFUNCTION(BlueprintCallable)
    void OnPlayerNameChanged();
    
    UFUNCTION(BlueprintCallable)
    void OnMainMenuLoaded();
    
public:
    UFUNCTION(BlueprintCallable)
    void KickPlayer(APlayerController* PlayerController, bool Banned);
    
    UFUNCTION(BlueprintCallable)
    void JoinSession(const FBlueprintSessionResult& SearchResult);
    
    UFUNCTION(BlueprintCallable)
    bool IsSessionJoinable();
    
    UFUNCTION(BlueprintCallable)
    bool IsPresenceJoinURLValid();
    
    UFUNCTION(BlueprintCallable)
    bool IsOnline();
    
    UFUNCTION(BlueprintCallable)
    bool IsLocalCharacterSurvival();
    
    UFUNCTION(BlueprintCallable)
    bool IsLocalCharacterHardcore();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsJoiningSession() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsFindingSessions() const;
    
    UFUNCTION(BlueprintCallable)
    void InviteFriend();
    
    UFUNCTION(BlueprintCallable)
    void Init(const UObject* WorldContextObject, APlayerController* PlayerController);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetSessionStateName() const;
    
    UFUNCTION(BlueprintCallable)
    FSessionDetails GetSessionDetails(const FBlueprintSessionResult& Session);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UMatchmaker* GetMatchmakerInstance(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    FString GetCurrentSessionDisplay();
    
    UFUNCTION(BlueprintCallable)
    void EndFindSessions();
    
    UFUNCTION(BlueprintCallable)
    void DestroySession();
    
    UFUNCTION(BlueprintCallable)
    void CreateSession(ESessionType SessionType, bool DisableJoinability);
    
    UFUNCTION(BlueprintCallable)
    void ChangeSession(ESessionType NewSessionType, bool Force);
    
    UFUNCTION(BlueprintCallable)
    bool CanRejoinLastSession();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CanJoinSessionGameMode(const UObject* WorldContextObject, const FBlueprintSessionResult& Session);
    
    UFUNCTION(BlueprintCallable)
    bool CanChangeSessiontype();
    
    UFUNCTION(BlueprintCallable)
    void BeginJoinPublicGame(ELastSearchType SearchType);
    
    UFUNCTION(BlueprintCallable)
    void BeginFindSessions();
    
};

