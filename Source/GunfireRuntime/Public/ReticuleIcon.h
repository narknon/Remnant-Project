#pragma once
#include "CoreMinimal.h"
#include "ReticulePiece.h"
#include "Engine/Canvas.h"
#include "ReticuleIcon.generated.h"

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UReticuleIcon : public UReticulePiece {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FCanvasIcon Icon;
    
    UReticuleIcon();
};

