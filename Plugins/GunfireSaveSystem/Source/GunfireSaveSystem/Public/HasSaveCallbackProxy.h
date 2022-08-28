#pragma once
#include "CoreMinimal.h"
#include "PersistenceCallbackProxy.h"
#include "BlueprintHasSaveResultDelegateDelegate.h"
#include "HasSaveCallbackProxy.generated.h"

class UHasSaveCallbackProxy;
class UObject;

UCLASS(Blueprintable)
class UHasSaveCallbackProxy : public UPersistenceCallbackProxy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintHasSaveResultDelegate OnComplete;
    
    UHasSaveCallbackProxy();
    UFUNCTION(BlueprintCallable)
    static UHasSaveCallbackProxy* HasSave(UObject* WorldContextObject, int32 Slot);
    
};

