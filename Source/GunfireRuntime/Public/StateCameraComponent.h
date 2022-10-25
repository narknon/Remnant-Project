#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "Camera/CameraTypes.h"
#include "Camera/CameraComponent.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "StateCameraComponent.generated.h"

class USceneComponent;
class AActor;
class UCameraState;
class ACharacter;
class APlayerControllerGunfire;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UStateCameraComponent : public UCameraComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraState> DefaultCameraState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraState> FlyCameraState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UCameraState> FixedCameraState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HMDComponentName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AimBone;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector AimBonePitchAxis;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AimBoneScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinControllerSensitivityScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxControllerSensitivityScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MinMouseSensitivityScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxMouseSensitivityScalar;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    float MaxPlatformCamPivotSmoothTime;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacter* Character;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCameraState* CurrentCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UCameraState* PreviousCamera;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* ActiveCameraActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    USceneComponent* HMDComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* AnimatedCameraActor;
    
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxRecoveryAngle;
    
    UStateCameraComponent();
    UFUNCTION(BlueprintCallable)
    void ToggleSecondaryFlyCamera();
    
    UFUNCTION(BlueprintCallable)
    void ToggleFlyCamera(bool bUseSecondGamepad);
    
    UFUNCTION(BlueprintCallable)
    void SetInputEnabled(bool Enabled);
    
    UFUNCTION(BlueprintCallable)
    void SetCameraState(UCameraState* State, float BlendTime);
    
    UFUNCTION(BlueprintCallable)
    void SetAnimatedCameraFOV(float CameraFOV);
    
    UFUNCTION(BlueprintCallable)
    void ResetView(bool bHardReset);
    
    UFUNCTION(BlueprintCallable)
    void ResetFromCurrentView(float BlendTime);
    
    UFUNCTION(BlueprintCallable)
    void HardReset(FMinimalViewInfo NewCameraParams, TSubclassOf<UCameraState> NewState);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    APlayerControllerGunfire* GetPlayerController() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UCameraState* GetCurrentCamera() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ACharacter* GetCharacter() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetCameraTransform() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FRotator GetCameraRotation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetCameraLocation() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetCameraActor() const;
    
    UFUNCTION(BlueprintCallable)
    void ExitFlyCamera();
    
    UFUNCTION(BlueprintCallable)
    void ExitAnimatedCamera();
    
    UFUNCTION(BlueprintCallable)
    void EnterFlyCamera(bool bUseSecondGamepad);
    
    UFUNCTION(BlueprintCallable)
    void EnterAnimatedCamera(AActor* RefActor, const FName& CameraBone, bool AllowInput, float BlendTime, float BlendOutTime, float CameraFOV, bool LockCameraState);
    
    UFUNCTION(BlueprintCallable)
    void AnimatedCameraCut(AActor* RefActor, const FName& CameraBone, float CameraFOV);
    
};

