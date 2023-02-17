#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void main()
{
    FILE *fp;
    char cCar;
    char nom[20];
    char prenom[20];
    int note;

    fp=fopen("francial.txt","w");
    if (fp == NULL)
        printf("Impossible d'ouvrir le fichier en ecriture\n");
    
    while(1){

        // Saisie par l'utilisateur
        printf("Entrer le nom : ");
        scanf("%20s", nom); //[^\n]
        if(strcmp(nom,"quit")==0)
            break;
        printf("Entrer le prénom : ");
        scanf("%25s", prenom); //[^\n]
        printf("Entrer la note : ");
        scanf("%d", &note); //[^\n]

        if(strcmp(nom,"quit")==0)
            break;
        fprintf(fp,"\n%s\t\t\t::\t%s\t\t\t::\t%d",nom, prenom, note);
    }     
    // while(1)
    // {
    //     cCar=fgetc(fp);
    //     if(cCar==EOF)
    //         break;
    //     printf("%c",cCar); // ecrire cCar sur l'écran
    //         //putc(cCar,fp;) //
    // }

    printf("Fin de programme\n");
   // fprintf(fp,"Fin de programme\n");
    fclose(fp);
    
    // Affichage du fichier

    fp=fopen("francial.txt","r");
        char c;
    while(!feof(fp)){
        c=fgetc(fp);
        printf("%c",c);
    }
    fclose(fp);
    // f=fopen("test.txt","rt");
    // while((cCar=fgetc(f))!=EOF){
    //      printf("%c",c);
    // }
    // fclose(f);

}