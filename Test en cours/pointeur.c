#include <stdio.h>
#include <stdlib.h>
#define N 5

void main(){
    int i=0;
    char tab[N]={'a','b', 'c','d', 'e'};
    char *ptr;
    ptr = &tab[0];
    for(i=0;i<N; i++){
        printf("%c est à l'adresse % d\n", *ptr, ptr);
        ptr++;
    }
    printf("%d\n", sizeof(tab));
}