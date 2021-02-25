#include<stdio.h>
#include<stdlib.h>

int main(){
    char *a[10] = {};

    for(int i=0; i<10; i++) a[i] = (char *)malloc(0x78);

    *(unsigned long *)(a[0]+0x8) = 0x471;

    free(a[0]+0x10);

    printf("main_arena: %p\n", *(void **)(a[0]+0x10)-0x60);
}