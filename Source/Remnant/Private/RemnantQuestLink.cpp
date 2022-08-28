#include "RemnantQuestLink.h"

class UQuestComponent;

void URemnantQuestLink::OnLinkDeactivated(UQuestComponent* Component) {
}

void URemnantQuestLink::OnLinkActivated(UQuestComponent* Component) {
}

URemnantQuestLink::URemnantQuestLink() {
    this->AutoLink = false;
    this->AutoLinkQuestID = -1;
}

