#include "SingleObjectPool.h"

USingleObjectPool::USingleObjectPool() {
    this->MaxSize = 128;
    this->DefaultTimeout = 3.00f;
    this->GarbageCollectTimeout = 180.00f;
    this->ItemClass = NULL;
}

