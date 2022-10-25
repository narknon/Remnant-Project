#pragma once
#include "CoreMinimal.h"
#include "VisualSlot.h"
#include "Components/ActorComponent.h"
#include "OnStreamedVisualAppliedDelegate.h"
#include "VisualComponent.generated.h"

class UVisualSetSlot;
class UVisualSet;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API UVisualComponent : public UActorComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, SaveGame, meta=(AllowPrivateAccess=true))
    int32 Seed;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UVisualSet* VisualSet;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    TArray<FVisualSlot> Slots;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> VisualTags;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> AnimSoundTags;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FOnStreamedVisualApplied OnStreamedVisualApplied;
    
    UVisualComponent();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable)
    void UpdateSlots();
    
    UFUNCTION(BlueprintCallable)
    void StopAllStreamingRequests();
    
    UFUNCTION(BlueprintCallable)
    void SetVisualAt(FName SlotID, int32 Idx);
    
    UFUNCTION(BlueprintCallable)
    void SetVisual(FName SlotID, FName VisualID);
    
    UFUNCTION(BlueprintCallable)
    void SetupSlaveMeshes();
    
    UFUNCTION(BlueprintCallable)
    void SetSlotEnabled(FName SlotID, bool bIsEnabled);
    
    UFUNCTION(BlueprintCallable)
    void PlayVisualFX(FName NameID);
    
protected:
    UFUNCTION(BlueprintCallable)
    void OnVisualLoaded(FName SlotID, FName VisualID);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    UVisualSetSlot* GetVisualSlot(FName SlotID) const;
    
    UFUNCTION(BlueprintCallable)
    int32 GetVisualPositionInSlot(FName SlotID);
    
    UFUNCTION(BlueprintCallable)
    FName GetSlotVisualID(FName SlotID);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumVisualsForSlotID(FName SlotID) const;
    
    UFUNCTION(BlueprintCallable)
    void ClearVisual(FName SlotID);
    
};

