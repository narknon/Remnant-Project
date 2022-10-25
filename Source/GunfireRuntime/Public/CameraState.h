#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Camera/CameraTypes.h"
#include "CameraState.generated.h"

class UCameraState;
class AActor;
class UStateCameraComponent;

UCLASS(Blueprintable, Config=Game)
class GUNFIRERUNTIME_API UCameraState : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float FOV;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultBlendTime;
    
    UCameraState();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    AActor* ValidateCameraActor(UStateCameraComponent* CameraManager, AActor* CameraActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnUpdate(UStateCameraComponent* CameraManager, float DeltaTime, FMinimalViewInfo& DesiredView);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnLeave(UStateCameraComponent* CameraManager);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEnter(UStateCameraComponent* CameraManager, UCameraState* PreviousState, float TransitionTime);
    
};

