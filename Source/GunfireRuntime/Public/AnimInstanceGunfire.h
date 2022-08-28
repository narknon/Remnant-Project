#pragma once
#include "CoreMinimal.h"
#include "LegIkEffector.h"
#include "Animation/AnimInstance.h"
#include "UObject/NoExportTypes.h"
#include "AnimationLayer.h"
#include "UObject/NoExportTypes.h"
#include "AnimationHandle.h"
#include "AnimInstanceGunfire.generated.h"

class UInputStateComponent;
class UStateMachineComponent;
class APawn;
class ACharacterGunfire;
class UAnimInstanceGunfire;
class AActor;

UCLASS(Blueprintable, NonTransient)
class GUNFIRERUNTIME_API UAnimInstanceGunfire : public UAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Speed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VerticalSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TurnSpeed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float GroundSlope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Direction;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float InputDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float VerticalDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimYaw;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimPitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator LookRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FAnimationLayer> AnimationLayers;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AnimationTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseVelocityOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector VelocityOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FLegIkEffector> LegIkEffectors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool UseTargetForAim;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAdjustTargetDirectionByMeshOrientation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bCalculateGroundSlope;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bClearTimeDilationOnStateChange;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    APawn* OwningPawn;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacterGunfire* OwningCharacter;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UInputStateComponent* Input;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimInstanceGunfire* ParentAnimInstance;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<UAnimInstanceGunfire*> ChildAnimInstances;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UStateMachineComponent* CachedStateMachine;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDoNotifyTriggerRateOptimizations;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bDisableRateOptimizationsDuringCinematics;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MinNotifiesPerFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxNotifiesPerFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 QueuedNotifyFlushThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName DefaultBone;
    
    UAnimInstanceGunfire();
    UFUNCTION(BlueprintCallable)
    void UpdateLegIkEffector(const FLegIkEffector& Effector);
    
    UFUNCTION(BlueprintCallable)
    static void StopAnimation(FAnimationHandle Handle);
    
    UFUNCTION(BlueprintCallable)
    void SetParentAnimInstance(UAnimInstanceGunfire* AnimInstance);
    
    UFUNCTION(BlueprintCallable)
    void RemoveLegIkEffector(FName IkBone);
    
    UFUNCTION(BlueprintCallable)
    void RemoveChildAnimInstance(UAnimInstanceGunfire* AnimInstance);
    
    UFUNCTION(BlueprintCallable)
    void RemoveAnimationTag(FName AnimTag);
    
    UFUNCTION(BlueprintCallable)
    FAnimationHandle PlayAnimationByID(FName AnimationLayer, FName AnimationID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasAnimationTag(FName AnimTag) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UStateMachineComponent* GetStateMachine() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMoveInputDir() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetMoveDir() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UAnimInstanceGunfire* GetMasterAnimInstance(AActor* Actor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FLegIkEffector GetLegIkEffector(FName IkBone) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetHeading() const;
    
    UFUNCTION(BlueprintCallable)
    void GetAimAngles(FName RefBone, float& Yaw, float& Pitch);
    
    UFUNCTION(BlueprintCallable)
    void EnableLookPoses(bool bEnabled);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool CompareAngles(float Angle1, float Angle2, float Arc) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool AreLookPosesDisabled() const;
    
    UFUNCTION(BlueprintCallable)
    void AddChildAnimInstance(UAnimInstanceGunfire* AnimInstance);
    
    UFUNCTION(BlueprintCallable)
    void AddAnimationTag(FName AnimTag);
    
};

