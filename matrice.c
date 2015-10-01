#include <stdio.h>

int main(void) {
	float tab[3];
	tab[0] = 0.1;
	 tab[1] = 0.01;
	 tab[2] = 0.001;
	 
	 int matrice[3][2];
	 matrice[2][1] = 4;
	 printf("matrice(2,1)=%d\n",matrice[2][1]);
	 
	 /* non défini ! */
	 printf("matrice(1,1)=%d\n",matrice[1][1]);
}
