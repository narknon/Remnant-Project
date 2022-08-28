#pragma once
#include "CoreMinimal.h"
#include "EGfeSDKScope.h"
#include "EGfeSDKPermission.h"
#include "GfeSDKCreateResponse.generated.h"

USTRUCT(BlueprintType)
struct FGfeSDKCreateResponse {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint16 VersionMajor;
    
    UPROPERTY(EditAnywhere)
    uint16 VersionMinor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString NVIDIAGfeVersion;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGfeSDKScope, EGfeSDKPermission> ScopePermissions;
    
    NVIDIAGFESDK_API FGfeSDKCreateResponse();
};

