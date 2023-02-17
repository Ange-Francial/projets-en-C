#include <stdio.h>
#include <stdlib.h>

int table(int a){
    int produit, facteur=0;
    while(facteur<10)
    {
        produit=a*(++facteur);
        printf("%i fois %i egale %i\n" , a, facteur, produit);
    }
    return 0;
}

void main(int argc, char *argv[]){
    int a=atoi(argv[1]); // permet de caster le caractère de argv[1]
    printf("%d",table (a));
}
