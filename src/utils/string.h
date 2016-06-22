/**
 * \file string.h
 * \brief Contains definitions for useful functions to work with strings.
 */

#ifndef _STRING_H_
#define _STRING_H_

#include <stddef.h>
#include <stdint.h>
#include "error.h"

/**
 * Computes the length of the string
 *
 * \param   [in] - Str zero terminated string
 * \return  lenght of str without null character and \c ERROR_NULL_POINTER if str = 0
 */
error_t str_len(char* str);



/**
 * Copies src string to dst string
 *
 * \param   [out] dst - Pointer to destination buffer.
 * \param   [in] max_len - Size of dst buffer.
 * \param   [in] src - Pointer to source buffer. Must be zero terminated.
 * \return  
 *          If the function succeed dst always contains null terminated string. \n
 *          \n
 *          Possible return codes: \n
 *          \c ERROR_SUCCESS \n
 *          \c ERROR_NULL_POINTER \n
 *          \c ERROR_BUFFER_TOO_SMALL \n
 */
error_t str_cpy(char* dst, size_t max_len, char* src);



/**
 * Copies n characters from src to dst.
 *
 * \param   [out] dst - Pointer to destination buffer.
 * \param   [in] max_len - Size of dst buffer.
 * \param   [in] src - Pointer to source buffer. Must be zero terminated.
 * \param   [in] n_chars - Characters count to be copied.
 *          If this parameter more than size of src than the function copies src untill null character.
 *          If this parameter is equal to max_len and last src character is not null than the function fails
 * \return 
 *          If the function succeed dst always contains null terminated string. \n
 *          \n
 *          Possible return codes: \n
 *          \c ERROR_SUCCESS \n
 *          \c ERROR_NULL_POINTER \n
 *          \c ERROR_BUFFER_TOO_SMALL \n
 */
error_t str_ncpy(char* dst, size_t max_len, char* src, size_t n_chars);



/**
 * Appends src to dst.
 *
 * \param   [in,out] dst - Destination string. Must be zero terminated.
 * \param   [in] max_len - Less or equal the dst buffer size.
 * \param   [in] src - Source string. Must be zero terminated.
 * \return
 *          If the function succeed dst always contains null terminated string. \n
 *          \n
 *          Possible return codes: \n
 *          \c ERROR_SUCCESS \n
 *          \c ERROR_NULL_POINTER \n
 *          \c ERROR_BUFFER_TOO_SMALL \n
 */
error_t str_cat(char* dst, size_t max_len, char* src);



/**
 * Converts signed integer to zero terminated ascii string.
 *
 * \param   [in] x Integer to convert.
 * \param   [out] dst Pointer to the result buffer.
 * \param   [in] max_len Size of result buffer.
 * \return
 *          If the function succeed dst always contains null terminated string. \n
 *          \n
 *          Possible return codes: \n
 *          \c ERROR_SUCCESS \n
 *          \c ERROR_NULL_POINTER \n
 *          \c ERROR_BUFFER_TOO_SMALL \n
 */
error_t itoa_i(int x, char* dst, size_t max_len);



/**
 * Converts unsigned integer to zero terminated ascii string.
 *
 * \param   [in] x Integer to convert.
 * \param   [out] dst Pointer to the result buffer.
 * \param   [in] max_len Size of result buffer.
 * \return
 *          If the function succeed dst always contains null terminated string. \n
 *          \n
 *          Possible return codes: \n
 *          \c ERROR_SUCCESS \n
 *          \c ERROR_NULL_POINTER \n
 *          \c ERROR_BUFFER_TOO_SMALL \n
 */
error_t itoa_u(unsigned int x, char* dst, size_t max_len);



/**
 * Converts unsigned integer to zero terminated ascii string in hex format 0x??.
 *
 * \param   [in] x Integer to convert.
 * \param   [out] dst Pointer to the result buffer.
 * \param   [in] max_len Size of result buffer.
 * \return
 *          If the function succeed dst always contains null terminated string. \n
 *          \n
 *          Possible return codes: \n
 *          \c ERROR_SUCCESS \n
 *          \c ERROR_NULL_POINTER \n
 *          \c ERROR_BUFFER_TOO_SMALL \n
 */
error_t itoa_x8(uint8_t x, char* dst, size_t max_len);



/**
 * Same as previous but the output format is 0x????
 */
error_t itoa_x16(uint16_t x, char* dst, size_t max_len);



/**
 * Same as previous but the output format is 0x????????
 */
error_t itoa_x32(uint32_t x, char* dst, size_t max_len);

#endif
