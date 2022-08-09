#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <assert.h> 
void test_assert();
void test_strlen();
void test_sprintf();
void test_snprintf();
void test_memcpy();
void test_strcpy();
bool setString(char* string, char* content, int len);

int main() {
    // test_assert();
    // test_strlen();
    // test_sprintf();
    // test_snprintf();
    test_memcpy();
    test_strcpy();
    return 0;
}

void test_assert() {
    char string[] = "123456789";
    assert(strlen(string) == 9);
    printf("OK1");
    assert(strlen(string) == 8);
    printf("OK2");
}

void test_strlen() {
    char string[] = "123456789";
    printf("strlen %d\n", strlen(string));
    string[5] = 0;
    printf("strlen %d", strlen(string));
}

void test_sprintf() {
    int len = 9;
    char *str = malloc(len * sizeof(char));
    memset(str, 0, sizeof(str));
    setString(str, "123456789", len);
    assert(strlen(str) > 0);
    printf("showA %s\n", str);

    memset(str, 0, sizeof(str)); 
    setString(str, "ABC", len);
    assert(strlen(str) == 3);
    printf("showB %s\n", str);
    free(str);
}

void test_snprintf() {
    char buffer[50];
    memset(buffer, 0, sizeof(char));
    int len = snprintf(buffer, 6, "123 %s", "ABC");
    printf("buffer %s, len = %d", buffer, len);
}

void test_memcpy() {
    char url[] = "http://\0google.com";
    char dest[20];
    int len = 20;
    memset(dest, 0, len);
    printf("start test_memcpy\n");
    memcpy(dest, url, len);
    for(int i=0;i<len;i++) {
        printf("%d ", dest[i]);
    }
    printf("\nend test_memcpy\n");
}

void test_strcpy() {
    char url[] = "http://\0google.com";
    char dest[20];
    int len = 20;
    memset(dest, 0, len);
    printf("start test_strcpy\n");
    strcpy(dest, url);
    for(int i=0;i<len;i++) {
        printf("%d ", dest[i]);
    }
    printf("\nend test_strcpy\n");
}

bool setString(char* string, char* content, int validLen) {
    int stringCount = strlen(string) + strlen(content);
    if(stringCount > validLen) {
        return false;
    }
    sprintf(string, content);
    return true;
}

//Code Runner 指令ctrl+alt+n