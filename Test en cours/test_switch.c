#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int note=atoi(argv[1]);
    //printf("Quelle note-as-tu obyenue(sur cinq) ? ");
   // scanf("%d", &note);
    switch(note){
        /*Si note==0*/
        case 0:
        printf("No comment.\n");
        break;
        /*Si note==1*/
        case 1:
        printf("Cela te fait 4/20, c'est accablant.\n");
        break;
        /*Si note==2*/
        case 2:
        printf("On se rapproche de la moyenne, mais c'est pas encore ca.\n");
        break;
        /*Si note==3*/
        case 3:
        printf("Tu passes.\n");
        break;
        /*Si note==4*/
        case 4:
        printf("Bon travail, continue ainsi!\n");
        break;
        /*Si note==5*/
        case 5:
        printf("Excellent!\n");
        break;
        /*Si note est différente de 0, 1, 2, 3, 4 et 5*/
        default:
        printf("Euh... tu possèdes une note improbable...\n\n");
        break;
    }
    return 0;
}
