#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Checkpoint.generated.h"

class ARemnantCharacter;

UCLASS(Blueprintable)
class REMNANT_API ACheckpoint : public AActor {
    GENERATED_BODY()
public:
    ACheckpoint();
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnFinishActivation();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnEndGrab(ARemnantCharacter* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBeginGrab(ARemnantCharacter* Player);
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnBeginActivation();
    
    UFUNCTION(BlueprintCallable, BlueprintImplementableEvent)
    void OnActivate();
    
    UFUNCTION(BlueprintCallable, BlueprintNativeEvent, BlueprintPure)
    bool CanCheckpointActivate() const;
    
};

