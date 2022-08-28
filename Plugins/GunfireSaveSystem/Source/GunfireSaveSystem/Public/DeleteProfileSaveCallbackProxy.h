#pragma once
#include "CoreMinimal.h"
#include "PersistenceCallbackProxy.h"
#include "BlueprintSaveNoRetDelegateDelegate.h"
#include "DeleteProfileSaveCallbackProxy.generated.h"

class UDeleteProfileSaveCallbackProxy;
class UObject;

UCLASS(Blueprintable)
class UDeleteProfileSaveCallbackProxy : public UPersistenceCallbackProxy {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintSaveNoRetDelegate OnSuccess;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FBlueprintSaveNoRetDelegate OnFailure;
    
    UDeleteProfileSaveCallbackProxy();
    UFUNCTION(BlueprintCallable)
    static UDeleteProfileSaveCallbackProxy* DeleteProfileSave(UObject* WorldContextObject);
    
};

