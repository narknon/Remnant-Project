#pragma once
#include "CoreMinimal.h"
#include "PersistenceCallbackProxy.h"
#include "BlueprintLoadSaveResultDelegateDelegate.h"
#include "ReadSaveCallbackProxy.generated.h"

class UReadSaveCallbackProxy;
class UObject;

UCLASS(Blueprintable)
class UReadSaveCallbackProxy : public UPersistenceCallbackProxy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintLoadSaveResultDelegate OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintLoadSaveResultDelegate OnFailure;
    
    UReadSaveCallbackProxy();
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UReadSaveCallbackProxy* ReadSave(UObject* WorldContextObject, int32 Slot);
    
};

