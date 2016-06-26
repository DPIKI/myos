#include "utils/mem.h"


error_t memset(void* mem, size_t size, uint8_t val)
{
    if (mem == 0)
        return ERROR_NULL_POINTER;

    for (size_t i = 0; i < size; i++) {
        ((uint8_t*)mem)[i] = val;
    }

    return ERROR_SUCCESS;
}
