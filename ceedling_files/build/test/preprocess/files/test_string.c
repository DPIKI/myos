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
