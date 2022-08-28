#pragma once
#include "CoreMinimal.h"
#include "SurfaceOrientFeeler.generated.h"

USTRUCT(BlueprintType)
struct GUNFIRERUNTIME_API FSurfaceOrientFeeler {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FeelerNode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName IkVirtualBone;
    
    FSurfaceOrientFeeler();
};

