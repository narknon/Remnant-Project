#include "QuestComponent.h"

void UQuestComponent::OnResetQuest_Implementation() {
}

void UQuestComponent::OnQuestComplete_Implementation(EQuestResult Result) {
}

void UQuestComponent::OnPostInitializeQuest_Implementation() {
}

void UQuestComponent::OnPostCreateQuest_Implementation() {
}

void UQuestComponent::OnObjectiveComplete_Implementation(FName NameID) {
}

void UQuestComponent::OnObjectiveActivate_Implementation(FName NameID) {
}

void UQuestComponent::OnInitializeQuest_Implementation() {
}

void UQuestComponent::OnDeinitializeQuest_Implementation() {
}

void UQuestComponent::OnCreateQuest_Implementation(const FRandomStream& RandomStream) {
}

bool UQuestComponent::IsQuestActive() {
    return false;
}

bool UQuestComponent::HasErrors() {
    return false;
}

void UQuestComponent::GetDebugProperties(TArray<FQuestDebugProperty>& Properties) {
}

FString UQuestComponent::GetDebugLabel() {
    return TEXT("");
}

void UQuestComponent::DeactivateQuest() {
}

void UQuestComponent::ActivateQuest() {
}

UQuestComponent::UQuestComponent() {
    this->Seed = 0;
    this->bQuestAutoActivate = true;
}

