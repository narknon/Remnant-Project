#pragma once
#include "CoreMinimal.h"
#include "PersistenceCallbackProxy.h"
#include "BlueprintSaveNoRetDelegateDelegate.h"
#include "RestoreProfileBackupCallbackProxy.generated.h"

class URestoreProfileBackupCallbackProxy;
class UObject;

UCLASS(Blueprintable)
class URestoreProfileBackupCallbackProxy : public UPersistenceCallbackProxy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintSaveNoRetDelegate OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintSaveNoRetDelegate OnFailure;
    
    URestoreProfileBackupCallbackProxy();
    UFUNCTION(BlueprintCallable)
    static URestoreProfileBackupCallbackProxy* RestoreProfileBackup(UObject* WorldContextObject);
    
};

