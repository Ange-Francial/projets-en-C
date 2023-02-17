#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ELEMENTS 5

typedef struct
{
    char nom[20];
    char prenom[20];
    char matiere[20];
    int note;
}Etudiant;


void saisirEtudiant(Etudiant e[], int nombre){
    printf("\n________________________________________");
    printf("\n|                                       |");
    printf("\n|         SAISIE DES ETUDIANTS          |");
    printf("\n|_______________________________________|\n");

    int i=0; // il joue le rôle de compteur général.
    int n=0; // permet de savoir le nombre d'étudiants saisis.

    while(n<nombre)
    {   
        if(i==MAX_ELEMENTS){
            printf("Uniquement %d étudiants ont été saisis car le nombre maximum d'étudiants est atteint !!!\n", n);
            break;
        }
        else
        {
            if  ( strcmp(e[i].nom,"") == 0 && strcmp(e[i].prenom,"") == 0 
                    && strcmp(e[i].matiere,"") == 0 && e[i].note == 0)
            {
                printf("\n Entrer les informations de l'étudiant %d : \n", i+1);
                printf("\tNom : ");
                scanf("%s", e[i].nom);
                printf("\tPrenom : ");
                scanf("%s", e[i].prenom);
                printf("\tMatière : ");
                scanf("%s", e[i].matiere);
                printf("\tNote : ");
                scanf("%d", &e[i].note);
                n++;
            }
            i++;
        }
    }
}

void afficher(Etudiant e){
    printf("\tNom : %s\n",e.nom);
    printf("\tPrenom : %s\n", e.prenom);
    printf("\tMatière : %s\n", e.matiere);
    printf("\tNote : %d\n", e.note);
}

void consulterEtudiant(Etudiant e[], char nom[]){
    int test=0; // permet de savoir si l'étudiant existe
    for(int i=0; i<MAX_ELEMENTS;i++){
        if( strcmp(e[i].nom,nom) == 0 )
        {
            afficher(e[i]);
            test++;
        }
    }
    if(test==0)
        printf("Aucun étudiant n'a ce nom !!!\n");
}

void modifierEtudiant(Etudiant e[], char nom[]){
    int test=0; // permet de savoir si l'étudiant existe
    for(int i=0; i<MAX_ELEMENTS;i++){
        if( strcmp(e[i].nom,nom) == 0 )
        {
            printf("\n\t Les anciennes informations de l'étudiant \"%s\" sont : \n",nom);
            afficher(e[i]);
            printf("\n\t Veuillez saisir les nouvelles informations cet étudiant");
            printf("\n\t Nouveau nom : ");
            scanf("%s", e[i].nom);
            printf("\t Nouveau prénom : ");
            scanf("%s", e[i].prenom);
            printf("\t Nouvelle Matière : ");
            scanf("%s", e[i].matiere);
            printf("\t Nouvelle Note : ");
            scanf("%d",&e[i].note);
            test++;
            break;
        }
    }
    if(test==0)
        printf("Aucun étudiant n'a ce nom !!!\n");
}


void supprimerEtudiant(Etudiant e[], char nom[]){
    int test=0; // permet de savoir si l'étudiant existe
    for(int i=0; i<MAX_ELEMENTS;i++){
        if( strcmp(e[i].nom,nom) == 0 )
        {
            strcpy(e[i].nom,"");
            strcpy(e[i].prenom,"");
            strcpy(e[i].matiere,"");
            e[i].note=0;
            test++;
            break;
        }
    }
    if(test==0)
        printf("Aucun étudiant n'a ce nom !!!\n");
}



void afficherEtudiant(Etudiant e[]){

    printf("\n________________________________________");
    printf("\n|                                       |");
    printf("\n|        AFFICHAGE DES ETUDIANTS        |");
    printf("\n|_______________________________________|\n");

    for(int i=0; i<MAX_ELEMENTS;i++){
        if( strcmp(e[i].nom,"") != 0 && strcmp(e[i].prenom,"") != 0 &&
            strcmp(e[i].matiere,"") != 0 && e[i].note!= 0)
        {
            printf("\n Affichage de l'etudiant \"%s\"\n", e[i].nom);
            afficher(e[i]);
        }
    }
}



int main()
{
    unsigned short int choix;
    int nombre;
    char nom[20];
    Etudiant tab[MAX_ELEMENTS];

    // Initialisation du tableau
    for(int i=0; i<MAX_ELEMENTS; i++){
        strcpy(tab[i].nom,"");
        strcpy(tab[i].prenom,"");
        strcpy(tab[i].matiere,"");
        tab[i].note=0;
    }

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
                        printf(" Entrer le nombre d'étudiants à ajouter : ");
                        scanf("%d", &nombre);
                        saisirEtudiant(tab, nombre);
                        break;
            case(2) :   
                        printf(" Entrer le nom de l'étudiant : ");
                        scanf("%s", nom);
                        supprimerEtudiant(tab,nom);
                        break;

            case(3) :
                        printf(" Entrer le nom de l'étudiant : ");
                        scanf("%s", nom);
                        consulterEtudiant(tab,nom);
                        break;

            case(4) :
                        printf(" Entrer le nom de l'étudiant : ");
                        scanf("%s", nom);
                        modifierEtudiant(tab,nom);
                        break;

            case(5) :   
                        afficherEtudiant(tab);
                        break;

            case(6) :   printf("Fin de la session. Merci !!!\n\n");
                        break;

            default :   printf("Veuillez entrer l'un des numéros ci-dessus !!!");
                        break;
        }
    
    }while(choix!=6);


}