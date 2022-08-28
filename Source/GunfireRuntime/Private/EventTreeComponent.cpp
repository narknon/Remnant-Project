#include "EventTreeComponent.h"

class UObject;
class UEventTreeNode;
class UEventTree;

void UEventTreeComponent::Stop() {
}

void UEventTreeComponent::StartTree() {
}

void UEventTreeComponent::SetVariableAsObject(FName Name, UObject* Value) {
}

void UEventTreeComponent::SetVariableAsBool(FName Name, bool Value) {
}


void UEventTreeComponent::SetStage(const FEventTreeStage& Stage) {
}

void UEventTreeComponent::PushStage(const FEventTreeStage& Stage) {
}

void UEventTreeComponent::PopStage() {
}

UEventTreeNode* UEventTreeComponent::PeekNextNode() {
    return NULL;
}

bool UEventTreeComponent::IsRunning() const {
    return false;
}

bool UEventTreeComponent::HasPendingEvents() const {
    return false;
}

UObject* UEventTreeComponent::GetVariableObject(FName Name) {
    return NULL;
}

UEventTreeNode* UEventTreeComponent::GetCurrentNode() {
    return NULL;
}

bool UEventTreeComponent::ExecuteTriggerFromEventTree(UEventTree* EventTree, const FName& TriggerName) {
    return false;
}

void UEventTreeComponent::ExecuteSubroutine(FName Name) {
}

void UEventTreeComponent::Clear(bool ForceComplete) {
}

void UEventTreeComponent::BeginEventTree(UEventTree* EventTree, bool DeferredStart) {
}

UEventTreeComponent::UEventTreeComponent() {
}

