#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int puissance(int a, int b){
    if(b==0)
        return 1;
    else
        return a*puissance(a,b-1);

}

int factoriel(int a){
    if(a==0)
        return 1;
    else
        return a*factoriel(a-1);
}

int pgcd (int nbr1, int nbr2){
    int i, pgcd;
    for(i=1; i <= nbr1 && i <= nbr2; ++i)
    {
        if(nbr1%i==0 && nbr2%i==0)
            pgcd = i;
    }
    return pgcd;
}

int ppcm (int nbr1, int nbr2){
    int i, ppcm;
    ppcm = (nbr1 > nbr2) ? nbr1 : nbr2;
    // Toujours vrai
    while(1)
    {
        if( ppcm%nbr1==0 && ppcm%nbr2==0 )
        {
            return ppcm;
            break;
        }
        ++ppcm;
    }
}


void main(int argc, char *argv[]){
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    if (*argv[2]=='!' && argc==3)
        printf("%d\n", factoriel(a));
    else 
        switch (*argv[3]){
            case '+':
                printf("%d\n", a+b);
                break;
            case '-':
                printf("%d\n", a-b);
                break;
            case 'x':
                printf("%d\n", a*b);
                break;
            case '/':
                printf("%d\n", a/b);
                break;
            case '%':
                printf("%d\n", a%b);
                break;
            case '^':
                printf("%d\n", puissance(a,b));
                break;
            case 'd':
                printf("%d\n", pgcd(a,b));
                break;
            case 'm':
                printf("%d\n", ppcm(a,b));
                break;

            default:
                printf("erreur\n");
                break;

        }

}