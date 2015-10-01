#include <stdio.h>


int somme(int nb, char **tab)
{
	int i, res=0;
	
	for( i=1; i < nb; i++)
		{
			res = res + atoi( tab[i] );
		}

	return res;
	
}


int main(int argc, char **argv)
{
	if( argc == 1 ) 
		{
			printf("\n Usage : %s nombre nombre...\n", argv[0]);
			return 1;
		}

	printf("\n somme = %d", somme(argc, argv) );
	
	printf("\n\n");
	return 0;
	
}

