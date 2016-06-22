#include "unity.h"
#include "utils/string.h"
#include "error.h"
#include <string.h>


void setUp(void)
{
}



void tearDown(void)
{
}



void test_str_len(void)
{
    TEST_ASSERT_EQUAL(5, str_len("hello"));
    TEST_ASSERT_EQUAL(0, str_len(""));
    TEST_ASSERT_EQUAL(14, str_len("string testing"));
}



void test_str_cpy(void)
{
    char str[] = "test string";

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, str_cpy(str, sizeof(str), "lazy"));
    TEST_ASSERT_EQUAL_STRING("lazy string", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, str_cpy(str, sizeof(str), "test string"));
    TEST_ASSERT_EQUAL_STRING("test string", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_BUFFER_TOO_SMALL, str_cpy(str, sizeof(str), "long long string"));
    TEST_ASSERT_EQUAL_HEX32(ERROR_BUFFER_TOO_SMALL, str_cpy(str, sizeof(str), "test stringg"));
    TEST_ASSERT_EQUAL_HEX32(ERROR_NULL_POINTER, str_cpy(str, sizeof(str), 0));
    TEST_ASSERT_EQUAL_HEX32(ERROR_NULL_POINTER, str_cpy(0, sizeof(str), str));
}



void test_str_ncpy(void)
{
    char str[] = "test string";

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, str_ncpy(str, sizeof(str), "lazy", 4));
    TEST_ASSERT_EQUAL_STRING("lazy string", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, str_ncpy(str, sizeof(str), "mono", 5));
    TEST_ASSERT_EQUAL_STRING("mono", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, str_ncpy(str, sizeof(str), "mono mono", 9));
    TEST_ASSERT_EQUAL_STRING("mono mono", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_BUFFER_TOO_SMALL, str_ncpy(str, sizeof(str), "mono mono mono", sizeof(str)));
    TEST_ASSERT_EQUAL_HEX32(ERROR_BUFFER_TOO_SMALL, str_ncpy(str, sizeof(str), "mono mono mono", 15));
    TEST_ASSERT_EQUAL_HEX32(ERROR_NULL_POINTER, str_ncpy(str, sizeof(str), 0, sizeof(str)));
    TEST_ASSERT_EQUAL_HEX32(ERROR_NULL_POINTER, str_ncpy(0, sizeof(str), str, sizeof(str)));
}



void test_str_cat(void)
{
    char str[10] = "foo ";
    char str2[10] = "lala ";

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, str_cat(str, sizeof(str), "bar"));
    TEST_ASSERT_EQUAL_STRING("foo bar", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, str_cat(str, sizeof(str), "ba"));
    TEST_ASSERT_EQUAL_STRING("foo barba", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, str_cat(str, sizeof(str), ""));
    TEST_ASSERT_EQUAL_STRING("foo barba", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_BUFFER_TOO_SMALL, str_cat(str, sizeof(str), "a"));
    TEST_ASSERT_EQUAL_HEX32(ERROR_BUFFER_TOO_SMALL, str_cat(str2, sizeof(str), "a;aaa"));
    TEST_ASSERT_EQUAL_HEX32(ERROR_NULL_POINTER, str_cat(0, sizeof(str), "aaaa"));
    TEST_ASSERT_EQUAL_HEX32(ERROR_NULL_POINTER, str_cat(str, sizeof(str), 0));
}




