#include "EventTreeNode_Dialog.h"
#include "Dialog_Emote.h"
#include "Dialog_Speaker.h"

class UEventTreeComponent;

void UEventTreeNode_Dialog::OnFinishedWaiting(UEventTreeComponent* Component) {
}

void UEventTreeNode_Dialog::OnDialogComplete(UEventTreeComponent* Component) {
}

void UEventTreeNode_Dialog::Complete(UEventTreeComponent* Component) {
}

UEventTreeNode_Dialog::UEventTreeNode_Dialog() {
    this->Speaker = UDialog_Speaker::StaticClass();
    this->Emote = UDialog_Emote::StaticClass();
    this->AutoComplete = false;
    this->CompleteAfterDialog = false;
    this->WaitTimeAfterComplete = 0.25f;
    this->VocalRange = NULL;
    this->IsDefaultSpeaker = true;
    this->IsDefaultVocalRange = true;
}

