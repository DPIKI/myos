#include "unity.h"
#include "utils/bitmap.h"
#include "error.h"


void setUp(void)
{
}



void tearDown(void)
{
}



void test_init(void)
{
    uint8_t buf[10] = { 0xFF };
    buf[9] = 0xBA;
    Bitmap bitmap;

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, bitmap_init(&bitmap, buf, 71));
    TEST_ASSERT_EQUAL_HEX32(buf, bitmap.data);
    TEST_ASSERT_EQUAL(71, bitmap.length);
    TEST_ASSERT_EQUAL(9, bitmap.n_bytes);
    for (int i = 0; i < sizeof(buf) - 2; i++) {
        TEST_ASSERT_EQUAL(0, buf[i]);
    }
    TEST_ASSERT_EQUAL_HEX8(0xBA, buf[sizeof(buf) - 1]);
    TEST_ASSERT_EQUAL_HEX8(0x00, (buf[8] & 0x7F));

    TEST_ASSERT_EQUAL_HEX32(ERROR_NULL_POINTER, bitmap_init(0, buf, 77));
    TEST_ASSERT_EQUAL_HEX32(ERROR_NULL_POINTER, bitmap_init(&bitmap, 0, 77));
}



void test_set_bits(void)
{
    uint8_t buf[10] = { 0xFF };
    buf[9] = 0xBA;
    Bitmap bitmap;

    bitmap_init(&bitmap, buf, 71);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, bitmap_set_bits(&bitmap, 0, 0));
    for (int i = 0; i < sizeof(buf) - 2; i++) {
        TEST_ASSERT_EQUAL(0, buf[i]);
    }
    TEST_ASSERT_EQUAL(0x00, (buf[8] & 0x7F));

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, bitmap_set_bits(&bitmap, 0, 16));
    TEST_ASSERT_EQUAL_HEX8(0xFF, buf[0]);
    TEST_ASSERT_EQUAL_HEX8(0xFF, buf[1]);
    for (int i = 2; i < sizeof(buf) - 2; i++) {
        TEST_ASSERT_EQUAL_HEX8(0, buf[i]);
    }
    TEST_ASSERT_EQUAL_HEX8(0x00, (buf[8] & 0x7F));

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, bitmap_set_bits(&bitmap, 19, 16));
    TEST_ASSERT_EQUAL_HEX8(0xFF, buf[1]);
    TEST_ASSERT_EQUAL_HEX8(0xF8, buf[2]);
    TEST_ASSERT_EQUAL_HEX8(0xFF, buf[3]);
    TEST_ASSERT_EQUAL_HEX8(0x07, buf[4]);
    TEST_ASSERT_EQUAL_HEX8(0x00, buf[5]);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, bitmap_set_bits(&bitmap, 37, 2));
    TEST_ASSERT_EQUAL_HEX8(0xFF, buf[3]);
    TEST_ASSERT_EQUAL_HEX8(0x67, buf[4]);
    TEST_ASSERT_EQUAL_HEX8(0x00, buf[5]);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, bitmap_set_bits(&bitmap, 65, 100));
    TEST_ASSERT_EQUAL_HEX8(0x00, buf[7]);
    TEST_ASSERT_EQUAL_HEX8(0x7E, (buf[8] & 0x7F));
    TEST_ASSERT_EQUAL_HEX8(0xBA, buf[9]);

    TEST_ASSERT_EQUAL_HEX32(ERROR_INDEX_OUT_OF_RANGE, bitmap_set_bits(&bitmap, 71, 5));
    TEST_ASSERT_EQUAL_HEX32(ERROR_NULL_POINTER, bitmap_set_bits(0, 4, 4));
}



void test_clear_bits(void)
{
    uint8_t test[10] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xBA };
    uint8_t res[10]  = { 0x00, 0x00, 0xFF, 0x07, 0x00, 0xFE, 0xE7, 0xFF, 0x01, 0xBA };
    Bitmap bitmap;

    bitmap_init(&bitmap, test, 71);
    bitmap_set_bits(&bitmap, 0, 71);
    
    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, bitmap_clear_bits(&bitmap, 0, 16));
    for (int i = 0; i < 2; i++) {
        TEST_ASSERT_EQUAL_HEX8(res[i], test[i]);
    }
    for (int i = 2; i < sizeof(test) - 2; i++) {
        TEST_ASSERT_EQUAL_HEX8(0xFF, test[i]);
    }
    TEST_ASSERT_EQUAL_HEX8(0x7F, test[8] & 0x7F);
    TEST_ASSERT_EQUAL_HEX8(0xBA, test[9]);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, bitmap_clear_bits(&bitmap, 27, 14));
    for (int i = 0; i < 6; i++) {
        TEST_ASSERT_EQUAL_HEX8(res[i], test[i]);
    }
    for (int i = 6; i < sizeof(test) - 2; i++) {
        TEST_ASSERT_EQUAL_HEX8(0xFF, test[i]);
    }
    TEST_ASSERT_EQUAL_HEX8(0x7F, test[8] & 0x7F);
    TEST_ASSERT_EQUAL_HEX8(0xBA, test[9]);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, bitmap_clear_bits(&bitmap, 51, 2));
    for (int i = 0; i < 7; i++) {
        TEST_ASSERT_EQUAL_HEX8(res[i], test[i]);
    }
    for (int i = 7; i < sizeof(test) - 2; i++) {
        TEST_ASSERT_EQUAL_HEX8(0xFF, test[i]);
    }
    TEST_ASSERT_EQUAL_HEX8(0x7F, test[8] & 0x7F);
    TEST_ASSERT_EQUAL_HEX8(0xBA, test[9]);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, bitmap_clear_bits(&bitmap, 65, 100));
    for (int i = 0; i < sizeof(test); i++) {
        TEST_ASSERT_EQUAL_HEX8(res[i], test[i]);
    }

    TEST_ASSERT_EQUAL_HEX32(ERROR_NULL_POINTER, bitmap_clear_bits(0, 1, 1));
    TEST_ASSERT_EQUAL_HEX32(ERROR_INDEX_OUT_OF_RANGE, bitmap_clear_bits(&bitmap, 71, 1));
}



