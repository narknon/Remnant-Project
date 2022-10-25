#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ELicensedContent.h"
#include "ERevokeType.h"
#include "OnLicenseCheckedDelegate.h"
#include "OnLicenseRevokedDelegate.h"
#include "EntitlementComponent.generated.h"

class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRETECHREQUIREMENTS_API UEntitlementComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ELicensedContent RequiredLicense;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    ERevokeType RevokeType;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLicenseChecked OnLicenseChecked;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnLicenseRevoked OnLicenseRevokedOverride;
    
    UEntitlementComponent();
    UFUNCTION(BlueprintCallable)
    void ShowRevokedDialog();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void RevokeLicense();
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static bool HasEntitlement(UObject* WorldContextObject, UObject* Object, bool NotifyIfUnlicensed);
    
    UFUNCTION(BlueprintCallable)
    static ELicensedContent GetRequiredLicense(UObject* Object);
    
protected:
    UFUNCTION(BlueprintCallable)
    void CheckLicense();
    
};

