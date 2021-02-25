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

    // Use After Free
    *(unsigned long *)a = (unsigned long)&k;

    char *c = (char *)malloc(0x18);
    char *d = (char *)malloc(0x18);
    printf("c: %p\n", c);
    printf("d: %p\n", d);
}