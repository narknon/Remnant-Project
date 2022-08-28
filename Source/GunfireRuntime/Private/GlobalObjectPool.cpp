#include "GlobalObjectPool.h"

class UWorld;
class UGlobalObjectPool;

UGlobalObjectPool* UGlobalObjectPool::GetInstance(UWorld* World) {
    return NULL;
}

void UGlobalObjectPool::Empty() {
}

UGlobalObjectPool::UGlobalObjectPool() {
}

