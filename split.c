#include<stdio.h>
#include<stdlib.h>

int main(){
    char *a = (char *)malloc(0x418);
    char *b = (char *)malloc(0x18);     // topと統合しないように
    free(a);

    char *c = (char *)malloc(0x18);
}