#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ContextualDialogDelegateDelegate.h"
#include "UObject/NoExportTypes.h"
#include "DamageInfo.h"
#include "UObject/NoExportTypes.h"
#include "ContextualDialogResponse.h"
#include "ContextualDialogComponent.generated.h"

class UContextualDialogSet;
class USoundSetComponent;
class UDialogInstance;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UContextualDialogComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UContextualDialogSet* DialogSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> ClientSideDialogTriggers;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FContextualDialogDelegate OnResponse;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USoundSetComponent* SoundSetComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FContextualDialogResponse CurrentResponse;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UDialogInstance* CurrentDialog;
    
public:
    UContextualDialogComponent();
    UFUNCTION(BlueprintCallable)
    static void TriggerDialogResponseInProximity(const FVector& Location, float Radius, FName DialogResponse);
    
    UFUNCTION(BlueprintCallable)
    bool TriggerDialogResponse(FName Trigger);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerTriggerDialogResponse(FName Trigger);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnNotifyTakeDamage(const FDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable)
    void OnNotifyHit(const FDamageInfo& DamageInfo);
    
    UFUNCTION(BlueprintCallable)
    void OnEvent(FName EventName);
    
    UFUNCTION(BlueprintCallable)
    void OnDialogComplete(UDialogInstance* Instance);
    
public:
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastDialog(FSoftObjectPath Dialog);
    
};

