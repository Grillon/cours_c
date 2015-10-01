#include <stdio.h>

int main(void)
{
	/* Declaration d'un entier et d'un pointeur sur entier */
	int num, *p_num;

	/* Initialisation de l'entier et du pointeur sur entier. */
	num = 5;
	p_num = &num; /* Adresse de l'entier num. */

	/* Affichage de l'entier et du pointeur, apres un "cast" dans le type
		 "unsigned long int" */
	printf("num = %d, p_num = %lu\n", num, (unsigned long int)p_num);

	/* Affectation d'une nouvelle valeur a l'emplacement pointe par p_num */
	*p_num = 6;

	/* C'est donc num qui a change de valeur. */
	printf("num = %d, p_num = %lu\n", num, (unsigned long int)p_num);


	return 0;
	
}