void test_set_bit(void)
{
    char test[10] = { 0xFF };
    test[9] = 0xBA;
    Bitmap bitmap;

    bitmap_init(&bitmap, test, 71);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, bitmap_set_bit(&bitmap, 5));
    TEST_ASSERT_EQUAL_HEX8(0x20, test[0]);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, bitmap_set_bit(&bitmap, 69));
    TEST_ASSERT_EQUAL_HEX8((0x20 & 0x7f), (test[8] & 0x7f));

    TEST_ASSERT_EQUAL_HEX32(ERROR_INDEX_OUT_OF_RANGE, bitmap_set_bit(&bitmap, 71));
    TEST_ASSERT_EQUAL_HEX32(ERROR_NULL_POINTER, bitmap_set_bit(0, 71));
}



void test_clear_bit(void)
{
    char test[10] = { 0xFF };
    test[9] = 0xBA;
    Bitmap bitmap;

    bitmap_init(&bitmap, test, 71);
    bitmap_set_bits(&bitmap, 0, 71);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, bitmap_clear_bit(&bitmap, 5));
    TEST_ASSERT_EQUAL_HEX8(~0x20, test[0]);

    TEST_ASSERT_EQUAL_HEX32(ERROR_SUCCESS, bitmap_clear_bit(&bitmap, 69));
    TEST_ASSERT_EQUAL_HEX8((~0x20) & 0x7f, (test[8] & 0x7f));

    TEST_ASSERT_EQUAL_HEX32(ERROR_INDEX_OUT_OF_RANGE, bitmap_clear_bit(&bitmap, 71));
    TEST_ASSERT_EQUAL_HEX32(ERROR_NULL_POINTER, bitmap_set_bit(0, 71));
}



void test_bitmap_find_one(void)
{
    char test[10] = { 0xFF };
    Bitmap bitmap;
    bitmap_init(&bitmap, test, 71);

    TEST_ASSERT_EQUAL(-1, bitmap_find_one(&bitmap, 0));

    bitmap_set_bits(&bitmap, 6, 15);
    bitmap_set_bits(&bitmap, 0, 1);
    bitmap_set_bits(&bitmap, 65, 1);
    bitmap_set_bits(&bitmap, 70, 1);

    TEST_ASSERT_EQUAL(0, bitmap_find_one(&bitmap, 0));
    TEST_ASSERT_EQUAL(6, bitmap_find_one(&bitmap, 1));
    TEST_ASSERT_EQUAL(6, bitmap_find_one(&bitmap, 3));
    TEST_ASSERT_EQUAL(8, bitmap_find_one(&bitmap, 8));
    TEST_ASSERT_EQUAL(65, bitmap_find_one(&bitmap, 25));
    TEST_ASSERT_EQUAL(70, bitmap_find_one(&bitmap, 66));
    TEST_ASSERT_EQUAL(-1, bitmap_find_one(&bitmap, 71));
    TEST_ASSERT_EQUAL(-1, bitmap_find_one(0, 25));
}



void test_bitmap_find_null(void)
{
    char test[10] = { 0xFF };
    Bitmap bitmap;

    bitmap_init(&bitmap, test, 71);
    bitmap_set_bits(&bitmap, 0, 71);

    TEST_ASSERT_EQUAL(-1, bitmap_find_null(&bitmap, 0));

    bitmap_clear_bits(&bitmap, 6, 15);
    bitmap_clear_bits(&bitmap, 0, 1);
    bitmap_clear_bits(&bitmap, 65, 1);
    bitmap_clear_bits(&bitmap, 70, 1);

    TEST_ASSERT_EQUAL(0, bitmap_find_null(&bitmap, 0));
    TEST_ASSERT_EQUAL(6, bitmap_find_null(&bitmap, 1));
    TEST_ASSERT_EQUAL(6, bitmap_find_null(&bitmap, 3));
    TEST_ASSERT_EQUAL(8, bitmap_find_null(&bitmap, 8));
    TEST_ASSERT_EQUAL(65, bitmap_find_null(&bitmap, 25));
    TEST_ASSERT_EQUAL(70, bitmap_find_null(&bitmap, 66));
    TEST_ASSERT_EQUAL(-1, bitmap_find_null(&bitmap, 71));
    TEST_ASSERT_EQUAL(-1, bitmap_find_null(0, 25));
}
