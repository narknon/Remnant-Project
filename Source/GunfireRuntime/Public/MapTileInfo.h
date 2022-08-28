#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MapTileInfo.generated.h"

class UTexture2D;
class UBoxComponent;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AMapTileInfo : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Image;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UBoxComponent* Region;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AActor* OriginPointActor;
    
    AMapTileInfo();
};

