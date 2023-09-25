#include "../libs/alg/algc.h"

#include <stdio.h>
#include <assert.h>
#include <string.h>

void testWriteFromToStr() {
    string1 emptyString;
    WriteToStr(emptyString, "");
    assert(!strcmp(emptyString, ""));
    assert(StrError == OK);
    char emptyStringChar[256];
    WriteFromStr(emptyStringChar, emptyString);
    assert(StrError == OK);
    assert(!strcmp(emptyStringChar, ""));

    string1 nonEmptyString;
    WriteToStr(nonEmptyString, "Cool val");
    assert(!strcmp(nonEmptyString, "Cool val"));
    assert(StrError == OK);
    char nonEmptyStringChar[256];
    WriteFromStr(nonEmptyStringChar, nonEmptyString);
    assert(StrError == OK);
    assert(!strcmp(nonEmptyStringChar, "Cool val"));

    string1 tooBigString;
    WriteToStr(tooBigString, "....................................................................................................................................................................................................................................................................");
    assert(StrError == BUFFER_OVERFLOW);
}

void testComp() {
    string1 t1s1 = "";
    string1 t1s2 = "";
    assert(Comp(t1s1, t1s2) == 0);
    assert(StrError == OK);

    string1 t2s1 = "A";
    string1 t2s2 = "";
    assert(Comp(t2s1, t2s2) == 1);
    assert(StrError == OK);

    string1 t3s1 = "";
    string1 t3s2 = "A";
    assert(Comp(t3s1, t3s2) == -1);
    assert(StrError == OK);

    string1 t4s1 = "AAAdasd";
    string1 t4s2 = "AAB";
    assert(Comp(t4s1, t4s2) == -1);
    assert(StrError == OK);
}

void testDelete() {
    string1 str1 = "";
    Delete(str1, 0, 0);
    assert(StrError == OK);
    assert(!strcmp(str1, ""));

    string1 str5 = "";
    Delete(str5, 0, 1);
    assert(StrError == OUT_OF_BOUNDS);

    string1 str2 = "A";
    Delete(str2, 0, 1);
    assert(StrError == OK);
    assert(!strcmp(str1, ""));

    string1 str3 = "A";
    Delete(str3, 0, 2);
    assert(StrError == OUT_OF_BOUNDS);

    string1 str4 = "I do not love algorithms and data structures";
    Delete(str4, 1, 7);
    assert(StrError == OK);
    assert(!strcmp(str4, "I love algorithms and data structures"));

    string1 str6 = "I am about to be deleted";
    Delete(str6, 0, 24);
    assert(StrError == OK);
    assert(!strcmp(str6, ""));
}

void testInsert() {
    string1 t1sb = "";
    string1 t1s = "";
    Insert(t1sb, t1s, 0);
    assert(StrError == OK);
    assert(!strcmp(t1s, ""));

    string1 t2sb = "love ";
    string1 t2s = "I algorithms and data structures";
    Insert(t2sb, t2s, 2);
    assert(StrError == OK);
    assert(!strcmp(t2s, "I love algorithms and data structures"));

    string1 t3sb = "I ";
    string1 t3s = "love algorithms and data structures";
    Insert(t3sb, t3s, 0);
    assert(StrError == OK);
    assert(!strcmp(t3s, "I love algorithms and data structures"));

    string1 t4sb = "pizza";
    string1 t4s = "I love ";
    Insert(t4sb, t4s, 7);
    assert(StrError == OK);
    assert(!strcmp(t4s, "I love pizza"));

    string1 t5sb = "1izzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizza";
    string1 t5s = "2izzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizza";
    Insert(t5sb, t5s, 1);
    assert(StrError == OK);
    assert(!strcmp(t5s, "21izzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzaizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizza"));

    string1 t6sb = "1231231izzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizza";
    string1 t6s = "2izzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizza";
    Insert(t6sb, t6s, 1);
    assert(StrError == BUFFER_OVERFLOW);
}

void testConcat() {
    string1 t1s1 = "";
    string1 t1s2 = "";
    string1 res1;
    Concat(t1s1, t1s2, res1);
    assert(StrError == OK);
    assert(!strcmp(res1, ""));

    string1 t2s1 = "42";
    string1 t2s2 = "";
    string1 res2;
    Concat(t2s1, t2s2, res2);
    assert(StrError == OK);
    assert(!strcmp(res2, "42"));

    string1 t3s1 = "";
    string1 t3s2 = "42";
    string1 res3;
    Concat(t3s1, t3s2, res3);
    assert(StrError == OK);
    assert(!strcmp(res3, "42"));

    string1 t4s1 = "I love algorithms and data structures";
    string1 t4s2 = " and pizza";
    string1 res4;
    Concat(t4s1, t4s2, res4);
    assert(StrError == OK);
    assert(!strcmp(res4, "I love algorithms and data structures and pizza"));

    string1 t5s1 = "1231231izzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizza";
    string1 t5s2 = "2izzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizzapizza";
    string1 res5;
    Concat(t5s1, t5s2, res5);
    assert(StrError == BUFFER_OVERFLOW);
}

