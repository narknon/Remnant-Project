#include "GlobalObjectPool.h"

class UGlobalObjectPool;
class UWorld;

UGlobalObjectPool* UGlobalObjectPool::GetInstance(UWorld* World) {
    return NULL;
}

void UGlobalObjectPool::Empty() {
}

UGlobalObjectPool::UGlobalObjectPool() {
}

