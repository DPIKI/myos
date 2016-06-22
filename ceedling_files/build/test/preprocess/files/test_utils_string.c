#include "error.h"
#include "utils/string.h"
#include "unity.h"






void setUp(void)

{

}







void tearDown(void)

{

}







void test_str_len(void)

{

    UnityAssertEqualNumber((_U_SINT)((5)), (_U_SINT)((str_len("hello"))), (((void *)0)), (_U_UINT)(21), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((0)), (_U_SINT)((str_len(""))), (((void *)0)), (_U_UINT)(22), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((_U_SINT)((14)), (_U_SINT)((str_len("string testing"))), (((void *)0)), (_U_UINT)(23), UNITY_DISPLAY_STYLE_INT);

}







void test_str_cpy(void)

{

    char str[] = "test string";



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((str_cpy(str, sizeof(str), "lazy"))), (((void *)0)), (_U_UINT)(32), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("lazy string")), (const char*)((str)), (((void *)0)), (_U_UINT)(33));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((str_cpy(str, sizeof(str), "test string"))), (((void *)0)), (_U_UINT)(35), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("test string")), (const char*)((str)), (((void *)0)), (_U_UINT)(36));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000001))), (_U_SINT)(_US32)((str_cpy(str, sizeof(str), "long long string"))), (((void *)0)), (_U_UINT)(38), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000001))), (_U_SINT)(_US32)((str_cpy(str, sizeof(str), "test stringg"))), (((void *)0)), (_U_UINT)(39), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000000))), (_U_SINT)(_US32)((str_cpy(str, sizeof(str), 0))), (((void *)0)), (_U_UINT)(40), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000000))), (_U_SINT)(_US32)((str_cpy(0, sizeof(str), str))), (((void *)0)), (_U_UINT)(41), UNITY_DISPLAY_STYLE_HEX32);

}







void test_str_ncpy(void)

{

    char str[] = "test string";



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((str_ncpy(str, sizeof(str), "lazy", 4))), (((void *)0)), (_U_UINT)(50), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("lazy string")), (const char*)((str)), (((void *)0)), (_U_UINT)(51));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((str_ncpy(str, sizeof(str), "mono", 5))), (((void *)0)), (_U_UINT)(53), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("mono")), (const char*)((str)), (((void *)0)), (_U_UINT)(54));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((str_ncpy(str, sizeof(str), "mono mono", 9))), (((void *)0)), (_U_UINT)(56), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("mono mono")), (const char*)((str)), (((void *)0)), (_U_UINT)(57));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000001))), (_U_SINT)(_US32)((str_ncpy(str, sizeof(str), "mono mono mono", sizeof(str)))), (((void *)0)), (_U_UINT)(59), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000001))), (_U_SINT)(_US32)((str_ncpy(str, sizeof(str), "mono mono mono", 15))), (((void *)0)), (_U_UINT)(60), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000000))), (_U_SINT)(_US32)((str_ncpy(str, sizeof(str), 0, sizeof(str)))), (((void *)0)), (_U_UINT)(61), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000000))), (_U_SINT)(_US32)((str_ncpy(0, sizeof(str), str, sizeof(str)))), (((void *)0)), (_U_UINT)(62), UNITY_DISPLAY_STYLE_HEX32);

}







void test_str_cat(void)

{

    char str[10] = "foo ";

    char str2[10] = "lala ";



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((str_cat(str, sizeof(str), "bar"))), (((void *)0)), (_U_UINT)(72), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("foo bar")), (const char*)((str)), (((void *)0)), (_U_UINT)(73));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((str_cat(str, sizeof(str), "ba"))), (((void *)0)), (_U_UINT)(75), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("foo barba")), (const char*)((str)), (((void *)0)), (_U_UINT)(76));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((str_cat(str, sizeof(str), ""))), (((void *)0)), (_U_UINT)(78), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("foo barba")), (const char*)((str)), (((void *)0)), (_U_UINT)(79));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000001))), (_U_SINT)(_US32)((str_cat(str, sizeof(str), "a"))), (((void *)0)), (_U_UINT)(81), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000001))), (_U_SINT)(_US32)((str_cat(str2, sizeof(str), "a;aaa"))), (((void *)0)), (_U_UINT)(82), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000000))), (_U_SINT)(_US32)((str_cat(0, sizeof(str), "aaaa"))), (((void *)0)), (_U_UINT)(83), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000000))), (_U_SINT)(_US32)((str_cat(str, sizeof(str), 0))), (((void *)0)), (_U_UINT)(84), UNITY_DISPLAY_STYLE_HEX32);

}









void test_itoa_i(void)

