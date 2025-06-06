#include <string.h>
#include <assert.h>
#include "controller.h"
#include "validator.h"

void test_validate_option()
{
    //Functia  void test_validate_option() e folosita pentru a testa functia validate_option cu assert;
    assert(validate_option("3", 1, 5) == 1);
    assert(validate_option("5", 1, 9) == 1);
    assert(validate_option("-2", 1, 9) == 0);
    assert(validate_option("15", 1, 5) == 0);
}

int validate_option(char *optiune, int st, int dr)
{
    if(check_number_string(optiune))
    {
        int option=transform_chars_to_integer(optiune);
        return option >= st && option <= dr;
    }
    return 0;
}

void test_check_number()
{
    //Functia  void test_check_number() e folosita pentru a testa functia check_number cu assert;
    assert(check_number('3')==1);
    assert(check_number('5')==1);
    assert(check_number('a')==0);
}

int check_number(char ch)
{
    return ch >= '0' && ch <= '9';
}

void test_count_sep()
{
    //Functia  void test_count_sep() e folosita pentru a testa functia count_sep() cu assert;
    assert(count_sep("a,b,c,")==3);
    assert(count_sep("a,b,c")==2);
    assert(count_sep("a b c")==0);
    assert(count_sep("a b c,")==1);
}

int count_sep(const char* string)
{
    int cnt = 0;
    for (int i = 0; string[i] != '\0'; i++)
        if (string[i] == ',')
            cnt++;
    return cnt;
}

void test_check_ok_adress()
{
    //Functia test_check_ok_adress e folosita pentru a testa functia check_ok_adress cu assert;
    assert(check_ok_adress("Sibiu,str.Luncii,nr.12")==1);
    assert(check_ok_adress("Sibiu,str.Lunciinr.12")==-1);
    assert(check_ok_adress("Sibiu,str.Luncii,nr.")==0);
}

int check_ok_adress(const char* string)
{
    if (count_sep(string) < 2)
        return -1;
    int ok = 0;
    for (int i = 0; string[i] != '\0'; i++)
        if (check_number(string[i]))
            ok = 1;
    return ok;
}

void test_check_equ_string()
{
    //Functia test_check_equ_string() e folosita pentru a testa functia check_equ_string() cu assert;
    assert(check_equ_string("abcd", "abcd")==1);
    assert(check_equ_string("abcd", " abcd")==0);
    assert(check_equ_string("2abcd", "2abce")==0);
}

int check_equ_string(const char* string1, const char* string2)
{
    if (strlen(string1) != strlen(string2))
        return 0;
    for (int i = 0; i < strlen(string1); i++)
        if (string1[i] != string2[i])
            return 0;
    return 1;
}


void test_check_ok_string()
{
    //Functia test_check_ok_string() e folosita pentru a testa functia check_ok_string() cu assert;
    assert(check_ok_string("Ok ")==0);
    assert(check_ok_string("OK")==1);
    assert(check_ok_string("0K")==0);
}

int check_ok_string(const char* string)
{
    if (strlen(string) != 2)
        return 0;
    if (string[0] != 'O')
        return 0;
    if (string[1] != 'K')
        return 0;
    return 1;
}

void test_check_number_string()
{
    //Functia test_check_ok_string() e folosita pentru a testa functia check_ok_string() cu assert;
    assert(check_number_string("123z")==0);
    assert(check_number_string("0123")==1);
    assert(check_number_string("12k3")==0);
}

int check_number_string(const char* string)
{
    
    for (int i = 0; i < strlen(string); i++)
        if (!check_number(string[i]))
            return 0;
    return 1;
}

void test_validation()
{
    test_validate_option();
    test_check_number();
    test_count_sep();
    test_check_ok_adress();
    test_check_equ_string();
    test_check_ok_string();
    test_check_number_string();
}