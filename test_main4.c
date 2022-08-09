#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(int *const x, int *const y);
void test_passReferencePointer();
void test_malloc_alloc_realloc();

int main() {
    // test_passReferencePointer();
    test_malloc_alloc_realloc();
}

void test_passReferencePointer() {
    int x = 10, y = 30;
    printf("x = %d, y = %d\n", x, y);
    swap(&x, &y);
    printf("x = %d, y = %d", x, y);
}

void test_malloc_alloc_realloc() {
    char *str = (char *)malloc(15);
    strcpy(str, "123456");
    printf("String = %s, Address = %u\n", str, str);

    str = (char *) realloc(str, 25);
    strcat(str, ".com");
    printf("String = %s, Address = %u\n", str, str);

    free(str);
}

void swap(int *const x, int *const y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

