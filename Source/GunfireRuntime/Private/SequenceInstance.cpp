#include "SequenceInstance.h"

void USequenceInstance::OnFinished() {
}

void USequenceInstance::OnEventTreeTrackTriggerNotified(FName TriggerName) {
}

USequenceInstance::USequenceInstance() {
    this->CurrentSequence = NULL;
    this->CurrentSequencePlayer = NULL;
    this->CurrentSequenceActor = NULL;
    this->CurrentSequenceInstigator = NULL;
    this->WorldContextObject = NULL;
}

