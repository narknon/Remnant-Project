#pragma once
#include "CoreMinimal.h"
#include "SceneVisual.h"
#include "TagVisual.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UTagVisual : public USceneVisual {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AnimSoundTags;
    
    UTagVisual();
};

