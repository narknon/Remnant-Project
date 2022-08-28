#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameFramework/Actor.h"
#include "EMiniMapStyle.h"
#include "EMiniMapMode.h"
#include "MiniMapActorRef.h"
#include "UObject/NoExportTypes.h"
#include "MiniMapEntry.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "UObject/NoExportTypes.h"
#include "MiniMapActorInfo.h"
#include "MiniMapDisplayActor.generated.h"

class AMiniMapActor;
class UMiniMapPanel;
class UMiniMapManager;
class UUserWidget;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API AMiniMapDisplayActor : public AActor {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DisplayRange;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMiniMapMode MiniMapMode;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultScaleMini;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DefaultScaleFull;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName NameID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool AutoInit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DisplayRangeVertical;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EMiniMapStyle MiniMapStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float HorizontalDisplayPower;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScaleMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ScaleMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bShouldClampPanOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PanOffsetMin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector PanOffsetMax;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 NumChangeVisibilityPerFrame;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName BoundsOverride;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FVector Origin;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    float CurrentScale;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FVector CurrentPanOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Replicated, meta=(AllowPrivateAccess=true))
    FRotator CurrentRotationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FMiniMapEntry> Actors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, ReplicatedUsing=OnRep_SelectedActors, meta=(AllowPrivateAccess=true))
    TArray<FMiniMapActorRef> SelectedActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FMiniMapActorRef> CachedSelectedActors;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AMiniMapActor* LockedActor;
    
    UPROPERTY(EditAnywhere, Export, Transient)
    TArray<TWeakObjectPtr<UMiniMapPanel>> MiniMapPanels;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, Transient, meta=(AllowPrivateAccess=true))
    UMiniMapManager* MiniMapManager;
    
public:
    AMiniMapDisplayActor();
    virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float WorldToMapScale(float NewScale) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector WorldToMapCoord(const FVector& Coord) const;
    
    UFUNCTION(BlueprintCallable)
    void UnregisterMiniMapPanel(UMiniMapPanel* Panel);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetOriginLocation(const FVector& WorldLocation);
    
    UFUNCTION(BlueprintAuthorityOnly, BlueprintCallable)
    void SetOrigin(AMiniMapActor* OriginActor);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void SetMiniMapMode(const EMiniMapMode Mode);
    
    UFUNCTION(BlueprintCallable)
    void SetIsIndicator(AMiniMapActor* Actor, bool Indicator);
    
    UFUNCTION(BlueprintCallable)
    void SetDisplayLevel(int32 NewLevel);
    
protected:
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetScale(float NewScale);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSetPanOffset(FVector Offset);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSelect(const FMiniMapActorRef& Actor, bool MultiSelect, bool bStaySelected);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerScaleTo(float NewScale, float Time);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerPanTo(const FVector& Offset, float Time);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDeSelectAll();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerDeSelect(const FMiniMapActorRef& Actor);
    
public:
    UFUNCTION(BlueprintCallable)
    void Select(AMiniMapActor* Actor, bool MultiSelect, bool bStaySelected);
    
    UFUNCTION(BlueprintCallable)
    void ScaleTo(float NewScale, float Time);
    
protected:
    UFUNCTION(BlueprintCallable)
    void Scale(float NewScale);
    
    UFUNCTION(BlueprintCallable)
    void Rotate(const FRotator& Rotation);
    
public:
    UFUNCTION(BlueprintCallable)
    void RegisterMiniMapPanel(UMiniMapPanel* Panel);
    
    UFUNCTION(BlueprintCallable)
    void PanToActor(AActor* MiniMapActor, float Time);
    
    UFUNCTION(BlueprintCallable)
    void PanTo(const FVector& Offset, float Time);
    
protected:
    UFUNCTION(BlueprintCallable)
    void Pan(const FVector& Translation);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnScale(float NewScale);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnRotate(const FRotator& Rotation);
    
private:
    UFUNCTION(BlueprintCallable)
    void OnRep_SelectedActors();
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRemoveMiniMapActor(AMiniMapActor* Actor);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPreInitMap(AActor* MiniMapRefActor);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnPostInitMap(AActor* MiniMapRefActor);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void OnPan(const FVector& Translation);
    
    UFUNCTION(BlueprintCallable)
    void OnMiniMapActorRemoved(int32 ID);
    
    UFUNCTION(BlueprintCallable)
    void OnMiniMapActorLevelChanged(int32 ID, int32 NewLevel);
    
    UFUNCTION(BlueprintCallable)
    void OnMiniMapActorAdded(int32 ID);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnAddMiniMapActor(AMiniMapActor* Actor);
    
    UFUNCTION(BlueprintCallable, NetMulticast, Reliable)
    void MulticastSelectDeselect(const FMiniMapActorRef& Actor);
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float MapToWorldScale(float NewScale) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector MapToWorldCoord(const FVector& Coord) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsSelected(AMiniMapActor* Actor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsActorOnMiniMap(AActor* RefActor) const;
    
    UFUNCTION(BlueprintCallable)
    void InitMap(AActor* MiniMapRefActor);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<UUserWidget*> GetWidgetsForActor(const FMiniMapEntry& MiniMapActor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FBox GetTotalBoundingBox();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<AMiniMapActor*> GetSelectedActors() const;
    
    UFUNCTION(BlueprintCallable)
    AMiniMapActor* GetSelectedActor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    void GetMiniMapScreenWindow(FVector2D& OutOffset, float& OutScale) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTransform GetMiniMapScreenTransform(FMiniMapEntry& ReferenceActor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetMiniMapRefActor() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FMiniMapActorInfo> GetMinimapActors() const;
    
    UFUNCTION(BlueprintCallable)
    AMiniMapActor* GetMiniMapActorFor(AActor* Actor);
    
protected:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AMiniMapActor* GetLockedActor() const;
    
public:
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetDisplayLevel() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetActorByContext(int32 Context, FMiniMapEntry& OutMiniMapActor) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool GetActor(AActor* RefActor, FMiniMapEntry& OutMiniMapActor) const;
    
    UFUNCTION(BlueprintCallable)
    void DeSelectAll();
    
    UFUNCTION(BlueprintCallable)
    void DeSelect(AMiniMapActor* Actor);
    
    UFUNCTION(BlueprintCallable)
    void CenterToOrigin();
    
    UFUNCTION(BlueprintCallable)
    void Center(AMiniMapActor* ActorToCenterOn, bool bLock);
    
};

