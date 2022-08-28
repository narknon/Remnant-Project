// Copyright 2019 ElgSoft. All rights reserved. 
// Elg001.ElgEditorScripting - ElgSoft.com

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Templates/SubclassOf.h"
#include <AssetData.h>
#include "ElgEditorBP_Enum.h"
#include "ElgEditorBP_UBlueprint.generated.h"

class UBlueprint;
class UActorComponent;
class UInterface;
struct FAssetData;
class UObject;



#pragma region Struct

USTRUCT(BlueprintType)
struct FS_ElgBlueprintNodeStats
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NodeStats")
		UBlueprint* Blueprint;

	UPROPERTY(BlueprintReadOnly, Category = "NodeStats")
		FString BlueprintName;

	UPROPERTY(BlueprintReadOnly, Category = "NodeStats")
		TArray<FString> DisplayNamesSorted;

	UPROPERTY(BlueprintReadOnly, Category = "NodeStats")
		TArray<FString> DisplayNamesCountSorted;

	UPROPERTY(BlueprintReadOnly, Category = "NodeStats")
		TArray<FString> NodeTypeSorted;

	UPROPERTY(BlueprintReadOnly, Category = "NodeStats")
		TArray<FString> NodeTypeCountSorted;

	UPROPERTY(BlueprintReadOnly, Category = "NodeStats")
		TMap<FString, int32> DisplayNameCountMap;

	UPROPERTY(BlueprintReadOnly, Category = "NodeStats")
		TMap<FString, int32> NodeTypeCountMap;

	UPROPERTY(BlueprintReadOnly, Category = "NodeStats")
		TMap<FString, FString> DisplayTypeMap;

	UPROPERTY(BlueprintReadOnly, Category = "NodeStats")
		int32 NodeCount;

	FS_ElgBlueprintNodeStats() {
		Blueprint = nullptr;
		BlueprintName = "";
		DisplayNamesSorted.Empty();
		DisplayNamesCountSorted.Empty();
		NodeTypeSorted.Empty();
		NodeTypeCountSorted.Empty();
		DisplayNameCountMap.Empty();
		NodeTypeCountMap.Empty();
		DisplayTypeMap.Empty();
		NodeCount = 0;
	}
};


USTRUCT(BlueprintType)
struct FS_ElgBlueprintsNodeStats
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(BlueprintReadOnly, Category = "NodeStats")
		int32 BlueprintCount;

	UPROPERTY(BlueprintReadOnly, Category = "NodeStats")
		int32 NodeCount;

	UPROPERTY(BlueprintReadOnly, Category = "NodeStats")
		TArray<FString> NodeTypeSorted;

	UPROPERTY(BlueprintReadOnly, Category = "NodeStats")
		TArray<FString> NodeCountSorted;

	UPROPERTY(BlueprintReadOnly, Category = "NodeStats")
		TMap<FString, int32> NodeTypeCountMap;

	UPROPERTY(BlueprintReadOnly, Category = "NodeStats")
		TArray<FS_ElgBlueprintNodeStats> Stats;


	FS_ElgBlueprintsNodeStats() {
		BlueprintCount = 0;
		NodeCount = 0;
		NodeTypeSorted.Empty();
		NodeCountSorted.Empty();
		NodeTypeCountMap.Empty();
		Stats.Empty();
	}
};

#pragma endregion

/**
 * 
 */
UCLASS()
class ELGEDITORSCRIPTING_API UElgEditorBP_UBlueprint : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


#pragma region GetBlueprint

	/* Get the UBlueprint object from the AssetData */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint", meta = (ExpandEnumAsExecs = "Branches", Keywords = "ElgSoft Editor Blueprint"))
		static UBlueprint* GetBlueprintFromAssetData(const FAssetData& AssetDataStruct, EBPEditorOutputValidBranch& Branches);

	/* Get the UBlueprint object from an UObject */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint", meta = (ExpandEnumAsExecs = "Branches", Keywords = "ElgSoft Editor Blueprint"))
		static UBlueprint* GetBlueprintFromObject(UObject* Object, EBPEditorOutputValidBranch& Branches);

	/* */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint")
		static TArray<UBlueprint*> GetBlueprintsFromObjects(TArray<UObject*> Objects);

	/* Get all blueprints in the Path */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint")
		static TArray<UBlueprint*> GetBlueprintsByPath(const FName Path, const bool RecursivePaths/*=true*/);

