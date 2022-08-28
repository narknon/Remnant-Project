#include "NavVolume.h"

ANavVolume::ANavVolume() {
    this->DrawType = DRAWTYPE_Blocked;
    this->bDrawVoxels = false;
    this->bDrawAreas = true;
    this->bIncludeVoxelAreas = false;
    this->bDrawSingleLayer = false;
    this->DrawLayerIndex = 0;
    this->bDrawSingleNode = false;
    this->DrawNodeIndex = 0;
    this->bDrawNodeNeighbors = false;
    this->DrawOriginOffset = 100.00f;
    this->DrawDistance = 500.00f;
    this->VoxelSize = 64.00f;
    this->TilePoolSize = 4096;
    this->bFixedTilePoolSize = false;
    this->TileLayerIndex = 3;
    this->AgentRadius = 0.00f;
    this->AgentHeight = 0.00f;
    this->AgentRadiusPaddingScalar = 0.50f;
    this->AgentHeightPaddingScalar = 0.50f;
    this->MaxTileGenerationJobs = 1024;
    this->MaxTilesPerGenerationJob = 1;
    this->bDoAsyncGeometryGathering = false;
    this->DefaultMaxSearchNodes = 1024;
    this->DefaultHeuristicScale = 100.00f;
    this->DefaultNodeSizeCompensation = 1.00f;
    this->DefaultBlockedNodeCompensation = 0.10f;
}

