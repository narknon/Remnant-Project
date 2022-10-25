#pragma once
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PersistentReference.h"
#include "PersistenceBlueprintFunctionLibrary.generated.h"

class AActor;
class USaveGameWorld;
class UPersistenceManager;
class UObject;
class USaveGameProfile;

UCLASS(Blueprintable)
class GUNFIRESAVESYSTEM_API UPersistenceBlueprintFunctionLibrary : public UBlueprintFunctionLibrary {
    GENERATED_BODY()
public:
    UPersistenceBlueprintFunctionLibrary();
    UFUNCTION(BlueprintCallable)
    static void SetReference(UPARAM(Ref) FPersistentReference& Reference, AActor* InActor);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void SetDisableCommit(UObject* WorldContextObject, bool DisableCommit);
    
    UFUNCTION(BlueprintCallable, BlueprintPure, meta=(WorldContext="WorldContextObject"))
    static AActor* GetReference(UObject* WorldContextObject, UPARAM(Ref) FPersistentReference& Reference);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static USaveGameProfile* GetProfileSave(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static UPersistenceManager* GetPersistenceManager(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static USaveGameWorld* GetCurrentSave(UObject* WorldContextObject);
    
    UFUNCTION(BlueprintCallable)
    static void CopyReference(const FPersistentReference& from, UPARAM(Ref) FPersistentReference& to);
    
    UFUNCTION(BlueprintCallable, meta=(WorldContext="WorldContextObject"))
    static void CommitSave(UObject* WorldContextObject, const FString& Reason);
    
    UFUNCTION(BlueprintCallable)
    static void ClearReference(UPARAM(Ref) FPersistentReference& Reference);
    
};

