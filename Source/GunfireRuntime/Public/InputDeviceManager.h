#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "OnDeviceChangedSignatureDelegate.h"
#include "OnResetIconCacheDelegate.h"
#include "EInputDevice.h"
#include "InputDeviceManager.generated.h"

class UInputDeviceManager;
class UImageSet;

UCLASS(Blueprintable, Transient)
class GUNFIRERUNTIME_API UInputDeviceManager : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnDeviceChangedSignature OnDeviceChangedDelegate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnResetIconCache OnResetIconCache;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UImageSet* ImageSet;
    
public:
    UInputDeviceManager();
    UFUNCTION(BlueprintCallable)
    void ResetKeyboardIconCache();
    
private:
    UFUNCTION(BlueprintCallable)
    void OnImageSetLoaded();
    
public:
    UFUNCTION(BlueprintCallable)
    bool IsUsingAltImageSet();
    
    UFUNCTION(BlueprintCallable)
    static UInputDeviceManager* GetInstance();
    
    UFUNCTION(BlueprintCallable)
    UObject* GetImage(FName NameID);
    
    UFUNCTION(BlueprintCallable)
    EInputDevice GetCurrentDeviceInUse(int32 ControllerId);
    
};