#pragma endregion

#pragma region GetComponents

	/* Returns an array with all the ActorComponents the blueprint has. */
	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint|Component", meta = (DisplayName = "GetComponents", Keywords = "ElgSoft Editor Blueprint"))
		static TArray<UActorComponent*> GetBlueprintComponents(UBlueprint* Blueprint, const bool ExcludeInherited = false);

	/* Returns the first component of the right class */
	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint|Component", meta = (DisplayName = "GetComponentOfClass", Keywords = "ElgSoft Editor Blueprint", DeterminesOutputType = "ComponentClass"))
		static UActorComponent* GetBlueprintComponentOfClass(UBlueprint* Blueprint, TSubclassOf<UActorComponent> ComponentClass, const bool ExcludeInherited = false);

	/* Returns the first component of the right class with an branch output pins */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint|Component", meta = (DisplayName = "GetComponentOfClassBranch", Keywords = "ElgSoft Editor Blueprint", ExpandEnumAsExecs = "Branches", DeterminesOutputType = "ComponentClass", ExcludeInherited = "false"))
		static UActorComponent* GetBlueprintComponentOfClassBranch(UBlueprint* Blueprint, TSubclassOf<UActorComponent> ComponentClass, const bool ExcludeInherited, EBPEditorOutputValidBranch& Branches);

	/* Returns all the components of the right class */
	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint|Component", meta = (DisplayName = "GetComponentsOfClass", Keywords = "ElgSoft Editor Blueprint", DeterminesOutputType = "ComponentClass"))
		static TArray<UActorComponent*> GetBlueprintComponentsOfClass(UBlueprint* Blueprint, TSubclassOf<UActorComponent> ComponentClass, const bool ExcludeInherited = false);

	/* Returns all the components of the right class with an branch output pins*/
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint|Component", meta = (DisplayName = "GetComponentsOfClassBranch", Keywords = "ElgSoft Editor Blueprint", ExpandEnumAsExecs = "Branches", DeterminesOutputType = "ComponentClass", ExcludeInherited="false"))
		static TArray<UActorComponent*> GetBlueprintComponentsOfClassBranch(UBlueprint* Blueprint, TSubclassOf<UActorComponent> ComponentClass, const bool ExcludeInherited, EBPEditorOutputValidBranch& Branches);

	/* Add an Component to the Blueprint, if the Blueprint is open you must recompile for it to show up. */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint|Component", meta = (DisplayName = "Add Component", Keywords = "ElgSoft Editor Blueprint"))
		static void BlueprintAddComponent(UBlueprint* Blueprint, TSubclassOf<UActorComponent> ComponentClass);

	/* Remove Component(s) from the Blueprint, if the Blueprint is open you must recompile for it to show up.
	@param  Blueprint		The blueprint asset to remove the component from.
	@param  ComponentClass	The class of component(s) to remove.
	@param  bOnlyFirst		Should it only remove the first or all the instances of the class?
	*/
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint|Component", meta = (DisplayName = "Remove Component", Keywords = "ElgSoft Editor Blueprint"))
		static void BlueprintRemoveComponent(UBlueprint* Blueprint, TSubclassOf<UActorComponent> ComponentClass, const bool bOnlyFirst = false);

	/* Return if the blueprint supports components or not */
	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint|Component", meta = (DisplayName = "Support Component", Keywords = "ElgSoft Editor Blueprint"))
		static bool BlueprintSupportComponent(UBlueprint* Blueprint);

	/* Return if the blueprint supports components or not with a branch pins*/
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint|Component", meta = (DisplayName = "Support Component Branch", Keywords = "ElgSoft Editor Blueprint", ExpandEnumAsExecs = "Branches"))
		static void BlueprintSupportComponentBranch(UBlueprint* Blueprint, EBPEditorOutputBranch& Branches);


#pragma endregion

