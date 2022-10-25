#include "EventTreeNode.h"

class APlayerController;
class UEventTreeComponent;

bool UEventTreeNode::Validate_Implementation(UEventTreeComponent* Component) {
    return false;
}

void UEventTreeNode::Loop_Implementation(UEventTreeComponent* Component) {
}

void UEventTreeNode::Join_Implementation(UEventTreeComponent* Component, APlayerController* JoiningController) {
}

bool UEventTreeNode::IsComplete_Implementation(UEventTreeComponent* Component) {
    return false;
}

void UEventTreeNode::End_Implementation(UEventTreeComponent* Component) {
}

void UEventTreeNode::Begin_Implementation(UEventTreeComponent* Component) {
}

UEventTreeNode::UEventTreeNode() {
}

