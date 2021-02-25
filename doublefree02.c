#include<stdio.h>
#include<stdlib.h>

int main(){
    char *p[10] = {};
    for(int i=0; i<7; i++) p[i] = (char *)malloc(0x18);

    int k;
    printf("k: %p\n", &k);

    char *a = (char *)malloc(0x18);
    char *b = (char *)malloc(0x18);
    printf("a: %p\n", a);
    printf("b: %p\n", b);

    for(int i=0; i<7; i++) free(p[i]);  // tcacheを埋める

    free(a);
    free(b);
    free(a);    // Double Free

    for(int i=0; i<7; i++) p[i] = (char *)malloc(0x18);     // tcacheから確保

    char *c = (char *)malloc(0x18);     // fastbinから確保
    printf("c: %p\n", c);

    *(unsigned long *)c = (unsigned long)&k;

    char *d = (char *)malloc(0x18);
    char *e = (char *)malloc(0x18);
    char *f = (char *)malloc(0x18);
    printf("d: %p\n", d);
    printf("e: %p\n", e);
    printf("f: %p\n", f);
}