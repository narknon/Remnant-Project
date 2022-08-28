#pragma once
#include "CoreMinimal.h"
#include "Templates/SubclassOf.h"
#include "SpentTraitPointValidationInfo.h"
#include "TraitsComponent.h"
#include "TraitInfo.h"
#include "TraitValidationInfo.h"
#include "TraitPointValidationInfo.h"
#include "RemnantTraitsComponent.generated.h"

class UTrait;

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class REMNANT_API URemnantTraitsComponent : public UTraitsComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFailAddIfTraitMaxLevel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UTrait> ValidTraitType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MaxTraitPointIncrement;
    
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FTraitPointValidationInfo> TraitPointValidationInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TArray<FSpentTraitPointValidationInfo> SpentTraitPointValidationInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TSubclassOf<UTrait>, FTraitValidationInfo> TraitLevelValidationInfo;
    
public:
    URemnantTraitsComponent();
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerAddTraitPoints(int32 Points);
    
    UFUNCTION(BlueprintCallable)
    void MarkClientTraitPointChangeValid(int32 AddedTraitPoints);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<FTraitInfo> GetTraitsForLevel(int32 Level) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    TArray<int32> GetTraitLevelBands() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    FTraitInfo GetTraitByLevelAndCategory(int32 Level, const FName& Category) const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetTotalAvailableTraits() const;
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    int32 GetNumAvailableTraits() const;
    
protected:
    UFUNCTION(BlueprintCallable)
    void ClientTraitPointTimeOut();
    
    UFUNCTION(BlueprintCallable)
    void ClientTraitLevelTimeOut();
    
    UFUNCTION(BlueprintCallable)
    void ClientSpentTraitPointTimeOut();
    
};

