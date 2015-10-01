#include <stdio.h>


int main(int argc, char **argv)
{
	int i, res=0;
	
	
	if( argc == 1 ) 
		{
			printf("\n Usage : %s nombre nombre...\n", argv[0]);
			return 1;
		}


	for( i=1; i < argc; i++)
		{
			res = res + atoi( argv[i] );
		}

	printf("\n somme = %d", res);
	
	
	printf("\n\n");
	return 0;
	
}

