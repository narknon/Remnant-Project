#include "StatsComponent.h"
#include "Templates/SubclassOf.h"

class UComputedStats;

void UStatsComponent::SetComputedStats(TSubclassOf<UComputedStats> NewComputedStats) {
}

void UStatsComponent::ScaleStat(const FName& Name, float Scalar, bool AutoInitValue) {
}

float UStatsComponent::ModifyStat(const FName& Name, float Value) {
    return 0.0f;
}

void UStatsComponent::Invalidate() {
}

bool UStatsComponent::HasStat(const FName& Name) {
    return false;
}

int32 UStatsComponent::GetStatAsInt(FName Name, bool ApplyMod) {
    return 0;
}

bool UStatsComponent::GetStatAsBool(FName Name, bool ApplyMod) {
    return false;
}

float UStatsComponent::GetStat(FName Name, bool ApplyMod) {
    return 0.0f;
}

TSubclassOf<UComputedStats> UStatsComponent::GetComputedStats() {
    return NULL;
}

void UStatsComponent::ApplyStats(const FDataTableRowHandle& DataTable, int32 Level) {
}

void UStatsComponent::ApplyStatModsTo(float& Value, FName Stat) {
}

UStatsComponent::UStatsComponent() {
}

