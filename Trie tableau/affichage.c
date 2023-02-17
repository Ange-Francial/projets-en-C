#include <stdio.h>
#include <stdlib.h>

void affichage(int iTab[], int n){
    int i;
    printf("Le tableau trié est : { %d ",iTab[0]);
    for (i = 1; i < n; i++)
        printf(", %d ",iTab[i]);
    printf("}\n\nFin du programme.\n");
}