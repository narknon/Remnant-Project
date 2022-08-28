#pragma once
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "RootVariableContext.generated.h"

UCLASS(Blueprintable, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class GUNFIRERUNTIME_API URootVariableContext : public UActorComponent {
    GENERATED_BODY()
public:
    URootVariableContext();
};

