#pragma once
#include "CoreMinimal.h"
#include "StateChangeDelegateDelegate.h"
#include "Components/ActorComponent.h"
#include "InteractiveInfo.h"
#include "InteractiveDelegateDelegate.h"
#include "StateCompleteDelegateDelegate.h"
#include "StateID.h"
#include "UObject/NoExportTypes.h"
#include "HitReactionType.h"
#include "StateMachineComponent.generated.h"

class ACharacterGunfire;
class UStateMachine;
class UActorState;
class UAnimInstanceGunfire;
class AActor;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UStateMachineComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UStateMachine* StateMachine;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FName StartState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AnimationLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FlinchAnimationLayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool Secondary;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStateChangeDelegate OnStateChange;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStateCompleteDelegate OnStateComplete;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FStateCompleteDelegate OnStateInterruptUpdate;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FInteractiveDelegate OnInteractive;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ACharacterGunfire* Character;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_InteractiveInfo, meta=(AllowPrivateAccess=true))
    FInteractiveInfo InteractiveInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UActorState* CurrentState;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_CurrentStateID, meta=(AllowPrivateAccess=true))
    FStateID CurrentStateID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UAnimInstanceGunfire* AnimInstance;
    
public:
    UStateMachineComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void SetWindow(const FName& Name);
    
    UFUNCTION(BlueprintCallable)
    bool SetState(const FName& NameID, bool bOnlySetIfValid);
    
    UFUNCTION(BlueprintCallable)
    void SetEvent(const FName& Name);
    
protected:
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSetTraversalState(FStateID StateID, float Heading, const FVector& Position, uint8 CurrentClientAck);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSetState(FStateID StateID, float LockDirection, uint8 CurrentClientAck);
    
    UFUNCTION(Reliable, Server, WithValidation)
    void ServerSetInteractiveResult(uint8 State, float MashValue);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDoInteractive(const FName& NameID, AActor* Other);
    
public:
    UFUNCTION(BlueprintCallable)
    bool ResetStateToDefault(bool bOnlySetIfValid);
    
protected:
    UFUNCTION(BlueprintCallable)
    void ProcessStateMachine(float DeltaTime);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_InteractiveInfo();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_CurrentStateID();
    
    UFUNCTION(BlueprintCallable)
    void OnPostComputeStats();
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastDoFlinch(FName NameID, FName HitLocation);
    
public:
    UFUNCTION(BlueprintCallable)
    bool IsWindowSet(const FName& Name);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsInterruptible() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsEventSet(const FName& Name);
    
    UFUNCTION(BlueprintCallable)
    void InitAnimInstance();
    
    UFUNCTION(BlueprintCallable)
    bool InInteractive();
    
    UFUNCTION(BlueprintCallable)
    FName GetStateName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetInteractiveOther() const;
    
    UFUNCTION(BlueprintCallable)
    HitReactionType GetHitReactionType();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetElapsedStateTime() const;
    
    UFUNCTION(BlueprintCallable)
    FString GetDebugInfo(int32 DebugLevel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UActorState* GetCurrentState();
    
    UFUNCTION(BlueprintCallable)
    bool DoInteractive(const FName& NameID, AActor* Other);
    
protected:
    UFUNCTION(Client, Reliable)
    void ClientSetState(FStateID State, float LockDirection, uint8 CurrentClientAck);
    
    UFUNCTION(Client, Reliable)
    void ClientDoInteractive(FInteractiveInfo Info, FStateID State, uint8 NewClientAck);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientAbortInteractive();
    
public:
    UFUNCTION(BlueprintCallable)
    void ClearWindow(const FName& Name, bool bClearAll);
    
    UFUNCTION(BlueprintCallable)
    void BeginLerp(float Time, bool LerpPosition, bool LerpRotation);
    
};

