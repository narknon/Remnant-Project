#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "EChromaSDKDevice1DEnum.h"
#include "ChromaSDKColorFrame1D.h"
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

