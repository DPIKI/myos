#ifndef _ERROR_H_
#define _ERROR_H_

#include <stddef.h>

typedef size_t error_t;

#define ERROR_SUCCESS             (0x00000000)
#define ERROR_NULL_POINTER        (0x80000000)
#define ERROR_BUFFER_TOO_SMALL    (0x80000001)
#define ERROR_INDEX_OUT_OF_RANGE  (0x80000002)

#endif
