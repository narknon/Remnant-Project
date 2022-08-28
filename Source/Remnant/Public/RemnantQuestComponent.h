#pragma once
#include "CoreMinimal.h"
#include "QuestComponent.h"
#include "RemnantQuestComponent.generated.h"

class APlayerController;
class ARemnantQuest;
class URemnantQuestTile;
class URemnantQuestZone;
class AZoneActor;
class URemnantQuestEntity;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantQuestComponent : public UQuestComponent {
    GENERATED_BODY()
public:
    URemnantQuestComponent();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    bool IsZoneLoaded();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    AZoneActor* GetZone();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FName GetUniqueName();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARemnantQuest* GetRootQuest();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    ARemnantQuest* GetRemnantQuest();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URemnantQuestZone* GetQuestZone();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URemnantQuestTile* GetQuestTile();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    URemnantQuestEntity* GetQuestEntity();
    
    UFUNCTION(BlueprintCallable)
    void DebugTravelTo(APlayerController* Player);
    
    UFUNCTION(BlueprintCallable)
    bool DebugCanTravelTo();
    
};