void testCopy() {
    string1 origin1 = "";
    string1 substr1 = "Lorem ipsum";
    Copy(origin1, 0, 0, substr1);
    assert(StrError == OK);
    assert(!strcmp(substr1, ""));

    string1 origin2 = "A";
    string1 substr2 = "Lorem ipsum";
    Copy(origin2, 0, 0, substr2);
    assert(StrError == OK);
    assert(!strcmp(substr2, ""));

    string1 origin3 = "A";
    string1 substr3 = "Lorem ipsum";
    Copy(origin3, 0, 1, substr3);
    assert(StrError == OK);
    assert(!strcmp(substr3, "A"));

    string1 origin4 = "A";
    string1 substr4 = "Lorem ipsum";
    Copy(origin4, 0, 2, substr4);
    assert(StrError == OUT_OF_BOUNDS);

    string1 origin5 = "There is an answer t42o all questions";
    string1 substr5 = "Lorem ipsum";
    Copy(origin5, 20, 2, substr5);
    assert(StrError == OK);
    assert(!strcmp(substr5, "42"));

    string1 origin6 = "There is no answer to all questions";
    string1 substr6 = "Lorem ipsum";
    Copy(origin6, 33, 2, substr6);
    assert(StrError == OK);
    assert(!strcmp(substr6, "ns"));

    string1 origin7 = "There is no answer to all questions";
    string1 substr7 = "Lorem ipsum";
    Copy(origin7, 33, 3, substr7);
    assert(StrError == OUT_OF_BOUNDS);

    string1 origin8 = "There is no answer to all questions";
    string1 substr8 = "Lorem ipsum";
    Copy(origin8, 35, 3, substr8);
    assert(StrError == OUT_OF_BOUNDS);

    string1 origin9 = "1PizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizza1PizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizza1PizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizza1PizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaa";
    string1 substr9 = "Lorem ipsum";
    Copy(origin9, 0, 255, substr9);
    assert(StrError == OK);
    assert(!strcmp(substr9, "1PizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizza1PizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizza1PizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizza1PizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaa"));
    
    string1 origin10 = "1111PizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizza1PizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizza1PizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizza1PizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizzaPizza";
    string1 substr10 = "Lorem ipsum";
    Copy(origin10, 0, 256, substr10);
    assert(StrError == BUFFER_OVERFLOW);
}

void testPos() {
    string1 t1origin = "";
    string1 t1search = "";
    assert(Pos(t1search, t1origin) == 0);
    assert(StrError == OK);

    string1 t2origin = "Some text";
    string1 t2search = "";
    assert(Pos(t2search, t2origin) == 0);
    assert(StrError == OK);

    string1 t3origin = "Some text";
    string1 t3search = "S";
    assert(Pos(t3search, t3origin) == 0);
    assert(StrError == OK);

    string1 t4origin = "Some text";
    string1 t4search = " ";
    assert(Pos(t4search, t4origin) == 4);
    assert(StrError == OK);

    string1 t5origin = "Some textp";
    string1 t5search = "p";
    assert(Pos(t5search, t5origin) == 9);
    assert(StrError == OK);

    string1 t6origin = "Some text";
    string1 t6search = "[";
    assert(Pos(t6search, t6origin) == -1);
    assert(StrError == OK);

    string1 t7origin = "I love algorithms, data structures, pizza and 42.";
    string1 t7search = "I lo";
    assert(Pos(t7search, t7origin) == 0);
    assert(StrError == OK);

    string1 t8origin = "I love algorithms, data structures, pizza and 42.";
    string1 t8search = "I love algorithms, data structures, pizza and 42.";
    assert(Pos(t8search, t8origin) == 0);
    assert(StrError == OK);

    string1 t9origin = "I love algorithms, data structures, pizza and 42.";
    string1 t9search = "data";
    assert(Pos(t9search, t9origin) == 19);
    assert(StrError == OK);

    string1 t10origin = "I love algorithms, data structures, pizza and 42.";
    string1 t10search = "42.";
    assert(Pos(t10search, t10origin) == 46);
    assert(StrError == OK);

    // Requiem for pizza
    string1 t11origin = "I love algorithms, data structures, pizza and 42.";
    string1 t11search = "pizza";
    assert(Pos(t11search, t11origin) == 36);
    assert(StrError == OK);
}

void test() {
    testWriteFromToStr();
    testComp();
    testDelete();
    testInsert();
    testConcat();
    testCopy();
    testPos();
}

int main() {
    test();
    
    return 0;
}