#ifndef _MEM_H_
#define _MEM_H_

#include "error.h"
#include <stdint.h>

/**
 * Fills given memory block with \c val.
 *
 * \param mem [in,out] Pointer to memory to fill.
 * \param size [in] Size in bytes of \c mem block.
 * \param val [in] Value to fill \c mem with.
 * \return 
 *      Possible return values: \n
 *      \c ERROR_SUCCESS \n
 *      \c ERROR_NULL_POINTER \n
 */
error_t memset(void* mem, size_t size, uint8_t val);

#endif