{

    char str[6];



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((itoa_i(5, str, sizeof(str)))), (((void *)0)), (_U_UINT)(94), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("5")), (const char*)((str)), (((void *)0)), (_U_UINT)(95));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((itoa_i(0, str, sizeof(str)))), (((void *)0)), (_U_UINT)(97), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("0")), (const char*)((str)), (((void *)0)), (_U_UINT)(98));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((itoa_i(45434, str, sizeof(str)))), (((void *)0)), (_U_UINT)(100), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("45434")), (const char*)((str)), (((void *)0)), (_U_UINT)(101));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((itoa_i(-4543, str, sizeof(str)))), (((void *)0)), (_U_UINT)(103), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("-4543")), (const char*)((str)), (((void *)0)), (_U_UINT)(104));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((itoa_i(-5, str, sizeof(str)))), (((void *)0)), (_U_UINT)(106), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("-5")), (const char*)((str)), (((void *)0)), (_U_UINT)(107));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000001))), (_U_SINT)(_US32)((itoa_i(343434, str, sizeof(str)))), (((void *)0)), (_U_UINT)(109), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000001))), (_U_SINT)(_US32)((itoa_i(-43434, str, sizeof(str)))), (((void *)0)), (_U_UINT)(110), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000001))), (_U_SINT)(_US32)((itoa_i(-343434, str, sizeof(str)))), (((void *)0)), (_U_UINT)(111), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000000))), (_U_SINT)(_US32)((itoa_i(-343434, 0, sizeof(str)))), (((void *)0)), (_U_UINT)(112), UNITY_DISPLAY_STYLE_HEX32);

}







void test_itoa_u(void)

{

    char str[6];



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((itoa_u(5, str, sizeof(str)))), (((void *)0)), (_U_UINT)(121), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("5")), (const char*)((str)), (((void *)0)), (_U_UINT)(122));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((itoa_u(0, str, sizeof(str)))), (((void *)0)), (_U_UINT)(124), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("0")), (const char*)((str)), (((void *)0)), (_U_UINT)(125));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((itoa_u(45434, str, sizeof(str)))), (((void *)0)), (_U_UINT)(127), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("45434")), (const char*)((str)), (((void *)0)), (_U_UINT)(128));



    char str1[11];



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((itoa_u(3000000000, str1, sizeof(str1)))), (((void *)0)), (_U_UINT)(132), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("3000000000")), (const char*)((str1)), (((void *)0)), (_U_UINT)(133));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000001))), (_U_SINT)(_US32)((itoa_u(343434, str, sizeof(str)))), (((void *)0)), (_U_UINT)(135), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000000))), (_U_SINT)(_US32)((itoa_u(-343434, 0, sizeof(str)))), (((void *)0)), (_U_UINT)(136), UNITY_DISPLAY_STYLE_HEX32);

}







void test_itoa_x8(void)

{

    char str[5];



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((itoa_x8(5, str, sizeof(str)))), (((void *)0)), (_U_UINT)(145), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("0x05")), (const char*)((str)), (((void *)0)), (_U_UINT)(146));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((itoa_x8(255, str, sizeof(str)))), (((void *)0)), (_U_UINT)(148), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("0xFF")), (const char*)((str)), (((void *)0)), (_U_UINT)(149));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((itoa_x8(0xAB, str, sizeof(str)))), (((void *)0)), (_U_UINT)(151), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("0xAB")), (const char*)((str)), (((void *)0)), (_U_UINT)(152));



    char str1[4];



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000001))), (_U_SINT)(_US32)((itoa_x8(5, str1, sizeof(str1)))), (((void *)0)), (_U_UINT)(156), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000000))), (_U_SINT)(_US32)((itoa_x8(5, 0, sizeof(str1)))), (((void *)0)), (_U_UINT)(157), UNITY_DISPLAY_STYLE_HEX32);

}







void test_itoa_x16(void)

{

    char str[7];



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((itoa_x16(5, str, sizeof(str)))), (((void *)0)), (_U_UINT)(166), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("0x0005")), (const char*)((str)), (((void *)0)), (_U_UINT)(167));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((itoa_x16(0xFFFF, str, sizeof(str)))), (((void *)0)), (_U_UINT)(169), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("0xFFFF")), (const char*)((str)), (((void *)0)), (_U_UINT)(170));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((itoa_x16(0xABCD, str, sizeof(str)))), (((void *)0)), (_U_UINT)(172), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("0xABCD")), (const char*)((str)), (((void *)0)), (_U_UINT)(173));



    char str1[6];



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000001))), (_U_SINT)(_US32)((itoa_x16(5, str1, sizeof(str1)))), (((void *)0)), (_U_UINT)(177), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000000))), (_U_SINT)(_US32)((itoa_x16(5, 0, sizeof(str1)))), (((void *)0)), (_U_UINT)(178), UNITY_DISPLAY_STYLE_HEX32);

}







void test_itoa_x32(void)

{

    char str[11];



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((itoa_x32(5, str, sizeof(str)))), (((void *)0)), (_U_UINT)(187), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("0x00000005")), (const char*)((str)), (((void *)0)), (_U_UINT)(188));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((itoa_x32(0xFFFFFFFF, str, sizeof(str)))), (((void *)0)), (_U_UINT)(190), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("0xFFFFFFFF")), (const char*)((str)), (((void *)0)), (_U_UINT)(191));



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x00000000))), (_U_SINT)(_US32)((itoa_x32(0xABCDEFAB, str, sizeof(str)))), (((void *)0)), (_U_UINT)(193), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualString((const char*)(("0xABCDEFAB")), (const char*)((str)), (((void *)0)), (_U_UINT)(194));



    char str1[10];



    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000001))), (_U_SINT)(_US32)((itoa_x32(5, str1, sizeof(str1)))), (((void *)0)), (_U_UINT)(198), UNITY_DISPLAY_STYLE_HEX32);

    UnityAssertEqualNumber((_U_SINT)(_US32)(((0x80000000))), (_U_SINT)(_US32)((itoa_x32(5, 0, sizeof(str1)))), (((void *)0)), (_U_UINT)(199), UNITY_DISPLAY_STYLE_HEX32);

}
