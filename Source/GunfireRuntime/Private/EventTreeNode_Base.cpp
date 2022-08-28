#include "EventTreeNode_Base.h"

FString UEventTreeNode_Base::GetEditorLabel_Implementation() const {
    return TEXT("");
}

UEventTreeNode_Base::UEventTreeNode_Base() {
    this->Enabled = true;
    this->Seed = 22369;
}

