#pragma once
#include "CoreMinimal.h"
#include "PlayerStateGunfire.h"
#include "ChatRestrictionChangedDelegate.h"
#include "LocalPlayerTargetChangedDelegate.h"
#include "PlayerStateRemnant.generated.h"

UCLASS(Blueprintable)
class REMNANT_API APlayerStateRemnant : public APlayerStateGunfire {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FChatRestrictionChanged OnChatRestrictionChanged;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLocalPlayerTargetChanged OnLocalPlayerTargetChanged;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_Traveling, meta=(AllowPrivateAccess=true))
    bool bTraveling;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, ReplicatedUsing=OnRep_ChatRestricted, meta=(AllowPrivateAccess=true))
    bool bIsChatRestricted;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bIsLocalPlayerTarget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    bool bIsHost;
    
public:
    APlayerStateRemnant();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void SetIsLocalPlayerTarget(bool IsTarget);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetChatRestricted(bool ChatRestricted);
    
    UFUNCTION(BlueprintCallable)
    void OnRep_Traveling();
    
    UFUNCTION(BlueprintCallable)
    void OnRep_ChatRestricted();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsTraveling() const;
    
    UFUNCTION(BlueprintCallable)
    bool IsChatRestricted();
    
};

