#include "utils/bitmap.h"
#include "utils/utils.h"
#include <stdio.h>


error_t bitmap_init(Bitmap* bitmap, uint8_t* buffer, size_t bitmap_length)
{
    if (bitmap == 0 || buffer == 0) {
        return ERROR_NULL_POINTER;
    }

    bitmap->data = buffer;
    bitmap->length = bitmap_length;
    bitmap->n_bytes = (bitmap_length & 0x7)
        ? (bitmap_length >> 3) + 1
        : bitmap_length >> 3;

    for (int i = 0; i < bitmap->n_bytes; i++) {
        bitmap->data[i] = 0;
    }

    return ERROR_SUCCESS;
}



error_t bitmap_set_bits(Bitmap* bitmap, size_t index, size_t length)
{
    if (bitmap == 0) {
        return ERROR_NULL_POINTER;
    }

    if (index >= bitmap->length) {
        return ERROR_INDEX_OUT_OF_RANGE;
    }

    if (length == 0) {
        return ERROR_SUCCESS;
    }

    length = MIN(length, bitmap->length - index);
    uint8_t* data = bitmap->data;
    size_t start_byte = index >> 3;
    size_t start_bit = index & 0x7;
    size_t bits_in_first_byte = MIN(8 - start_bit, length);
    size_t full_bytes = (length - bits_in_first_byte) >> 3;
    size_t bits_in_last_byte = length - bits_in_first_byte - (full_bytes << 3);

    uint8_t first_byte_mask = ~(0xFF << bits_in_first_byte);
    first_byte_mask <<= start_bit;
    data[start_byte] |= first_byte_mask;
    
    for (int i = start_byte + 1; i < start_byte + full_bytes + 1; i++) {
        data[i] = 0xFF;
    }

    uint8_t last_byte_mask = ~(0xFF << bits_in_last_byte);
    data[start_byte + full_bytes + 1] |= last_byte_mask;

    return ERROR_SUCCESS;
}



error_t bitmap_clear_bits(Bitmap* bitmap, size_t index, size_t length)
{
    if (bitmap == 0) {
        return ERROR_NULL_POINTER;
    }

    if (index >= bitmap->length) {
        return ERROR_INDEX_OUT_OF_RANGE;
    }

    if (length == 0) {
        return ERROR_SUCCESS;
    }

    length = MIN(length, bitmap->length - index);
    uint8_t* data = bitmap->data;
    size_t start_byte = index >> 3;
    size_t start_bit = index & 0x7;
    size_t bits_in_first_byte = MIN(8 - start_bit, length);
    size_t full_bytes = (length - bits_in_first_byte) >> 3;
    size_t bits_in_last_byte = length - bits_in_first_byte - (full_bytes << 3);

    uint8_t first_byte_mask = ~(0xFF << bits_in_first_byte);
    first_byte_mask <<= start_bit;
    first_byte_mask = ~first_byte_mask;
    data[start_byte] &= first_byte_mask;
    
    for (int i = start_byte + 1; i < start_byte + full_bytes + 1; i++) {
        data[i] = 0x00;
    }

    uint8_t last_byte_mask = 0xFF << bits_in_last_byte;
    data[start_byte + full_bytes + 1] &= last_byte_mask;

    return ERROR_SUCCESS;
}



error_t bitmap_set_bit(Bitmap* bitmap, size_t index)
{
    if (bitmap == 0) {
        return ERROR_NULL_POINTER;
    }

    if (index >= bitmap->length) {
        return ERROR_INDEX_OUT_OF_RANGE;
    }

    bitmap->data[index >> 3] |= (1 << (index & 0x7));
    
    return ERROR_SUCCESS;
}



error_t bitmap_clear_bit(Bitmap* bitmap, size_t index)
{
    if (bitmap == 0) {
        return ERROR_NULL_POINTER;
    }

    if (index >= bitmap->length) {
        return ERROR_INDEX_OUT_OF_RANGE;
    }

    bitmap->data[index >> 3] &= ~(1 << (index & 0x7));
    
    return ERROR_SUCCESS;
}



int bitmap_find_one(Bitmap* bitmap, size_t index)
{
    if (bitmap == 0) {
        return -1;
    }

    if (index >= bitmap->length) {
        return -1;
    }

    size_t start_byte = index >> 3;
    size_t start_bit = index & 0x7;
    size_t i;
    for (i = start_byte; i < bitmap->n_bytes - 1; i++) {
        if (bitmap->data[i] != 0) {
            uint8_t c = (i == start_byte) ? 1 << start_bit : 1;
            size_t  j = (i == start_byte) ?      start_bit : 0;
            while ((bitmap->data[i] & c) == 0) {
                c <<= 1;
                j++;
            }

            return (i << 3) | j;
        }
    }

    //i == bitmap->n_bytes - 1
    size_t bits_in_last_byte = bitmap->length - (i << 3);
    uint8_t last_byte_mask = ~(0xFF << bits_in_last_byte);
    uint8_t last_byte = bitmap->data[i];

    if ((last_byte & last_byte_mask) != 0) {
        uint8_t c = (i == start_byte) ? 1 << start_bit : 1;
        size_t  j = (i == start_byte) ?      start_bit : 0;
        while ((bitmap->data[i] & c) == 0) {
            c <<= 1;
            j++;
        }

        return (i << 3) | j;
    }

    return -1;
}



int bitmap_find_null(Bitmap* bitmap, size_t index)
{
    if (bitmap == 0) {
        return -1;
    }

    if (index >= bitmap->length) {
        return -1;
    }

    size_t start_byte = index >> 3;
    size_t start_bit = index & 0x7;
    size_t i;
    for (i = start_byte; i < bitmap->n_bytes - 1; i++) {
        if (bitmap->data[i] != 0xFF) {
            uint8_t c = (i == start_byte) ? 1 << start_bit : 1;
            size_t  j = (i == start_byte) ?      start_bit : 0;
            while ((bitmap->data[i] & c) != 0) {
                c <<= 1;
                j++;
            }

            return (i << 3) | j;
        }
    }

    //i == bitmap->n_bytes - 1
    size_t bits_in_last_byte = bitmap->length - (i << 3);
    uint8_t last_byte_mask = ~(0xFF << bits_in_last_byte);
    uint8_t last_byte = bitmap->data[i];

    if ((last_byte & last_byte_mask) != last_byte_mask) {
        uint8_t c = (i == start_byte) ? 1 << start_bit : 1;
        size_t  j = (i == start_byte) ?      start_bit : 0;
        while ((bitmap->data[i] & c) != 0) {
            c <<= 1;
            j++;
        }

        return (i << 3) | j;
    }

    return -1;
}
