#include <stdio.h>
#include <stdlib.h>
#include "saisie.h"
#include "trie.h"
#include "affichage.h"
#define n 4

int main(void)
{
    int iTab[n];
    saisie(iTab,n);
    trie(iTab,n);
    affichage(iTab,n);
    return EXIT_SUCCESS;
}