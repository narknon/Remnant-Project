#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EAwarenessSignal.h"
#include "UObject/NoExportTypes.h"
#include "AIAwarenessManager.generated.h"

class AActor;
class AAIControllerGunfire;
class UAIAwarenessManager;
class UObject;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UAIAwarenessManager : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxUpdatesPerFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldUpdateAwareness;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<AAIControllerGunfire*> Controllers;
    
public:
    UAIAwarenessManager();
    UFUNCTION(BlueprintCallable)
    void SendAwarenessSignalSegment(EAwarenessSignal Type, AActor* Source, const FVector& from, const FVector& to, float Radius);
    
    UFUNCTION(BlueprintCallable)
    void SendAwarenessSignal(EAwarenessSignal Type, AActor* Source, const FVector& Position, float Radius, bool UseSourceForLastKnownPosition, bool bApplySightRangeBonus);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UAIAwarenessManager* GetInstance(UObject* WorldContextObject);
    
};

