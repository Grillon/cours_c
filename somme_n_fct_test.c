#include <stdio.h>


int somme(int nb, char **tab)
{
	int i, res=0;
	
	for( i=1; i < nb; i++)
		{
			if ( atoi(tab[i]) == 0 && tab[i][0] != 48)
				{
					printf("- L'argument numero %d n'est pas un entier\n", i);
				}
			
			res = res + atoi( tab[i] );
		}

	return res;
	
}


int main(int argc, char **argv)
{
	if( argc == 1 ) 
		{
			printf("- Usage : %s nombre nombre...\n", argv[0]);
			return 1;
		}

	printf("somme = %d\n", somme(argc, argv) );
	
	printf("\n");
	return 0;
	
}

