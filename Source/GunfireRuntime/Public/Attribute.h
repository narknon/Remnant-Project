#pragma once
#include "CoreMinimal.h"
#include "Attribute.generated.h"

class UDataTable;

USTRUCT(BlueprintType)
struct FAttribute {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true), Category="GF")
    FName ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true), Category="GF")
    FText Label;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true), Category="GF")
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true), Category="GF")
    int32 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true), Category="GF")
    UDataTable* StatsTable;
    
    GUNFIRERUNTIME_API FAttribute();
};

