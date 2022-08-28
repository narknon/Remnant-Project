#pragma once
#include "CoreMinimal.h"
#include "PersistenceCallbackProxy.h"
#include "BlueprintLoadSaveResultDelegateDelegate.h"
#include "ReadSaveCallbackProxy.generated.h"

class UObject;
class UReadSaveCallbackProxy;

UCLASS(Blueprintable)
class UReadSaveCallbackProxy : public UPersistenceCallbackProxy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintLoadSaveResultDelegate OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintLoadSaveResultDelegate OnFailure;
    
    UReadSaveCallbackProxy();
    UFUNCTION(BlueprintCallable)
    static UReadSaveCallbackProxy* ReadSave(UObject* WorldContextObject, int32 Slot);
    
};

