#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "LevelInstanceStateDelegateDelegate.h"
#include "LevelInstance.generated.h"

class ULevelStreaming;

UCLASS(Blueprintable)
class ULevelInstance : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelInstanceStateDelegate OnLevelLoadedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelInstanceStateDelegate OnLevelUnloadedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelInstanceStateDelegate OnLevelShownEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelInstanceStateDelegate OnLevelHiddenEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelInstanceStateDelegate OnLevelLoadedForAllEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelInstanceStateDelegate OnLevelUnloadedForAllEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelInstanceStateDelegate OnLevelShownForAllEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelInstanceStateDelegate OnLevelHiddenForAllEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelInstanceStateDelegate OnLevelAllChildrenLoadedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelInstanceStateDelegate OnLevelAllChildrenUnloadedEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelInstanceStateDelegate OnLevelAllChildrenShownEvent;
    
    UPROPERTY(BlueprintAssignable, BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLevelInstanceStateDelegate OnLevelAllChildrenHiddenEvent;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    ULevelStreaming* LevelStreaming;
    
    ULevelInstance();
private:
    UFUNCTION(BlueprintCallable)
    void OnLevelUnloaded();
    
    UFUNCTION(BlueprintCallable)
    void OnLevelShown();
    
    UFUNCTION(BlueprintCallable)
    void OnLevelLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnLevelHidden();
    
    UFUNCTION(BlueprintCallable)
    void OnChildUnloaded();
    
    UFUNCTION(BlueprintCallable)
    void OnChildShown();
    
    UFUNCTION(BlueprintCallable)
    void OnChildLoaded();
    
    UFUNCTION(BlueprintCallable)
    void OnChildHidden();
    
};

