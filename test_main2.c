#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
void test_rand();
void test_multidimensional_array();
void test_strncpy();
void test_strcat();
void test_strncat();
void test_strcmp();
void test_strncmp();
void test_strchr();
void test_strstr();
void test_strtok();
void test_analyzing();
void toupperWithTolower();
void test_atox();

int main()
{
    // test_rand();
    // test_strcat();
    // test_strncpy();
    // test_strncat();
    // test_strcmp();
    // test_strncmp();
    // test_strchr();
    // test_strstr();
    // test_strtok();
    // test_analyzing();
    // toupperWithTolower();
    test_atox();
}

void test_rand()
{
    time_t t;
    srand((unsigned)time(&t));
    int randomNumber = rand() % 21;
    printf("test %d", randomNumber);
}

void test_multidimensional_array()
{
    //外層2、中層3、內層4
    int array[2][3][4] = {
        {{1, 2, 3, 4},
         {1, 2, 3, 4},
         {1, 2, 3, 4}},
        {{1, 2, 3, 4},
         {1, 2, 3, 4},
         {1, 2, 3, 4}}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                printf("i = %d, j = %d, k = %d\n", i, j, k);
            }
        }
    }
}

void test_strncpy()
{
    char src[40] = "Tes\0t info ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char dest[12];
    int destLen = 12;
    memset(dest, '\0', sizeof(dest));
    strncpy(dest, src, destLen);
    printf("src start\n");
    for (int i = 0; i < 40; i++)
    {
        printf("%d ", src[i]);
    }
    printf("dest start\n");
    for (int i = 0; i < destLen; i++)
    {
        printf("%d ", dest[i]);
    }
}

void test_strcat()
{
    char src[] = "This is Source.";
    char dest[] = "This is destination.";

    strcat(dest, src);
    printf("result %s", dest);
}

void test_strncat()
{
    char src[] = "This is Source.";
    char dest[] = "This is destination.";

    strncat(dest, src, 8);
    printf("result %s", dest);
}

void test_strcmp()
{
    printf("%d\n", strcmp("Apple", "Apple"));
    printf("%d\n", strcmp("Apple_Apple", "Apple_Banana"));
}

void test_strncmp()
{
    printf("%d\n", strncmp("Apple_Apple", "Apple_Banana", 6));
    printf("%d\n", strncmp("Apple_Apple", "Apple_Banana", 7));
}

void test_strchr()
{
    char str[] = "This a apple.";
    char ch = 'a';
    char *pGot_char = NULL;
    pGot_char = strchr(str, ch);
    printf("str = %s\npGot_char = %s\n", str, pGot_char);
    if (pGot_char == NULL)
    {
        printf("is NULL\n");
    }
}

void test_strstr()
{
    char str[] = "When do fresh strawberries come in?";
    char word[] = "fresh";
    char *pFound = NULL;
    pFound = strstr(str, word);
    printf("str = %s\npGot_char = %s\n", str, pFound);
    if (pFound == NULL)
    {
        printf("is NULL\n");
    }
}

void test_strtok()
{
    char str[100] = "my name is Sam - I am in my office - my breakfast eat hamburger - www.google.com";
    const char s[5] = "-";
    char *token;

    token = strtok(str, s);

    while (token != NULL)
    {
        printf("token = %s\n", token);
        token = strtok(NULL, s);
    }
}

void test_analyzing()
{
    // islower 是小寫
    // isupper 是大寫
    // isalpha 是大寫或小寫(不是數字或符號)
    // isalnum 是大寫或小寫或數字
    // iscntrl 是控制字符
    // isprint 能打印包含空白
    // isgraph 是空白以外的字符
    // isdigit 是數字
    // isxdigit 是16進制
    // isblank 是空白或\t
    // isspace 是空白或\n或\t或\v或\r或\f
    // ispunct 能打印，isspace與isalnum除外的字符

    
}

void toupperWithTolower() {
    char str[] = "Apple";
    printf("toupper %s\n", str);
    for (int i = 0; i < strlen(str); i++)
    {
        printf("%c", toupper(str[i]));
    }

    char str2[] = "Apple";
    printf("\ntolower %s\n", str2);
    for (int i = 0; i < strlen(str2); i++)
    {
        printf("%c", tolower(str[i]));
    }
}

void test_atox() {
    char string[] = "12a3.0";
    int convert = atoi(string);
    printf("show1 %d\n", convert);   

    char string2[] = "12.902K4123";
    float convertFloat = atof(string2);
    printf("show2 %f\n", convertFloat); 

    char string3[] = "12.902K4123";
    double convertDouble = atof(string3);
    printf("show3 %f\n", convertDouble); 

    char string4[] = "129.02K4123";
    long convertLong = atol(string4);
    printf("show4 %lu\n", convertLong); 
    
    char string5[] = "12902K4123";
    long long convertLongLong = atoll(string5);
    printf("show5 %lld\n", convertLongLong); 
}