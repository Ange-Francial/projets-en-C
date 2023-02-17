#include <stdio.h>
#include <stdlib.h>

void trie(int iTab[], int n){
  int i,j,k;
  j=n;
    while(j>0){
        for (i=0; i < j-1; i++) {
            if (iTab[i]>iTab[i+1]){
                /* Permutation */
                k=iTab[i];
                iTab[i]=iTab[i+1];
                iTab[i+1]=k;
            }
        }
        j--;
    }

}