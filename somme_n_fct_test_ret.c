#include <stdio.h>


int somme(int nb, char **tab, int *ptr)
{
	int i;
	
	*ptr=0;
	
	for( i=1; i < nb; i++)
		{
			if ( atoi(tab[i]) == 0 && tab[i][0] != 48)
				{
					printf("- L'argument %d n'est pas un entier\n", i);
					return 1;
				}
			
			*ptr = *ptr + atoi( tab[i] );
		}

	return 0;
}


int main(int argc, char **argv)
{
	int res;
	int *p_int;
	
	if( argc == 1 ) 
		{
			printf("- Usage : %s nombre nombre...\n", argv[0]);
			return 1;
		}

	if ( somme(argc, argv, &res) != 0 )
		{
			printf("- Erreur dans la somme, utiliser des entiers\n");
			return 1;
		}
	
	printf("somme = %d\n", res );
	
	printf("\n");
	return 0;
	
}

