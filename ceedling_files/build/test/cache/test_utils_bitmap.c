#include "error.h"
#include "utils/bitmap.h"
#include "unity.h"






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



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((bitmap_init(&bitmap, buf, 71))), (((void *)0)), (_U_UINT)(24), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)((buf)), (_U_SINT)(_US32)((bitmap.data)), (((void *)0)), (_U_UINT)(25), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)((71)), (_U_SINT)((bitmap.length)), (((void *)0)), (_U_UINT)(26), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((9)), (_U_SINT)((bitmap.n_bytes)), (((void *)0)), (_U_UINT)(27), UNITY_DISPLAY_STYLE_INT);

    for (int i = 0; i < sizeof(buf) - 2; i++) {

        UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((buf[i])), (((void *)0)), (_U_UINT)(29), UNITY_DISPLAY_STYLE_INT);

    }

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0xBA)), (_U_SINT)(_US8 )((buf[sizeof(buf) - 1])), (((void *)0)), (_U_UINT)(31), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )(((buf[8] & 0x7F))), (((void *)0)), (_U_UINT)(32), UNITY_DISPLAY_STYLE_HEX8);



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000000))), (_U_SINT)(_US32)((bitmap_init(0, buf, 77))), (((void *)0)), (_U_UINT)(34), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000000))), (_U_SINT)(_US32)((bitmap_init(&bitmap, 0, 77))), (((void *)0)), (_U_UINT)(35), UNITY_DISPLAY_STYLE_HEX32);

}







void test_set_bits(void)

{

    uint8_t buf[10] = { 0xFF };

    buf[9] = 0xBA;

    Bitmap bitmap;



    bitmap_init(&bitmap, buf, 71);



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((bitmap_set_bits(&bitmap, 0, 0))), (((void *)0)), (_U_UINT)(48), UNITY_DISPLAY_STYLE_HEX32);

    for (int i = 0; i < sizeof(buf) - 2; i++) {

        UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((buf[i])), (((void *)0)), (_U_UINT)(50), UNITY_DISPLAY_STYLE_INT);

    }

    UnityAssertEqualNumber((_U_SINT)((0x00)), (_U_SINT)(((buf[8] & 0x7F))), (((void *)0)), (_U_UINT)(52), UNITY_DISPLAY_STYLE_INT);



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((bitmap_set_bits(&bitmap, 0, 16))), (((void *)0)), (_U_UINT)(54), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFF)), (_U_SINT)(_US8 )((buf[0])), (((void *)0)), (_U_UINT)(55), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFF)), (_U_SINT)(_US8 )((buf[1])), (((void *)0)), (_U_UINT)(56), UNITY_DISPLAY_STYLE_HEX8);

    for (int i = 2; i < sizeof(buf) - 2; i++) {

        UnityAssertEqualNumber((_U_SINT)(_US8 )((0)), (_U_SINT)(_US8 )((buf[i])), (((void *)0)), (_U_UINT)(58), UNITY_DISPLAY_STYLE_HEX8);

    }

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )(((buf[8] & 0x7F))), (((void *)0)), (_U_UINT)(60), UNITY_DISPLAY_STYLE_HEX8);



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((bitmap_set_bits(&bitmap, 19, 16))), (((void *)0)), (_U_UINT)(62), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFF)), (_U_SINT)(_US8 )((buf[1])), (((void *)0)), (_U_UINT)(63), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0xF8)), (_U_SINT)(_US8 )((buf[2])), (((void *)0)), (_U_UINT)(64), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFF)), (_U_SINT)(_US8 )((buf[3])), (((void *)0)), (_U_UINT)(65), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0x07)), (_U_SINT)(_US8 )((buf[4])), (((void *)0)), (_U_UINT)(66), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((buf[5])), (((void *)0)), (_U_UINT)(67), UNITY_DISPLAY_STYLE_HEX8);



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((bitmap_set_bits(&bitmap, 37, 2))), (((void *)0)), (_U_UINT)(69), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFF)), (_U_SINT)(_US8 )((buf[3])), (((void *)0)), (_U_UINT)(70), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0x67)), (_U_SINT)(_US8 )((buf[4])), (((void *)0)), (_U_UINT)(71), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((buf[5])), (((void *)0)), (_U_UINT)(72), UNITY_DISPLAY_STYLE_HEX8);



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((bitmap_set_bits(&bitmap, 65, 100))), (((void *)0)), (_U_UINT)(74), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0x00)), (_U_SINT)(_US8 )((buf[7])), (((void *)0)), (_U_UINT)(75), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0x7E)), (_U_SINT)(_US8 )(((buf[8] & 0x7F))), (((void *)0)), (_U_UINT)(76), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0xBA)), (_U_SINT)(_US8 )((buf[9])), (((void *)0)), (_U_UINT)(77), UNITY_DISPLAY_STYLE_HEX8);



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000002))), (_U_SINT)(_US32)((bitmap_set_bits(&bitmap, 71, 5))), (((void *)0)), (_U_UINT)(79), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000000))), (_U_SINT)(_US32)((bitmap_set_bits(0, 4, 4))), (((void *)0)), (_U_UINT)(80), UNITY_DISPLAY_STYLE_HEX32);

}







