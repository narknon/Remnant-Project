#pragma once
#include "CoreMinimal.h"
#include "ChromaSDKColorFrame2D.h"
#include "UObject/Object.h"
#include "EChromaSDKDevice2DEnum.h"
#include "ChromaSDKPluginAnimation2DObject.generated.h"

UCLASS(Blueprintable)
class CHROMASDKPLUGIN_API UChromaSDKPluginAnimation2DObject : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    TEnumAsByte<EChromaSDKDevice2DEnum::Type> Device;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FChromaSDKColorFrame2D> Frames;
    
    UChromaSDKPluginAnimation2DObject();
    UFUNCTION(BlueprintCallable)
    void Unload();
    
    UFUNCTION(BlueprintCallable)
    bool IsLoaded();
    
};

