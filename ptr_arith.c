#include <stdio.h>

/* Compilation : gcc forptr.c -o forptr -std=c99
	 cf. for (int i... */

int main(void)
{
	/* Declaration de 3 tableaux de types differents, necessitant une place
		 memoire differente. */
	int tabint[20];
	double tabdouble[20];
	char tabchar[20];

	/* Initialisation des tableaux */
	for (int i=0; i<20; i++) {
		tabint[i]=i*i;
		tabchar[i]=65+i;
		tabdouble[i]=(double)(i+2)/(i+1);	/* comparer avec tabdouble[i]=(i+2)/(i+1); */
	}

	/* Affichage de qq valeurs dans le tableau de INT et de leurs adresses.
		 Remarquer le nombre d'octets par case du tableau. */
	printf("&tabint[5] = %lu, tabint[5] = %d\n",
				 (unsigned long int)&tabint[5], tabint[5]);
	printf("&tabint[6] = %lu, tabint[6] = %d\n",
				 (unsigned long int)&tabint[6], tabint[6]);
	printf("&tabint[7] = %lu, tabint[7] = %d\n",
				 (unsigned long int)&tabint[7], tabint[7]);
	/* Utilisation de l'arithmétique sur les pointeurs pour accéder la case
		 suivante. */
	printf("*(&tabint[5]+1) = %d\n", *(&tabint[5]+1));
	printf("*(&tabint[5]+2) = %d\n\n", *(&tabint[5]+2));


	/* Affichage de qq valeurs dans le tableau de CHAR et de leurs adresses.
		 Remarquer le nombre d'octets par case du tableau. */
	printf("&tabchar[5] = %lu, tabchar[5] = %c, tabchar[5] = %d\n",
				 (unsigned long int)&tabchar[5], tabchar[5], tabchar[5]);
	printf("&tabchar[6] = %lu, tabchar[6] = %c, tabchar[6] = %d\n",
				 (unsigned long int)&tabchar[6], tabchar[6], tabchar[6]);
	printf("&tabchar[7] = %lu, tabchar[7] = %c, tabchar[7] = %d\n",
				 (unsigned long int)&tabchar[7], tabchar[7], tabchar[7]);
	/* Utilisation de l'arithmétique sur les pointeurs pour accéder la case
		 suivante. */
	printf("*(&tabchar[5]+1) = %c\n", *(&tabchar[5]+1));
	printf("*(&tabchar[5]+2) = %c\n\n", *(&tabchar[5]+2));


	/* Affichage de qq valeurs dans le tableau de DOUBLE et de leurs adresses.
		 Remarquer le nombre d'octets par case du tableau. */
	printf("&tabdouble[5] = %lu, tabdouble[5] = %f\n",
				 (unsigned long int)&tabdouble[5], tabdouble[5]);
	printf("&tabdouble[6] = %lu, tabdouble[6] = %f\n",
				 (unsigned long int)&tabdouble[6], tabdouble[6]);
	printf("&tabdouble[7] = %lu, tabdouble[7] = %f\n",
				 (unsigned long int)&tabdouble[7], tabdouble[7]);
	/* Utilisation de l'arithmétique sur les pointeurs pour accéder la case
		 suivante. */
	printf("*(&tabdouble[5]+1) = %f\n", *(&tabdouble[5]+1));
	printf("*(&tabdouble[5]+2) = %f\n\n", *(&tabdouble[5]+2));

	return 0;
	
}
