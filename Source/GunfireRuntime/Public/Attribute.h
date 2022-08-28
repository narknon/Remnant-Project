#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Attribute.generated.h"


USTRUCT(BlueprintType)
struct FAttribute {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true), Category = "Gunfire")
    FName ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true), Category = "Gunfire")
    FText Label;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true), Category = "Gunfire")
    FText Description;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true), Category = "Gunfire")
    int32 Level;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true), Category = "Gunfire")
    UDataTable* StatsTable;
    
    GUNFIRERUNTIME_API FAttribute();
};

