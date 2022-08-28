#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ZoneLinkInfo.h"
#include "RemnantUtil.generated.h"

class AZoneActor;

UCLASS(Blueprintable)
class REMNANT_API URemnantUtil : public UObject {
    GENERATED_BODY()
public:
    URemnantUtil();
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool IsGameSessionReady(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetGameSeed();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetBaseZoneLinkByLabel(const UObject* WorldContextObject, const FString& Label, FZoneLinkInfo& OutZoneLink);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool GetBaseZoneLink(const UObject* WorldContextObject, FZoneLinkInfo& OutZoneLink);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static int32 GetBaseZoneID();
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static AZoneActor* GetBaseZoneActor(const UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static bool CanPlayerExitGame(const UObject* WorldContextObject);
    
};

