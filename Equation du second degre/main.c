#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
	printf("********************************************\n");
	printf("***** Equation du second dégré dans R ******\n");
	printf("********************************************\n\n\n");
	
	float a, b, c, delta, x1, x2;
	printf("Entrez les valeurs de a, b et c correspondant à l'equation: ax²+bx+c \n");
	// Saisie des paramètres
	scanf("%f %f %f",&a,&b,&c);
	//Calcul du discriminant
	delta=b*b-4*a*c;
	
	printf("L'équation a résoudre est (%f)x²+(%f)x+(%f).\n",a,b,c);
	if(delta>0){
		x1=(-b-sqrt(delta))/(2*a);
		x2=(-b+sqrt(delta))/(2*a);
		printf("Cet équation admet 02 solutions distinctes dont les valeurs sont: %f et %f \n",x1,x2);
	}
	else   if(delta==0){
			x1=(-b)/(2*a);
			printf("Cet équation admet une solution double dont la valeur est: %f \n",x1);
		}
		else
			printf("Cette équation n'a pas de solution dans R !!!\n");
	return 0;
}
