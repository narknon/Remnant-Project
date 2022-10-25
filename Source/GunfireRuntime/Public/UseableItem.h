#pragma once
#include "CoreMinimal.h"
#include "Equipment.h"
#include "EUsableActivationType.h"
#include "Engine/EngineTypes.h"
#include "UseableItem.generated.h"

class UConditionList;
class AActor;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AUseableItem : public AEquipment {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UConditionList* Conditions;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UseState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName UseAnim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName PlayRateStat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> UseTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EUsableActivationType ActivationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bConsumeInput;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HoldTime;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FTimerHandle HoldTimerHandle;
    
public:
    AUseableItem();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    bool ValidateUse(AActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void UseItem();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Use();
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerKeyPressed();
    
public:
    UFUNCTION(BlueprintCallable)
    void RemoveItem();
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable, BlueprintImplementableEvent)
    void OnUse();
    
protected:
    UFUNCTION(NetMulticast, Reliable)
    void MulticastSetState(uint8 NewState);
    
};

