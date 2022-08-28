#pragma once
#include "CoreMinimal.h"
#include "ZoneTileDef.generated.h"

USTRUCT(BlueprintType)
struct REMNANT_API FZoneTileDef {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 X;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 Y;
    
    FZoneTileDef();
};

