#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Engine/EngineTypes.h"
#include "ENavigationType.h"
#include "OnPhysicsBoundsChangedDelegateDelegate.h"
#include "UObject/NoExportTypes.h"
#include "CharacterMovementComponentGunfire.generated.h"

class AActor;
class ACharacterGunfire;
class APhysicsBounds;
class UPhysicsBoundsType;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UCharacterMovementComponentGunfire : public UCharacterMovementComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float MaxSpeedBackwards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    bool bAllowVerticalInputAcceleration;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIgnoreZFrictionAndBrakingWhenFlying;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DoSoftCharacterCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SoftCharacterCollisionWeight;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SoftCharacterCollisionRadius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacterGunfire* SoftCharacterIgnore;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool DoSpecialCharacterCollision;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 SpecialCharacterCollisionIterations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SpecialCharacterCollisionAlpha;
    
    UPROPERTY(EditAnywhere)
    TMap<TEnumAsByte<EMovementMode>, float> MaxSpeedOverrides;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurnSmoothTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CrouchedRadius;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool ConstrainToNavMesh;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerchSimpleRadius;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bPerchFallingRadiusChange;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerchFallingRadius;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float PerchFallingThreshold;
    
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool PerchShowDebug;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float KnockBackImpulseScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float KnockUpImpulseScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WallSlideDampenThresholdDeg;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float WallSlideDampenMulti;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AcceptanceRadiusScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AcceptanceHeightScale;
    
    UPROPERTY(EditAnywhere)
    TEnumAsByte<ENavigationType> DefaultNavigationType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FullTurnSpeedVelocity;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPhysicsBoundsChangedDelegate OnPhysicsBoundsChangedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnPhysicsBoundsChangedDelegate OnWaterBoundsChangedEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAutoSetSwimmingMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bStartWithSwimmingDisabled;
    
    UCharacterMovementComponentGunfire();
    UFUNCTION(BlueprintCallable)
    void SetSwingConstraint(bool Enabled, const FVector& SwingPoint, float RopeLength);
    
    UFUNCTION(BlueprintCallable)
    void SetNavigationType(TEnumAsByte<ENavigationType> NavigationType);
    
    UFUNCTION(BlueprintCallable)
    void SetCanSwim(bool bInCanSwim);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool Is3DNavigating() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetWaterBoundsActor(bool bConstrainToFluidFilled) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APhysicsBounds* GetWaterBounds(bool bConstrainToFluidFilled) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetPhysicsBoundsActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APhysicsBounds* GetPhysicsBounds() const;
    
    UFUNCTION(BlueprintPure)
    TEnumAsByte<ENavigationType> GetNavigationType() const;
    
    UFUNCTION(BlueprintCallable)
    FString GetDebugInfo(int32 DebugLevel) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UPhysicsBoundsType> GetCurrentWaterBoundsType(bool bConstrainToFluidFilled) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TSubclassOf<UPhysicsBoundsType> GetCurrentPhysicsBoundsType() const;
    
    UFUNCTION(BlueprintCallable)
    void AddExternalVelocity(FVector ExternalVelocityIn);
    
};

