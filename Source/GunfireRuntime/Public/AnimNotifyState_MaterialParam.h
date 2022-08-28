#pragma once
#include "CoreMinimal.h"
#include "EEaseType.h"
#include "ConditionalAnimNotifyState.h"
#include "AnimNotifyState_MaterialParam.generated.h"

class UMaterialInterface;

UCLASS(Blueprintable, CollapseCategories, EditInlineNew)
class GUNFIRERUNTIME_API UAnimNotifyState_MaterialParam : public UConditionalAnimNotifyState {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ComponentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInterface* Material;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName MaterialParam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float from;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float to;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EEaseType EaseType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Exponent;
    
public:
    UAnimNotifyState_MaterialParam();
};

