/**
 * \file bitmap.h
 * \brief Contains implementation of simple bitmap.
 */
#ifndef _BITMAP_H_
#define _BITMAP_H_

#include <stdint.h>
#include "error.h"

/**
 * Presents the bitmap.
 */
typedef struct {
    uint8_t* data;     ///< Pointer to memory where to place Bitmap's data.
    size_t n_bytes; ///< Size in bytes of data buffer.
    size_t length;  ///< Length in bits of the Bitmap.
} Bitmap;


/**
 * \brief Initializes bitmap struct.
 *
 * Does not take ownership so the caller
 * must free buffer memory if needed. Fills buffer with zeros.
 *
 * \param bitmap [out]          Pointer to Bitmap struct to be initialized.
 * \param buffer [in]           Pointer to the memory where bitmap is placed.
 * \param bitmap_length [in]    Count of bits in bitmap.
 * \return
 *          Possible return codes: \n
 *          \c ERROR_SUCCESS \n
 *          \c ERROR_NULL_POINTER \n
 */
error_t bitmap_init(Bitmap* bitmap, uint8_t* buffer, size_t bitmap_length);



/**
 * \breif Sets specified series of bits.
 *
 * If \c index + \c length more than the length of Bitmap then function
 * set all bits from \c index to the end of Bitmap.
 *
 * \param bitmap [in,out]   Pointer to Bitmap struct to work with.
 * \param index [in]        Index of the first bit of the series.
 * \param length [in]       Count of bits to be set.
 * \return
 *          Possible return codes: \n
 *          \c ERROR_SUCCESS \n
 *          \c ERROR_NULL_POINTER \n
 *          \c ERROR_INDEX_OUT_OF_RANGE \n
 */
error_t bitmap_set_bits(Bitmap* bitmap, size_t index, size_t length);



/**
 * \breif Sets specified bit.
 *
 * \param bitmap [in,out]   Pointer to Bitmap struct to work with.
 * \param index [in]        Index of the bit to set.
 * \return
 *          Possible return codes: \n
 *          \c ERROR_SUCCESS \n
 *          \c ERROR_NULL_POINTER \n
 *          \c ERROR_INDEX_OUT_OF_RANGE \n
 */
error_t bitmap_set_bit(Bitmap* bitmap, size_t index);



/**
 * \breif Clears specified series of bits.
 *
 * If \c index + \c length more than the length of Bitmap then function
 * clears all bits from \c index to the end of Bitmap.
 *
 * \param bitmap [in,out]   Pointer to Bitmap struct to work with.
 * \param index [in]        Index of the first bit of the series.
 * \param length [in]       Count of bits to be cleared.
 * \return
 *          Possible return codes: \n
 *          \c ERROR_SUCCESS \n
 *          \c ERROR_NULL_POINTER \n
 *          \c ERROR_INDEX_OUT_OF_RANGE \n
 */
error_t bitmap_clear_bits(Bitmap* bitmap, size_t index, size_t length);



/**
 * \breif Clears specified bit.
 *
 * \param bitmap [in,out]   Pointer to Bitmap struct to work with.
 * \param index [in]        Index of the bit to clear.
 * \return
 *          Possible return codes: \n
 *          \c ERROR_SUCCESS \n
 *          \c ERROR_NULL_POINTER \n
 *          \c ERROR_INDEX_OUT_OF_RANGE \n
 */
error_t bitmap_clear_bit(Bitmap* bitmap, size_t index);



/**
 * \brief Finds the series of sequential zeros.
 *
 * \param bitmap [in]       Pointer to Bitmap sturct to work with.
 * \param index [in]        Index where to start search from.
 * \param length [in]       Length of the series to search.
 * \return Index of first bit in the series or -1 if it fails.
 */
int bitmap_find_null_series(Bitmap* bitmap, size_t index, size_t length);



/**
 * \brief Finds the series of sequential ones.
 *
 * \param bitmap [in]       Pointer to Bitmap sturct to work with.
 * \param index [in]        Index where to start search from.
 * \param length [in]       Length of the series to search.
 * \return Index of first bit in the series or -1 if it fails.
 */
int bitmap_find_one_series(Bitmap* bitmap, size_t index, size_t length);



/**
 * \brief Finds first null starting from \c index
 *
 * \param bitmap [in]       Pointer to Bitmap struct to work with.
 * \param index [in]        Index where to start search from.
 * \return Index of first null bit or -1 if it fails.
 */
int bitmap_find_null(Bitmap* bitmap, size_t index);



/**
 * \brief Finds first one starting from \c index
 *
 * \param bitmap [in]       Pointer to Bitmap struct to work with.
 * \param index [in]        Index where to start search from.
 * \return Index of first one bit or -1 if it fails.
 */
int bitmap_find_one(Bitmap* bitmap, size_t index);

#endif
