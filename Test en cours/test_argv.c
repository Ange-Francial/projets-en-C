#include <stdio.h>
#include <stdlib.h>

main (int argc, char *argv[]){
    printf("argc=%d\n", argc);
    printf("argv=%s\n", argv[1]);
    int a=atoi(argv[1]);
    printf("%d", a);
}