void test_itoa_i(void)
{
    char str[6];

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, itoa_i(5, str, sizeof(str)));
    TEST_ASSERT_EQUAL_STRING("5", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, itoa_i(0, str, sizeof(str)));
    TEST_ASSERT_EQUAL_STRING("0", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, itoa_i(45434, str, sizeof(str)));
    TEST_ASSERT_EQUAL_STRING("45434", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, itoa_i(-4543, str, sizeof(str)));
    TEST_ASSERT_EQUAL_STRING("-4543", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, itoa_i(-5, str, sizeof(str)));
    TEST_ASSERT_EQUAL_STRING("-5", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_BUFFER_TOO_SMALL, itoa_i(343434, str, sizeof(str)));
    TEST_ASSERT_EQUAL_HEX32(ERROR_BUFFER_TOO_SMALL, itoa_i(-43434, str, sizeof(str)));
    TEST_ASSERT_EQUAL_HEX32(ERROR_BUFFER_TOO_SMALL, itoa_i(-343434, str, sizeof(str)));
    TEST_ASSERT_EQUAL_HEX32(ERROR_NULL_POINTER, itoa_i(-343434, 0, sizeof(str)));
}



void test_itoa_u(void)
{
    char str[6];

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, itoa_u(5, str, sizeof(str)));
    TEST_ASSERT_EQUAL_STRING("5", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, itoa_u(0, str, sizeof(str)));
    TEST_ASSERT_EQUAL_STRING("0", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, itoa_u(45434, str, sizeof(str)));
    TEST_ASSERT_EQUAL_STRING("45434", str);

    char str1[11];

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, itoa_u(3000000000, str1, sizeof(str1)));
    TEST_ASSERT_EQUAL_STRING("3000000000", str1);

    TEST_ASSERT_EQUAL_HEX32(ERROR_BUFFER_TOO_SMALL, itoa_u(343434, str, sizeof(str)));
    TEST_ASSERT_EQUAL_HEX32(ERROR_NULL_POINTER, itoa_u(-343434, 0, sizeof(str)));
}



void test_itoa_x8(void)
{
    char str[5];

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, itoa_x8(5, str, sizeof(str)));
    TEST_ASSERT_EQUAL_STRING("0x05", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, itoa_x8(255, str, sizeof(str)));
    TEST_ASSERT_EQUAL_STRING("0xFF", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, itoa_x8(0xAB, str, sizeof(str)));
    TEST_ASSERT_EQUAL_STRING("0xAB", str);

    char str1[4];

    TEST_ASSERT_EQUAL_HEX32(ERROR_BUFFER_TOO_SMALL, itoa_x8(5, str1, sizeof(str1)));
    TEST_ASSERT_EQUAL_HEX32(ERROR_NULL_POINTER, itoa_x8(5, 0, sizeof(str1)));
}



void test_itoa_x16(void)
{
    char str[7];

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, itoa_x16(5, str, sizeof(str)));
    TEST_ASSERT_EQUAL_STRING("0x0005", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, itoa_x16(0xFFFF, str, sizeof(str)));
    TEST_ASSERT_EQUAL_STRING("0xFFFF", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, itoa_x16(0xABCD, str, sizeof(str)));
    TEST_ASSERT_EQUAL_STRING("0xABCD", str);

    char str1[6];

    TEST_ASSERT_EQUAL_HEX32(ERROR_BUFFER_TOO_SMALL, itoa_x16(5, str1, sizeof(str1)));
    TEST_ASSERT_EQUAL_HEX32(ERROR_NULL_POINTER, itoa_x16(5, 0, sizeof(str1)));
}



void test_itoa_x32(void)
{
    char str[11];

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, itoa_x32(5, str, sizeof(str)));
    TEST_ASSERT_EQUAL_STRING("0x00000005", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, itoa_x32(0xFFFFFFFF, str, sizeof(str)));
    TEST_ASSERT_EQUAL_STRING("0xFFFFFFFF", str);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, itoa_x32(0xABCDEFAB, str, sizeof(str)));
    TEST_ASSERT_EQUAL_STRING("0xABCDEFAB", str);

    char str1[10];

    TEST_ASSERT_EQUAL_HEX32(ERROR_BUFFER_TOO_SMALL, itoa_x32(5, str1, sizeof(str1)));
    TEST_ASSERT_EQUAL_HEX32(ERROR_NULL_POINTER, itoa_x32(5, 0, sizeof(str1)));
}
