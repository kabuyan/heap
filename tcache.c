#include<stdio.h>
#include<stdlib.h>

int main(){
    char *a = (char *)malloc(0x18);
    char *b = (char *)malloc(0x18);
    free(a);
    free(b);
}