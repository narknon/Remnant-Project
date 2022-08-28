#include "StaticProceduralMesh.h"
#include "Components/SceneComponent.h"
#include "Components/ArrowComponent.h"
#include "ProceduralMeshComponent.h"
#include "Components/StaticMeshComponent.h"

AStaticProceduralMesh::AStaticProceduralMesh() {
    this->Scene = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
    this->Arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
    this->InitialProceduralMesh = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("InitialProceduralMesh"));
    this->FinalStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FinalStaticMesh"));
    this->bIsUsingStaticMesh = false;
}

