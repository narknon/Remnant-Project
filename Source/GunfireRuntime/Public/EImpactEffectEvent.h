#pragma once
#include "CoreMinimal.h"
#include "EImpactEffectEvent.generated.h"

UENUM(BlueprintType)
enum EImpactEffectEvent {
    Animation_Blocking,
    Animation_Water,
    Animation_Editor,
    Melee_Environment,
    Melee_Impact,
    Ragdoll,
    Combat_Block,
    Combat_Trace,
    Combat_Projectile,
    Combat_AOE,
};

