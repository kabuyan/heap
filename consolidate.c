#include<stdio.h>
#include<stdlib.h>

int main(){
    char *a = (char *)malloc(0x418);
    char *b = (char *)malloc(0x418);
    char *c = (char *)malloc(0x418);
    free(b);
    free(a);
    free(c);
}