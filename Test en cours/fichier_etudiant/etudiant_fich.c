#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct
{
    char nom[20];
    char prenom[20];
    char matiere[20];
    int note;
}Etudiant;

typedef FILE* classe_etud;


void saisirEtudiant(classe_etud c, int nombre){

    printf("\n________________________________________");
    printf("\n|                                       |");
    printf("\n|         SAISIE DES ETUDIANTS          |");
    printf("\n|_______________________________________|\n");

    int i=1; // il joue le rôle de compteur général.
    Etudiant e;

    while(i<=nombre)
    {   
        printf("\nEntrer les informations de l'étudiant %d.\n", i);
        printf("Nom : ");
        scanf("%20s", e.nom); //[^\n]
        printf("Prénom : ");
        scanf("%20s", e.prenom); //[^\n]
        printf("Matière : ");
        scanf("%20s", e.matiere); //[^\n]
        printf("Note : ");
        scanf("%d", &e.note); 

        fprintf(c,"\n Nom: %s;\t Prénom: %s;\t Matière: %s;\t Note: %d",e.nom, e.prenom, e.matiere, e.note);
        i++;
    
    }
}


void consulterEtudiant(classe_etud fp, char nom[]){
    char c;
    char line[256];
    int x=0;
    while(fgets(line, 80, fp) != NULL){
        if(strstr(line, nom)){ 
            x++;
            printf("%s",line);
        } 
    }
    if(x==0)
        printf("\nÉtudiant inexistant !!!\n");
}


void modifierEtudiant(classe_etud fp, char nom[]){
    char c;
    char line[256];
    Etudiant e;
    classe_etud temp;

    temp=fopen("temp.txt","w");//etudiants.txt
    int x=0; // verifie l'appartenance du nom au fichier
    while(fgets(line, 80, fp) != NULL){
        if(strstr(line, nom)){ // verifie si nom est dans line
            x++;
            printf("\n\t Les anciennes informations de l'étudiant \"%s\" sont : \n",nom);
            printf("%s",line);
        }
        else{ 
            fprintf(temp,"%s",line);
        }
    }
    if(x==0)
        printf("\nÉtudiant inexistant !!!\n");
    else{
            printf("\n\t Veuillez saisir les nouvelles informations cet étudiant");
            printf("\n\t Nouveau nom : ");
            scanf("%s", e.nom);
            printf("\t Nouveau prénom : ");
            scanf("%s", e.prenom);
            printf("\t Nouvelle Matière : ");
            scanf("%s", e.matiere);
            printf("\t Nouvelle Note : ");
            scanf("%d",&e.note);
            fprintf(temp,"\n Nom: %s;\t Prénom: %s;\t Matière: %s;\t Note: %d",e.nom, e.prenom, e.matiere, e.note);
    }
    fclose(temp);
    
}



void supprimerEtudiant(classe_etud fp, char nom[]){
    char c;
    char line[256];
    Etudiant e;
    classe_etud temp;

    temp=fopen("temp.txt","w");
    int x=0; // verifie l'appartenance du nom au fichier
    while(fgets(line, 80, fp) != NULL){
        if(strstr(line, nom)){ // verifie si nom est dans line
            x++;
            printf("Étudiant supprimé !!!");
        } 
        fprintf(temp,"%s",line);
    }
    if(x==0)
        printf("\nÉtudiant inexistant !!!\n");

    fclose(temp);
}

void afficherEtudiant(classe_etud fp){

    printf("\n________________________________________");
    printf("\n|                                       |");
    printf("\n|        AFFICHAGE DES ETUDIANTS        |");
    printf("\n|_______________________________________|\n");

    int i=1;
    char c;

    while(!feof(fp)){
        c=fgetc(fp);
        if(c=='\n'){
            printf("\n Affichage de l'etudiant %d.", i);
            printf("%c\t",c);
            i++;
        }
        else{
            if(c==';'){
                printf("\n");
                c=' ';
            }
            printf("%c",c);
        }
    }
    
}



int main()
{
    unsigned short int choix;
    int nombre;
    char nom[20];
    classe_etud fp;
    // fp=fopen("Liste etudiant.txt","a");
    // if (fp == NULL)
    //     printf("Impossible d'ouvrir le fichier en ecriture\n");

    do {
        printf("\n\n\t\t\t***************************************************************");
        printf("\n\t\t\t****************** MENU DE GESTION D'ÉTUDIANT *****************");
        printf("\n\t\t\t***************************************************************\n\n");
        printf("\t\t\t1.  Ajout d'étudiant(s)\n");
        printf("\t\t\t2.  Suppression d'un étudiant\n");
        printf("\t\t\t3.  Consulter un étudiant\n");
        printf("\t\t\t4.  Modifier un étudiant\n");
        printf("\t\t\t5.  Afficher tous les étudiants\n");
        printf("\t\t\t6.  Fin\n\n");


        printf("\t\t\tSaisissez le numéro de votre choix : ");
        scanf("%ho", &choix);
        printf("\n");

        switch(choix){
            case(1) :
                        fp=fopen("etudiants.txt","a");
                        printf(" Entrer le nombre d'étudiants à ajouter : ");
                        scanf("%d", &nombre);
                        saisirEtudiant(fp, nombre);
                        fclose(fp);
                        break;
            case(2) :   
                        fp=fopen("etudiants.txt","a");
                        printf(" Entrer le nom de l'étudiant : ");
                        scanf("%s", nom);
                        supprimerEtudiant(fp,nom);
                        fclose(fp);
                        remove("etudiants.txt");
                        rename("temp.txt","etudiants.txt");
                        break;

            case(3) :
                        fp=fopen("etudiants.txt","r");
                        printf(" Entrer le nom de l'étudiant : ");
                        scanf("%s", nom);
                        consulterEtudiant(fp,nom);
                        fclose(fp);
                        break;

            case(4) :
                        fp=fopen("etudiants.txt","a");
                        printf(" Entrer le nom de l'étudiant : ");
                        scanf("%s", nom);
                        modifierEtudiant(fp,nom);
                        fclose(fp);
                        remove("etudiants.txt");
                        rename("temp.txt","etudiants.txt");
                        break;

            case(5) :   
                        fp=fopen("etudiants.txt","r");
                        afficherEtudiant(fp);
                        fclose(fp);
                        break;

            case(6) :   printf("Fin de la session. Merci !!!\n\n");
                        break;

            default :   printf("Veuillez entrer l'un des numéros ci-dessus !!!");
                        break;
        }
    
    }while(choix!=6);


}