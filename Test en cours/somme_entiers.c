#include <stdio.h>
#include <stdlib.h>

int calcul (int i, int s){
	for(int j=i; j<=5; j++)
		s+=j;
	return s;
}

int main(void) {
	int i=1;
	int s=0;
	s= calcul(i,s);
	printf("somme des entiers de 1 à 5\n");
	printf("somme = %d\n", s);
	exit(0);
}
