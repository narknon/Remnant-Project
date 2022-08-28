#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "ReplicatedMovementInfo.h"
#include "ReplicatedMovementComponent.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UReplicatedMovementComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere)
    uint16 BufferTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExtrapolationSmoothTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ExtrapolationTeleportThresh;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_MovementInfo, meta=(AllowPrivateAccess=true))
    FReplicatedMovementInfo MovementInfo;
    
public:
    UReplicatedMovementComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
protected:
    UFUNCTION(BlueprintCallable, Server, Unreliable, WithValidation)
    void ServerMoveUpdate(const FReplicatedMovementInfo& Info);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_MovementInfo();
    
    UFUNCTION(Client, Unreliable)
    void ClientAckMove(uint16 MoveTime);
    
};

