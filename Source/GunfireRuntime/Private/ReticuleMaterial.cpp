#include "ReticuleMaterial.h"

UReticuleMaterial::UReticuleMaterial() {
    this->Material = NULL;
    this->BaseMaterialSize = 10.00f;
    this->ColorParameter = TEXT("Color");
    this->LastReticuleMaterial = NULL;
}

