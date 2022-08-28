#pragma once
#include "CoreMinimal.h"
#include "EventTreeStage.h"
#include "GameFramework/Actor.h"
#include "UObject/NoExportTypes.h"
#include "DialogStage.generated.h"

class UCameraComponent;
class UDialogComponent;
class APlayerController;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API ADialogStage : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDialogComponent* DialogComponent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StageActive;
    
public:
    ADialogStage();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetupStage(const FEventTreeStage& Stage);
    
protected:
    UFUNCTION(BlueprintCallable)
    void SetCameraByName(FName Name, APlayerController* TargetController);
    
    UFUNCTION(BlueprintCallable)
    void SetCamera(AActor* CameraActor, APlayerController* TargetController);
    
    UFUNCTION(BlueprintCallable)
    void SetActiveCameraComponent(AActor* Actor, UCameraComponent* Camera, APlayerController* TargetController);
    
    UFUNCTION(BlueprintCallable)
    void RestoreCamera(bool ResetToCurrentView, APlayerController* TargetController);
    
    UFUNCTION(BlueprintCallable)
    void PositionActorAtMark(AActor* Actor, FName Mark);
    
    UFUNCTION(BlueprintCallable)
    void PositionActor(AActor* Actor, const FTransform& Transform);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetActor(FName Name);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void End();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void Begin();
    
};

