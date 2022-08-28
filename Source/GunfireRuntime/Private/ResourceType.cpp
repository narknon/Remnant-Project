#include "ResourceType.h"

FResourceType::FResourceType() {
    this->Distribution = EResourceDistribution::Quantity;
    this->Min = 0.00f;
    this->Max = 0.00f;
    this->SpawnTable = NULL;
}

