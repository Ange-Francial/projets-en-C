#include <stdio.h>
#include <stdlib.h>

void saisie(int iTab[], int n){
    int i;
    printf("Entrer les valeurs de votre tableau :\n");
    for(i=0;i<n;i++){
        printf(" iTab[%d] = ",i);
        scanf("%d",&iTab[i]);
    }
}