void test_clear_bits(void)

{

    uint8_t test[10] = { 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xBA };

    uint8_t res[10] = { 0x00, 0x00, 0xFF, 0x07, 0x00, 0xFE, 0xE7, 0xFF, 0x01, 0xBA };

    Bitmap bitmap;



    bitmap_init(&bitmap, test, 71);

    bitmap_set_bits(&bitmap, 0, 71);



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((bitmap_clear_bits(&bitmap, 0, 16))), (((void *)0)), (_U_UINT)(94), UNITY_DISPLAY_STYLE_HEX32);

    for (int i = 0; i < 2; i++) {

        UnityAssertEqualNumber((_U_SINT)(_US8 )((res[i])), (_U_SINT)(_US8 )((test[i])), (((void *)0)), (_U_UINT)(96), UNITY_DISPLAY_STYLE_HEX8);

    }

    for (int i = 2; i < sizeof(test) - 2; i++) {

        UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFF)), (_U_SINT)(_US8 )((test[i])), (((void *)0)), (_U_UINT)(99), UNITY_DISPLAY_STYLE_HEX8);

    }

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0x7F)), (_U_SINT)(_US8 )((test[8] & 0x7F)), (((void *)0)), (_U_UINT)(101), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0xBA)), (_U_SINT)(_US8 )((test[9])), (((void *)0)), (_U_UINT)(102), UNITY_DISPLAY_STYLE_HEX8);



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((bitmap_clear_bits(&bitmap, 27, 14))), (((void *)0)), (_U_UINT)(104), UNITY_DISPLAY_STYLE_HEX32);

    for (int i = 0; i < 6; i++) {

        UnityAssertEqualNumber((_U_SINT)(_US8 )((res[i])), (_U_SINT)(_US8 )((test[i])), (((void *)0)), (_U_UINT)(106), UNITY_DISPLAY_STYLE_HEX8);

    }

    for (int i = 6; i < sizeof(test) - 2; i++) {

        UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFF)), (_U_SINT)(_US8 )((test[i])), (((void *)0)), (_U_UINT)(109), UNITY_DISPLAY_STYLE_HEX8);

    }

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0x7F)), (_U_SINT)(_US8 )((test[8] & 0x7F)), (((void *)0)), (_U_UINT)(111), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0xBA)), (_U_SINT)(_US8 )((test[9])), (((void *)0)), (_U_UINT)(112), UNITY_DISPLAY_STYLE_HEX8);



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((bitmap_clear_bits(&bitmap, 51, 2))), (((void *)0)), (_U_UINT)(114), UNITY_DISPLAY_STYLE_HEX32);

    for (int i = 0; i < 7; i++) {

        UnityAssertEqualNumber((_U_SINT)(_US8 )((res[i])), (_U_SINT)(_US8 )((test[i])), (((void *)0)), (_U_UINT)(116), UNITY_DISPLAY_STYLE_HEX8);

    }

    for (int i = 7; i < sizeof(test) - 2; i++) {

        UnityAssertEqualNumber((_U_SINT)(_US8 )((0xFF)), (_U_SINT)(_US8 )((test[i])), (((void *)0)), (_U_UINT)(119), UNITY_DISPLAY_STYLE_HEX8);

    }

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0x7F)), (_U_SINT)(_US8 )((test[8] & 0x7F)), (((void *)0)), (_U_UINT)(121), UNITY_DISPLAY_STYLE_HEX8);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0xBA)), (_U_SINT)(_US8 )((test[9])), (((void *)0)), (_U_UINT)(122), UNITY_DISPLAY_STYLE_HEX8);



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((bitmap_clear_bits(&bitmap, 65, 100))), (((void *)0)), (_U_UINT)(124), UNITY_DISPLAY_STYLE_HEX32);

    for (int i = 0; i < sizeof(test); i++) {

        UnityAssertEqualNumber((_U_SINT)(_US8 )((res[i])), (_U_SINT)(_US8 )((test[i])), (((void *)0)), (_U_UINT)(126), UNITY_DISPLAY_STYLE_HEX8);

    }



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000000))), (_U_SINT)(_US32)((bitmap_clear_bits(0, 1, 1))), (((void *)0)), (_U_UINT)(129), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000002))), (_U_SINT)(_US32)((bitmap_clear_bits(&bitmap, 71, 1))), (((void *)0)), (_U_UINT)(130), UNITY_DISPLAY_STYLE_HEX32);

}







void test_set_bit(void)

