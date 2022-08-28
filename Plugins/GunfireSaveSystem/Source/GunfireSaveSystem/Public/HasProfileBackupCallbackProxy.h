#pragma once
#include "CoreMinimal.h"
#include "PersistenceCallbackProxy.h"
#include "BlueprintSaveNoRetDelegateDelegate.h"
#include "HasProfileBackupCallbackProxy.generated.h"

class UObject;
class UHasProfileBackupCallbackProxy;

UCLASS(Blueprintable)
class UHasProfileBackupCallbackProxy : public UPersistenceCallbackProxy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintSaveNoRetDelegate HasBackup;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintSaveNoRetDelegate NoBackup;
    
    UHasProfileBackupCallbackProxy();
    UFUNCTION(BlueprintCallable)
    static UHasProfileBackupCallbackProxy* HasProfileBackup(UObject* WorldContextObject);
    
};

