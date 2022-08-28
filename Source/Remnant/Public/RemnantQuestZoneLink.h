#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "RemnantQuestComponent.h"
#include "EZoneLinkType.h"
#include "RemnantQuestZoneLink.generated.h"

class AActor;
class AZoneActor;
class UTexture2D;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantQuestZoneLink : public URemnantQuestComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EZoneLinkType Type;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Destination;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ZoneLinkNameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StartsActive;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Category;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DefaultWaypointSpawnTag;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FText Label;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AActor> WaypointBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSoftObjectPtr<UTexture2D> Image;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, SaveGame, meta=(AllowPrivateAccess=true))
    bool OwnsLink;
    
public:
    URemnantQuestZoneLink();
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSetLinkActive(AZoneActor* Zone, bool Active);
    
protected:
    UFUNCTION(BlueprintCallable)
    void MapLoaded();
    
    UFUNCTION(BlueprintCallable)
    void DestinationZoneLoaded();
    
    UFUNCTION(BlueprintCallable)
    void DestinationMapLoaded();
    
public:
    UFUNCTION(BlueprintCallable)
    void DeactivateWaypoint();
    
    UFUNCTION(BlueprintCallable)
    void ActivateWaypoint(bool SetAsRespawnPoint);
    
};

