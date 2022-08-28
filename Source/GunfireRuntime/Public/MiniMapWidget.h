#pragma once
#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UObject/NoExportTypes.h"
#include "Slate/WidgetTransform.h"
#include "MiniMapWidget.generated.h"

class AActor;
class AMiniMapDisplayActor;
class UMiniMapPanel;

UCLASS(Blueprintable, EditInlineNew)
class GUNFIRERUNTIME_API UMiniMapWidget : public UUserWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D DefaultWidgetCullBounds;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ZOrder;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AMiniMapDisplayActor* MiniMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    AActor* CachedRefActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    int32 Context;
    
public:
    UMiniMapWidget();
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    FWidgetTransform UpdateMiniMapWidget(const FWidgetTransform& InTransform);
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent)
    void UpdateLevelVisibility(int32 DisplayLevel, int32 MyLevel);
    
    UFUNCTION(BlueprintCallable)
    void SetDynamicSize(const FVector2D& DynamicSize);
    
    UFUNCTION(BlueprintCallable)
    void SetCullBounds(const FVector2D& CullBounds);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnRegisteredToPanel(UMiniMapPanel* MiniMapPanel);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetZOrder() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AActor* GetMiniMapRefActor();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AMiniMapDisplayActor* GetMiniMap() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FVector2D GetDefaultWidgetCullBounds() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetContext() const;
    
};

