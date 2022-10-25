#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ESplineAttachmentRule.h"
#include "ESplineAttachType.h"
#include "ESplineMovementDirection.h"
#include "SplineFollowCompleteEventDelegate.h"
#include "UObject/NoExportTypes.h"
#include "SplineFollowingComponent.generated.h"

class USplineComponent;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API USplineFollowingComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MovementSpeed;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<ESplineMovementDirection::Type> MovementDirection;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<ESplineAttachType::Type> AttachType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPingPong;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsPaused;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LocationOffset;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSplineFollowCompleteEvent OnSplineFollowComplete;
    
    USplineFollowingComponent();
    UFUNCTION(BlueprintCallable)
    void SetSpline(USplineComponent* Spline, TEnumAsByte<ESplineAttachmentRule::Type> Location, float CustomTime);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetCurrentSplineTime() const;
    
};

