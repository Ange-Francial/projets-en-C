#include <stdio.h>
#include <stdlib.h>
# define N 7

typedef int matrice[N][N];



void lire(matrice mat, int n){

    int i,j;

    for (i=0;i<n;i++){
        printf("ligne %d\n",i);
        for (j=0;j<n;j++)
                scanf("%d",&mat[i][j]);
    }

}
void binaire (int nombre, int tab[]){
    int decimal=nombre;
    for(int i=0; decimal > 0; i++)  
    {  
        tab[i] = decimal%2;  
        decimal = decimal/2;  
    }

}


int puissance(int a, int b){
    if(b==0)
        return 1;
    else
        return a*puissance(a,b-1);
}

int multiple_de_2(int nombre){
    if (nombre==1)
        return 1;
    else{
        for(int i=1; i<nombre; i++){
            if(puissance(2,i)>nombre)
                return 0;
            if(puissance(2,i)==nombre)
                return 1;
        }
    }
}

int parite (int nombre){
    if(nombre%2==0)
        return 1; // Paire
    else
        return 0; // Impair

}

// Afficher un tableau.
void affiche_tab(int tabl[]){
    for(int i=0; i<N-1; i++)
        printf(" %d ->", tabl[i]);
    printf("%d\n", tabl[N-1]);
}

int main (){

    int nombre;
    int tab[4], i;
    matrice Mconv;
    tab[0]=1; tab[1]=0; tab[2]=1; tab[3]=1;
    int conv[N];
    int t[N];
    // Variables de correction
    int indC[N];

    int org=0;
    for(i=0; i<4; i++){
        int j=org;
        while(multiple_de_2(j+1)==1 && j<N){
            t[j]=9540409;
            j++;
        }
        if(multiple_de_2(j+1)!=1){
                t[j]=tab[i];
                indC[i]=j+1;
        }
        org=j+1;
    }

    // Correction d'erreurs

    // convertion de position

    for(i=0; i<4; i++){
        binaire(indC[i], conv);
        for(int t=0; t<N; t++){
            printf("%d <><>", conv[t]);
        }
        printf("\n\n");
        for(int j=0; j<N; j++){
            Mconv[i][j] = conv[j];
            if(Mconv[i][j] != 1)
                Mconv[i][j]=0;
            //printf("%d ----", Mconv[i][j]);
        }
        //printf("\n");
    }
    for(i=4; i<N; i++){
        for(int j=0; j<N; j++){
            Mconv[i][j] = 0;
            //printf("%d ----", Mconv[i][j]);
        }
        //printf("\n");
    }

    //somme des ligne
    int j;
    int sommel[N];
    int res[N];
    // initialisation de sommel
    for(i=0; i<N; i++){
        sommel[i]=0;
    }
    // affectation des binaires correspondant.
    for(j=0; j<N; j++){
        for(i=0; i<N; i++){
           sommel[j]+=Mconv[i][j];
        }
        //printf("%d\n", sommel[j]);
        if(sommel[j]%2==0)
            res[j]= 0;
        else
            res[j]==1;
        
        //printf("%d\n", res[j]);
    }

    // for(i=0; i<4; i++){
    //     t[indC[i]-1]=res[i];
    // }


    affiche_tab(tab);
    affiche_tab(t);
    
    return 0;

}