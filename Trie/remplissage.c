#include <stdio.h>
#include <stdlib.h>


void main(){
  int iTab[4],i;
  //remplisage;
  for(i=0;i<4;i++){
    printf("iTab[%d] = ",i);
    scanf("%d",&iTab[i]);
  }

  printf("Le tableau passé en paramètre est : { ");
  for (i = 0; i < 4; i++)
    printf("%d, ",iTab[i]);
  printf("}\n");
  
  //Trie
  int j,k;
  j=sizeof(iTab)/sizeof(iTab[0]); // Taille du tableau
  printf("%d\n",j);
  while(j>0){

    for (i=0; i < j-1; i++) {
      if (iTab[i]>iTab[i+1]){
        k=iTab[i];
        iTab[i]=iTab[i+1];
        iTab[i+1]=k;
      }
    }
    j--;
  }

  //affiche

  printf("Le tableau trié est : { %d",iTab[0]);
  for (i = 1; i < 4; i++)
    printf(", %d ",iTab[i]);
  printf("}\n Fin du programme.\n");

}
