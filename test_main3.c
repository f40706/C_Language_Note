#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
void test_strtod();
void test_strtold();
void test_strtof();
void test_pointerNotice();
void test_pointerWithConst();
void test_pointerVoid();
void test_pointerOffset();
void test_pointerAdd();
void test_arraySizeof();
void string_copy(char *from, char *to);
int string_length(const char *string);
void test_pointerStringCopy();

int main()
{
    // test_strtold();
    // test_strtod();
    // test_strtof();

    // test_pointerNotice();
    // test_pointWithConst();
    // test_pointerVoid();
    // test_pointerOffset();
    // test_pointerAdd();
    // test_arraySizeof();
    test_pointerStringCopy();
}

void test_strtold()
{
    char str[] = "13.995032 This is Number. ";
    char *ptr;
    double number;
    number = strtod(str, &ptr);

    printf("string %s\nlong double %lf\n", ptr, number);
}

void test_strtod()
{
    char str[] = "13.995032 This is Number. ";
    char *ptr;
    double number;
    number = strtod(str, &ptr);

    printf("string %s\ndouble %lf\n", ptr, number);
}

void test_strtof()
{
    char str[] = "13.995032 This is Number. ";
    char *ptr;
    double number;
    number = strtof(str, &ptr);

    printf("string %s\nfloat %f\n", ptr, number);
}

void test_pointerNotice()
{
    //指標小心越界
    char a[9] = "12345678";
    char *test = NULL;
    test = &a[0];
    test[1] = 'a'; //此處的[]可以改成超出範圍，使用應注意不要超出
    printf("%s\n", a);
    printf("%s", test);

    //不能取消、引用他，僅能訪問
    //導致記憶體洩漏
    // char *pstr = "1234567"; //錯誤的用法，沒有創建內存給他
    char *pstr = NULL; //正確用法，應該初始化給予NULL
}

void test_pointerWithConst()
{
    //禁止改指標內的位置，可以改指鰾指向的數值
    int temp = 10;
    int item = 25;
    int *const pItem = &item;
    *pItem = 20; // ok
    // pItem = &temp;  //error
    printf("%d\n", *pItem); // 20

    //可以改指標內的位置，禁止改指鰾指向的數值
    int temp2 = 10;
    int item2 = 25;
    const int *pItem2 = &item2;
    // *pItem2 = 20;//error
    pItem2 = &temp2;         // ok
    printf("%d\n", *pItem2); // 10

    //禁止改指標內的位置，禁止改指鰾指向的數值
    int temp3 = 10;
    int item3 = 25;
    const int *const pItem3 = &item3;
    // *pItem3 = 20;//error
    // pItem3 = &temp3;  //error
    printf("%d\n", *pItem3); // 25

    //可以改指標內的位置，可以改指鰾指向的數值
    int temp4 = 10;
    int item4 = 25;
    int *pItem4 = &item4;
    *pItem4 = 20;            // ok
    pItem4 = &temp4;         // ok
    printf("%d\n", *pItem4); // 10
}

void test_pointerVoid() {
    int i = 10;
    float j = 20.3;
    char k = 'U';

    void *pVoid;

    pVoid = &i;
    printf("%d\n", *(int *)pVoid);

    pVoid = &j;
    printf("%.2f\n", *(float *)pVoid);
    
    pVoid = &k;
    printf("%c\n", *(char *)pVoid);
}

void test_pointerOffset() {
    int values[] = {2, 4, 6, 8};
    int *pValues = values;

    printf("show1 = %d\n", values[2]);
    printf("show2 = %d\n", *(pValues + 2));

    *(pValues + 2) = 9;
    printf("show3 = %d\n", values[2]);
    printf("show4 = %d\n", *(pValues + 2));

    values[2] = 21;
    printf("show5 = %d\n", values[2]);
    printf("show6 = %d\n", *(pValues + 2));
}

int sumArray(int array[], const int count) {
    int sum = 0;
    int *ptr;
    int const* arrayEnd = array + count;
    for(ptr = array; ptr < arrayEnd; ptr++) {
        sum += *ptr;
    }
    return sum;
}

void test_pointer_add() {
    int sumArray(int array[], const int count);
    int array[] = {1, 33, 2, 20, -5, -23, 3, 13, 20, 8, -2};

    printf("number %d", sumArray(array, 11));
}

void test_arraySizeof() {
    int array[] = {20L, 30L, 40L};
    printf("sizeof -> array[0] = %zu, array = %zu", sizeof(array[0]), sizeof(array));
}

void string_copy(char *from, char *to) {
    while (*from) {
        *to++ = *from++;
    }
    *to = '\0';
}

int string_length(const char *string) {
    const char *last = string;
    while(*last) 
        last++;
    printf("string length %d\n", last - string);
    return last - string;
}

void test_pointerStringCopy() {
    char array[] = "A12345678";
    char ptr[9];
    int len = 9;//len = ptr長度
    //確保len大於array，避免越區
    assert(len >= string_length(array));
    string_copy(array, ptr);
    printf("ptr = %s", ptr);
}

