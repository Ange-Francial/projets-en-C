#include <stdio.h>


  // int iCar;
  //
  // iCar=getchar();
  // while (iCar!=EOF) {
  //   printf("Le caractère %c à le code ASCII %d\n",iCar,iCar);
  //   iCar=getchar();
  // }
  // printf("Fin du programme.\n");


  // int iCar;
  //
  // while (1) {
  //   iCar=getchar();
  //   if(iCar!=EOF)
  //     break;
  //   printf("Le code ASCII du caractère \'%c\' : %d\n",iCar,iCar);
  // }
  // printf("Fin du programme.\n");


  // int iTab[4], iSomme,i;
  //
  //   iTab[0]= 1;
  //   iTab[1]= 10;
  //   iTab[2]= 100;
  //   iTab[3]= 1000;
  //   iSomme=0; i=0;
  //   printf("La somme de %d",iSomme);
  //   while (i<4) {
  //     iSomme+=iTab[i];
  //     printf("+%d",iTab[i]);
  //     i++;
  //   }
  //   printf("= %d\n",iSomme );
  //   printf("Fin du programme.\n");


  int puissance(int x, int n){
    if(n=0)
      return 1;
    else
      return x*puissance(x,n-1);
  }

  void remplirTab(int Tab[][],int n){
    int i,j;
    for(i=0;i<n;i++)
      for(j=0;i<n;i++)
        Tab[i][j]=puissance(10,j);
  }

  int main()
  {

  int iTab[4][4], iSomme,i,j;

    remplirTab(iTab, 4);
    iSomme=0; i=0;
    printf("La somme de %d",iSomme);
    while (i<4) {
      while (j<4) {
        iSomme+=iTab[i][j];
        printf("+%d",iTab[i][j]);
        j++;
      }
      i++;
    }
    printf("= %d\n",iSomme );
    printf("Fin du programme.\n");

    return 0;
}
