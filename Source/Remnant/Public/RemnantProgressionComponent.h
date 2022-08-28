#pragma once
#include "CoreMinimal.h"
#include "OnExperienceGainedDelegate.h"
#include "ProgressionComponent.h"
#include "ProgressionValidationInfo.h"
#include "RemnantProgressionComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantProgressionComponent : public UProgressionComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxValidExperienceOverTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExpTimeOutSeconds;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FProgressionValidationInfo> ProgressionTimeOutInfo;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnExperienceGained OnExperienceGained;
    
public:
    URemnantProgressionComponent();
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAddExperience(int32 Exp);
    
    UFUNCTION(BlueprintCallable)
    void ClientAddProgressionTimeOut();
    
    UFUNCTION(BlueprintCallable)
    void AddProtectionTimeOut();
    
};

