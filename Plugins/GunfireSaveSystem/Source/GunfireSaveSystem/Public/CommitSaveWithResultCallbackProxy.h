#pragma once
#include "CoreMinimal.h"
#include "PersistenceCallbackProxy.h"
#include "BlueprintCommitSaveResultDelegateDelegate.h"
#include "CommitSaveWithResultCallbackProxy.generated.h"

class UCommitSaveWithResultCallbackProxy;
class UObject;

UCLASS(Blueprintable)
class UCommitSaveWithResultCallbackProxy : public UPersistenceCallbackProxy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintCommitSaveResultDelegate OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintCommitSaveResultDelegate OnFailure;
    
    UCommitSaveWithResultCallbackProxy();
    UFUNCTION(BlueprintCallable)
    static UCommitSaveWithResultCallbackProxy* CommitSaveWithResult(UObject* WorldContextObject, const FString& Reason);
    
};

