#pragma once
#include "CoreMinimal.h"
#include "PersistenceCallbackProxy.h"
#include "BlueprintSaveNoRetDelegateDelegate.h"
#include "DeleteSaveCallbackProxy.generated.h"

class UDeleteSaveCallbackProxy;
class UObject;

UCLASS(Blueprintable)
class UDeleteSaveCallbackProxy : public UPersistenceCallbackProxy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintSaveNoRetDelegate OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintSaveNoRetDelegate OnFailure;
    
    UDeleteSaveCallbackProxy();
    UFUNCTION(BlueprintCallable)
    static UDeleteSaveCallbackProxy* DeleteSave(UObject* WorldContextObject, int32 Slot);
    
};

