#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VariableComponent.generated.h"

class UVariables;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UVariableComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVariables* Variables;
    
    UVariableComponent();
    UFUNCTION(BlueprintCallable)
    void SetVariableObject(const FName& NameID, UObject* Value, float Expiration);
    
    UFUNCTION(BlueprintCallable)
    void SetVariableNumber(const FName& NameID, float Value, float Expiration);
    
    UFUNCTION(BlueprintCallable)
    void SetVariableName(const FName& NameID, FName Value, float Expiration);
    
    UFUNCTION(BlueprintCallable)
    void SetVariableBool(const FName& NameID, bool Value, float Expiration);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UObject* GetVariableObject(const FName& NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetVariableNumber(const FName& NameID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetVariableBool(const FName& NameID);
    
};

