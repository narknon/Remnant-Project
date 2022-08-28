#include "EventTreeNode_LevelSequence.h"

void UEventTreeNode_LevelSequence::OnSequenceTriggerForEventTree(FName TriggerName) {
}

void UEventTreeNode_LevelSequence::OnSequenceFinishedCallback() {
}

UEventTreeNode_LevelSequence::UEventTreeNode_LevelSequence() {
    this->HideOtherPlayers = true;
    this->ResetNonMVPs = true;
    this->ResetCameraOnComplete = false;
    this->ShowSkipCinematic = true;
    this->DefaultToPlayerCameraOnFinish = false;
    this->StoredComponent = NULL;
}

