#include "PostProcessSkylightComponent.h"

class USkyLightComponent;

USkyLightComponent* UPostProcessSkylightComponent::GetCurrentSkylight() {
    return NULL;
}

UPostProcessSkylightComponent::UPostProcessSkylightComponent() {
    this->SkyLightActorCls = NULL;
    this->SkyLight = NULL;
}

