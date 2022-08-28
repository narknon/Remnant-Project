#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DamageInfo.h"
#include "BlueprintFunctionLibraryGunfire.generated.h"

class UDecalComponent;
class UObject;

UCLASS(Blueprintable)
class GUNFIRERUNTIME_API UBlueprintFunctionLibraryGunfire : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UBlueprintFunctionLibraryGunfire();
    UFUNCTION(BlueprintCallable)
    static void SetFadeScreenSize(UDecalComponent* Decal, float Size);
    
    UFUNCTION(BlueprintCallable)
    static void SetDamageInfoVariableObject(UPARAM(Ref) FDamageInfo& DamageInfo, const FName& VariableName, UObject* Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetDamageInfoVariableInt(UPARAM(Ref) FDamageInfo& DamageInfo, const FName& VariableName, int32 Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetDamageInfoVariableFloat(UPARAM(Ref) FDamageInfo& DamageInfo, const FName& VariableName, float Value);
    
    UFUNCTION(BlueprintCallable)
    static void SetDamageInfoVariableBool(UPARAM(Ref) FDamageInfo& DamageInfo, const FName& VariableName, bool Value);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    static UObject* GetDefaultObject(UClass* ObjectClass);
    
};

