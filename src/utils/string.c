#include "utils/string.h"


error_t str_len(char* str)
{
    int i = 0;

    while (*str++)
        i++;

    return i;
}



error_t str_cpy(char* dst, size_t max_len, char* src)
{
    if (dst == 0 || src == 0)
        return ERROR_NULL_POINTER;

    if (str_len(src) + 1 > max_len)
        return ERROR_BUFFER_TOO_SMALL;

    for (size_t i = str_len(dst); i < max_len; i++) {
        dst[i] = '\0';
    }

    while (*src) {
        *dst = *src;
        dst++;
        src++;
    }

    return ERROR_SUCCESS;
}



error_t str_ncpy(char* dst, size_t max_len, char* src, size_t n_chars)
{
    if (dst == 0 || src == 0) {
        return ERROR_NULL_POINTER;
    }

    if (n_chars > max_len) {
        return ERROR_BUFFER_TOO_SMALL;
    }

    for (size_t i = str_len(dst); i < max_len; i++) {
        dst[i] = '\0';
    }

    for (size_t i = 0; i < n_chars; i++) {
        dst[i] = src[i];
    }

    if (dst[max_len - 1] != '\0') {
        dst[max_len - 1]  = '\0';
        return ERROR_BUFFER_TOO_SMALL;
    }

    return ERROR_SUCCESS;
}



error_t str_cat(char* dst, size_t max_len, char* src)
{
    if (dst == 0 || src == 0) {
        return ERROR_NULL_POINTER;
    }

    size_t dst_len = str_len(dst);
    size_t src_len = str_len(src);
    if (dst_len + src_len + 1 > max_len) {
        return ERROR_BUFFER_TOO_SMALL;
    }

    for (size_t i = dst_len; i < max_len; i++) {
        dst[i] = '\0';
    }

    char* dst_ptr = dst + dst_len;
    char* src_ptr = src;
    while (*src_ptr) {
        *dst_ptr = *src_ptr;
        dst_ptr++;
        src_ptr++;
    }

    return ERROR_SUCCESS;
}



error_t itoa_i(int x, char* dst, size_t max_len)
{
    if (dst == 0) {
        return ERROR_NULL_POINTER;
    }

    if (max_len < 2) {
        return ERROR_BUFFER_TOO_SMALL;
    }

    if (x == 0x80000000) {
        dst[0] = '-';
        return itoa_u(0x80000000, dst + 1, max_len - 1);
    }
    else if (x < 0) {
        dst[0] = '-';
        return itoa_u((unsigned int)-x, dst + 1, max_len - 1); 
    }
    else {
        return itoa_u((unsigned int)x, dst, max_len);
    }
}



error_t itoa_u(unsigned int x, char* dst, size_t max_len)
{
    if (dst == 0) {
        return ERROR_NULL_POINTER;
    }

    if (max_len < 2) {
        return ERROR_BUFFER_TOO_SMALL;
    }

    if (x == 0) {
        dst[0] = '0';
        dst[1] = '\0';
        return ERROR_SUCCESS;
    }

    size_t i = 0;
    while (x != 0 && i < max_len) {
        dst[i] = '0' + x % 10;
        x /= 10;
        i++;
    }

    if (i >= max_len) {
        return ERROR_BUFFER_TOO_SMALL;
    }

    dst[i] = '\0';

    if (i > 1) {
        i--;
        size_t j = 0;
        while (j < i) {
            char c = dst[i];
            dst[i] = dst[j];
            dst[j] = c;
            i--;
            j++;
        }
    }

    return ERROR_SUCCESS;
}



error_t itoa_x8(uint8_t x, char* dst, size_t max_len)
{
    if (dst == 0) {
        return ERROR_NULL_POINTER;
    }

    if (max_len < 5) {
        return ERROR_BUFFER_TOO_SMALL;
    }

    dst[0] = '0';
    dst[1] = 'x';
    dst[4] = '\0';

    for (int i = 2; i < 4; i++) {
        int digit = (x >> (4 - ((i - 2) << 2))) & 0xF;
        if (digit < 10) {
            dst[i] = '0' + digit;
        }
        else {
            dst[i] = 'A' + (digit - 10);
        }
    }

    return ERROR_SUCCESS;
}



error_t itoa_x16(uint16_t x, char* dst, size_t max_len)
{
    if (dst == 0) {
        return ERROR_NULL_POINTER;
    }

    if (max_len < 7) {
        return ERROR_BUFFER_TOO_SMALL;
    }

    dst[0] = '0';
    dst[1] = 'x';
    dst[6] = '\0';

    for (int i = 2; i < 6; i++) {
        int digit = (x >> (12 - ((i - 2) << 2))) & 0xF;
        if (digit < 10) {
            dst[i] = '0' + digit;
        }
        else {
            dst[i] = 'A' + (digit - 10);
        }
    }

    return ERROR_SUCCESS;
}



error_t itoa_x32(uint32_t x, char* dst, size_t max_len)
{
    if (dst == 0) {
        return ERROR_NULL_POINTER;
    }

    if (max_len < 11) {
        return ERROR_BUFFER_TOO_SMALL;
    }

    dst[0] = '0';
    dst[1] = 'x';
    dst[10] = '\0';

    for (int i = 2; i < 10; i++) {
        int digit = (x >> (28 - ((i - 2) << 2))) & 0xF;
        if (digit < 10) {
            dst[i] = '0' + digit;
        }
        else {
            dst[i] = 'A' + (digit - 10);
        }
    }

    return ERROR_SUCCESS;
}
