#pragma once
#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "TargetTraceParams.h"
#include "HeuristicBoundsHitResult.h"
#include "TargetingComponent.generated.h"

class UTargetManager;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UTargetingComponent : public USceneComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCacheTargetOnTick;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FTargetTraceParams TargetTraceParams;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FHeuristicBoundsHitResult CurrentTargetHitResult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    FHeuristicBoundsHitResult CurrentSnapTargetHitResult;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UTargetManager* TargetManager;
    
public:
    UTargetingComponent();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnNewTargetSet(FHeuristicBoundsHitResult& NewTargetHitResult);
    
    UFUNCTION(BlueprintCallable)
    bool GetTarget(FHeuristicBoundsHitResult& OutTargetHitResult, bool bForceRecalc);
    
    UFUNCTION(BlueprintCallable)
    bool GetSnapTarget(FHeuristicBoundsHitResult& OutSnapTargetHitResult, bool bForceRecalc);
    
};