#pragma region Interfaces

	/* Returns an array with all the Interfaces the blueprint has. */
	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint|Interface", meta = (DisplayName = "GetInterfaces", Keywords = "ElgSoft Editor Blueprint"))
		static TArray<TSubclassOf<UInterface>> GetBlueprintInterfaces(UBlueprint* Blueprint, const bool ExcludeInherited = false);

	/* Check if the blueprint has the Interfaces of the class */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint|Interface", meta = (DisplayName = "ImplementInterface", Keywords = "ElgSoft Editor Blueprint", ExpandEnumAsExecs = "Branches", DeterminesOutputType = "InterfaceClass"))
		static void BlueprintImplementInterface(UBlueprint* Blueprint, TSubclassOf<UInterface> InterfaceClass, EBPEditorOutputBranch& Branches);

	/* Add an Interface to the blueprint */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint|Interface", meta = (DisplayName = "Add Interface", Keywords = "ElgSoft Editor Blueprint"))
		static void BlueprintAddInterface(UBlueprint* Blueprint, TSubclassOf<UInterface> InterfaceClass);

	/*  
		Remove an interface from the blueprint.
		If bPreserveFunctions is true, then the interface will move its functions to be normal implemented blueprint functions
	*/
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint|Interface", meta = (DisplayName = "Remove Interface", Keywords = "ElgSoft Editor Blueprint"))
		static void BlueprintRemoveInterface(UBlueprint* Blueprint, TSubclassOf<UInterface> InterfaceClass, const bool bPreserveFunctions = false);

	/* Return if the blueprint supports Interfaces or not */
	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint|Interface", meta = (DisplayName = "Support Interface", Keywords = "ElgSoft Editor Blueprint"))
		static bool BlueprintSupportInterface(UBlueprint* Blueprint);

	/* Return if the blueprint supports Interfaces or not with a branch pins*/
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint|Interface", meta = (DisplayName = "Support Interface Branch", Keywords = "ElgSoft Editor Blueprint", ExpandEnumAsExecs = "Branches"))
		static void BlueprintSupportInterfaceBranch(UBlueprint* Blueprint, EBPEditorOutputBranch& Branches);

#pragma endregion

#pragma region Misc

	/*  */
	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint", meta = (Keywords = "ElgSoft Editor Blueprint"))
		static TSubclassOf<UObject> GetParentClass(UBlueprint* Blueprint);

	/* Return the Native class for a blueprint */
	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint")
		static TSubclassOf<class UObject> GetNativeClass(UBlueprint* Blueprint);

	/* Test if a blueprint is a child of the ChildClass */
	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint")
		static bool IsChildOfClass(UBlueprint* Blueprint, TSubclassOf<class UObject> ChildClass);

	/* Test if a blueprint is a child of the ChildClass */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint", meta=(ExpandEnumAsExecs = "Branches"))
		static void IsChildOfClassBranch(UBlueprint* Blueprint, TSubclassOf<class UObject> ChildClass, EBPEditorOutputBranch& Branches);

	/* Compiles the blueprint asset */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint", meta = (Keywords = "ElgSoft Editor Blueprint"))
		static void CompileBlueprint(UBlueprint* Blueprint);

#pragma endregion

#pragma region Tick

	/* Return the bStartWithTickEnabled state */
	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint")
		static bool IsStartingWithTick(UBlueprint* Blueprint);
	
	/* Return the bStartWithTickEnabled state with branch pins */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint", meta = (ExpandEnumAsExecs = "Branches"))
		static void IsStartingWithTickBranch(UBlueprint* Blueprint, EBPEditorOutputBranch& Branches);

	/* Set the bStartWithTickEnabled state */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint")
		static void SetStartingWithTick(UBlueprint* Blueprint, const bool bEnabled=false);

	/* Return the bCanEverTick state */
	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint")
		static bool CanEverTick(UBlueprint* Blueprint);

	/* Return the bCanEverTick state with branch pins */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint", meta = (ExpandEnumAsExecs = "Branches"))
		static void CanEverTickBranch(UBlueprint* Blueprint, EBPEditorOutputBranch& Branches);

	/* Set the bCanEverTick state */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint")
		static void SetCanEverTick(UBlueprint* Blueprint, const bool bEnabled = false);

#pragma endregion