{

    char test[10] = { 0xFF };

    test[9] = 0xBA;

    Bitmap bitmap;



    bitmap_init(&bitmap, test, 71);



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((bitmap_set_bit(&bitmap, 5))), (((void *)0)), (_U_UINT)(143), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((0x20)), (_U_SINT)(_US8 )((test[0])), (((void *)0)), (_U_UINT)(144), UNITY_DISPLAY_STYLE_HEX8);



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((bitmap_set_bit(&bitmap, 69))), (((void *)0)), (_U_UINT)(146), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US8 )(((0x20 & 0x7f))), (_U_SINT)(_US8 )(((test[8] & 0x7f))), (((void *)0)), (_U_UINT)(147), UNITY_DISPLAY_STYLE_HEX8);



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000002))), (_U_SINT)(_US32)((bitmap_set_bit(&bitmap, 71))), (((void *)0)), (_U_UINT)(149), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000000))), (_U_SINT)(_US32)((bitmap_set_bit(0, 71))), (((void *)0)), (_U_UINT)(150), UNITY_DISPLAY_STYLE_HEX32);

}







void test_clear_bit(void)

{

    char test[10] = { 0xFF };

    test[9] = 0xBA;

    Bitmap bitmap;



    bitmap_init(&bitmap, test, 71);

    bitmap_set_bits(&bitmap, 0, 71);



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((bitmap_clear_bit(&bitmap, 5))), (((void *)0)), (_U_UINT)(164), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US8 )((~0x20)), (_U_SINT)(_US8 )((test[0])), (((void *)0)), (_U_UINT)(165), UNITY_DISPLAY_STYLE_HEX8);



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((bitmap_clear_bit(&bitmap, 69))), (((void *)0)), (_U_UINT)(167), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US8 )(((~0x20) & 0x7f)), (_U_SINT)(_US8 )(((test[8] & 0x7f))), (((void *)0)), (_U_UINT)(168), UNITY_DISPLAY_STYLE_HEX8);



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000002))), (_U_SINT)(_US32)((bitmap_clear_bit(&bitmap, 71))), (((void *)0)), (_U_UINT)(170), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000000))), (_U_SINT)(_US32)((bitmap_set_bit(0, 71))), (((void *)0)), (_U_UINT)(171), UNITY_DISPLAY_STYLE_HEX32);

}







void test_bitmap_find_one(void)

{

    char test[10] = { 0xFF };

    Bitmap bitmap;

    bitmap_init(&bitmap, test, 71);



    UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((bitmap_find_one(&bitmap, 0))), (((void *)0)), (_U_UINT)(182), UNITY_DISPLAY_STYLE_INT);



    bitmap_set_bits(&bitmap, 6, 15);

    bitmap_set_bits(&bitmap, 0, 1);

    bitmap_set_bits(&bitmap, 65, 1);

    bitmap_set_bits(&bitmap, 70, 1);



    UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((bitmap_find_one(&bitmap, 0))), (((void *)0)), (_U_UINT)(189), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((bitmap_find_one(&bitmap, 1))), (((void *)0)), (_U_UINT)(190), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((bitmap_find_one(&bitmap, 3))), (((void *)0)), (_U_UINT)(191), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((bitmap_find_one(&bitmap, 8))), (((void *)0)), (_U_UINT)(192), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((65)), (_U_SINT)((bitmap_find_one(&bitmap, 25))), (((void *)0)), (_U_UINT)(193), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((bitmap_find_one(&bitmap, 66))), (((void *)0)), (_U_UINT)(194), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((bitmap_find_one(&bitmap, 71))), (((void *)0)), (_U_UINT)(195), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((bitmap_find_one(0, 25))), (((void *)0)), (_U_UINT)(196), UNITY_DISPLAY_STYLE_INT);

}







void test_bitmap_find_null(void)

{

    char test[10] = { 0xFF };

    Bitmap bitmap;



    bitmap_init(&bitmap, test, 71);

    bitmap_set_bits(&bitmap, 0, 71);



    UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((bitmap_find_null(&bitmap, 0))), (((void *)0)), (_U_UINT)(209), UNITY_DISPLAY_STYLE_INT);



    bitmap_clear_bits(&bitmap, 6, 15);

    bitmap_clear_bits(&bitmap, 0, 1);

    bitmap_clear_bits(&bitmap, 65, 1);

    bitmap_clear_bits(&bitmap, 70, 1);



    UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((bitmap_find_null(&bitmap, 0))), (((void *)0)), (_U_UINT)(216), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((bitmap_find_null(&bitmap, 1))), (((void *)0)), (_U_UINT)(217), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((6)), (_U_SINT)((bitmap_find_null(&bitmap, 3))), (((void *)0)), (_U_UINT)(218), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((8)), (_U_SINT)((bitmap_find_null(&bitmap, 8))), (((void *)0)), (_U_UINT)(219), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((65)), (_U_SINT)((bitmap_find_null(&bitmap, 25))), (((void *)0)), (_U_UINT)(220), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((70)), (_U_SINT)((bitmap_find_null(&bitmap, 66))), (((void *)0)), (_U_UINT)(221), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((bitmap_find_null(&bitmap, 71))), (((void *)0)), (_U_UINT)(222), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((-1)), (_U_SINT)((bitmap_find_null(0, 25))), (((void *)0)), (_U_UINT)(223), UNITY_DISPLAY_STYLE_INT);

}
