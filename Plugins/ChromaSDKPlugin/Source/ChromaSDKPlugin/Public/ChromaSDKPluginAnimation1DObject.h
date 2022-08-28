#pragma once
#include "CoreMinimal.h"
#include "ChromaSDKColorFrame1D.h"
//CROSS-MODULE INCLUDE V2: -ModuleName=CoreUObject -ObjectName=Object -FallbackName=Object
#include "EChromaSDKDevice1DEnum.h"
#include "ChromaSDKPluginAnimation1DObject.generated.h"

UCLASS(Blueprintable)
class CHROMASDKPLUGIN_API UChromaSDKPluginAnimation1DObject : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EChromaSDKDevice1DEnum::Type> Device;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FChromaSDKColorFrame1D> Frames;
    
    UChromaSDKPluginAnimation1DObject();
    UFUNCTION(BlueprintCallable)
    void Unload();
    
    UFUNCTION(BlueprintCallable)
    bool IsLoaded();
    
};

