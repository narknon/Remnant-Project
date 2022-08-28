#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "FindSessionsCallbackProxy.h"
#include "MatchmakerListenerInterface.generated.h"

UINTERFACE(Blueprintable)
class UMatchmakerListenerInterface : public UInterface {
    GENERATED_BODY()
};

class IMatchmakerListenerInterface : public IInterface {
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSessionStarted();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSessionsFound(const TArray<FBlueprintSessionResult>& Sessions);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSessionJoined();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSessionFailed(FName Reason);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSessionEnded();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnSessionCreated();
    
};