#pragma region ConstructionScript

	/* Return the bRunConstructionScriptOnDrag state */
	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint")
		static bool IsRunConstructionScriptOnDrag(UBlueprint* Blueprint);

	/* Return the bRunConstructionScriptOnDrag state with branch pins */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint", meta = (ExpandEnumAsExecs = "Branches"))
		static void IsRunConstructionScriptOnDragBranch(UBlueprint* Blueprint, EBPEditorOutputBranch& Branches);

	/* Set the bRunConstructionScriptOnDrag state */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint")
		static void SetRunConstructionScriptOnDrag(UBlueprint* Blueprint, const bool bEnabled=true);

	/* Return if the ConstructionScript node has anything connected */
	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint")
		static bool IsConstructionScriptConnected(UBlueprint* Blueprint);

	/* Return if the ConstructionScript node has anything connected */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint", meta = (ExpandEnumAsExecs = "Branches"))
		static void IsConstructionScriptConnectedBranch(UBlueprint* Blueprint, EBPEditorOutputBranch& Branches);

#pragma endregion

#pragma region Node

	/* Check if the blueprint has a node with NodeName */
	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint")
		static bool HasNode(UBlueprint* Blueprint, const FString NodeName);
	
	/* Check if the blueprint has a node with NodeName */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint", meta = (ExpandEnumAsExecs = "Branches"))
		static void HasNodeBranch(UBlueprint* Blueprint, const FString NodeName, EBPEditorOutputBranch& Branches);

	/* Check if the blueprint has a node with NodeName with a Pin called PinNamed that is connected to anything */
	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint")
		static bool IsNodePinConnected(UBlueprint* Blueprint, const FString NodeName, const FString PinName);

	/* Check if the blueprint has a node with NodeName with a Pin called PinNamed that is connected to anything */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint", meta = (ExpandEnumAsExecs = "Branches"))
		static void IsNodePinConnectedBranch(UBlueprint* Blueprint, const FString NodeName, const FString PinName, EBPEditorOutputBranch& Branches);
	
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint")
		static void GetNodeUsage(UBlueprint* Blueprint, TMap<FString, int32>& NodeUsageMap);

	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint")
		static FS_ElgBlueprintNodeStats GetBlueprintNodeStat(UBlueprint* Blueprint);

	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint")
		static FS_ElgBlueprintsNodeStats GetBlueprintsNodeStat(TArray<UBlueprint*> Blueprints);

	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint")
		static FS_ElgBlueprintsNodeStats GetNodeStatsByPath(const FName Path);

	/* Delete any nodes in the blueprint with the NodeName */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint")
		static void DeleteNodesByName(UBlueprint* Blueprint, const FString NodeName);

	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint")
		static bool HasCompilerError(UBlueprint* Blueprint);

	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint", meta = (ExpandEnumAsExecs = "Branches"))
		static void HasCompilerErrorBranch(UBlueprint* Blueprint, EBPEditorOutputBranch& Branches);

#pragma endregion

#pragma region LocalVariables

	/* Return an array of variable names the blueprint has, VariableName */
	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint")
		static void GetVariableNames(UBlueprint* Blueprint, TArray<FString>& VariableNames);

	/* Return an array of local variable names the blueprint has, VariableName @ FunctionName */
	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint")
		static void GetLocalVariableNames(UBlueprint* Blueprint, TArray<FString>& VariableNames);

	/* Return an array of unused local variable names the blueprint has, VariableName @ FunctionName */
	UFUNCTION(BlueprintPure, Category = "ElgEditor|Blueprint")
		static void GetUnusedLocalVariableNames(UBlueprint* Blueprint, TArray<FString>& VariableNames);

	/* Remove any unused variables in the blueprint */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint")
		static void RemoveUnusedLocalVariables(UBlueprint* Blueprint);

	/* Rename a local variable in FunctionName */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint")
		static void RenameLocalVariable(UBlueprint* Blueprint, const FString FunctionName, const FString OldVariableName, const FString NewVariableName);
	
	/* Remove a local variable in FunctionName */
	UFUNCTION(BlueprintCallable, Category = "ElgEditor|Blueprint")
		static void RemoveLocalVariable(UBlueprint* Blueprint, const FString FunctionName, const FString VariableName);

#pragma endregion

#pragma region Helpers

	static AActor* GetDefaultObjectActor(UBlueprint* Blueprint);

	static UStruct* GetNodeScope(class UK2Node* Node);

	static UStruct* GetFunctionScope(UBlueprint* Blueprint, const FString FunctionName);

	static void GetNodeNameAndType(class UEdGraphNode* Node, FString& NodeName, FString& NodeType);

#pragma endregion

	
};
