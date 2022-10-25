#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InputButton.h"
#include "UObject/NoExportTypes.h"
#include "InputStateDelegateDelegate.h"
#include "ButtonEvent.h"
#include "InputButtonDelegateDelegate.h"
#include "UObject/NoExportTypes.h"
#include "InputStateComponent.generated.h"

class UInputHandler;
class APlayerController;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UInputStateComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FInputButton> Buttons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool StickyMovement;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float StickyMovementThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName WalkingToggleButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float MaxWalkingInput;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInputStateDelegate MoveInputEvent;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<FName, UInputHandler*> InputHandlerMap;
    
public:
    UInputStateComponent();
    UFUNCTION(BlueprintCallable)
    void SetWalking(bool InIsWalking);
    
    UFUNCTION(BlueprintCallable)
    void SetInputEnabled(bool enable);
    
    UFUNCTION(BlueprintCallable)
    void SetButtonStateByName(const FName& Name, ButtonEvent Event);
    
    UFUNCTION(BlueprintCallable)
    void ResetButton(FName ButtonName);
    
    UFUNCTION(BlueprintCallable)
    void RemoveButtonListener(const FName& Name, const FInputButtonDelegate& Event);
    
    UFUNCTION(BlueprintCallable)
    void OnSwitchCamera();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInputEnabled() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsActionPressed(APlayerController* PlayerController, FName ActionName);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasVerticalMoveInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasMoveInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool HasHorizontalMoveInput() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetScreenRelativeMoveInput(FVector Up, bool bAllowSticky, bool bAllowVerticalInput);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetRelativeMoveInput(FRotator Rotation, bool bAllowVerticalInput);
    
    UFUNCTION(BlueprintCallable)
    void GetMoveInput(UPARAM(Ref) FVector& OutMoveInput);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetIsWalking() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetCameraRotation(FRotator& OutCameraRotation, bool bAllowSticky);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector GetCameraRelativeMoveInput(FVector Up, bool bAllowSticky, bool bAllowVerticalInput);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ButtonEvent GetButtonStateByName(const FName& Name) const;
    
    UFUNCTION(BlueprintCallable)
    void AddButtonListener(const FName& Name, const FInputButtonDelegate& Event);
    
};

