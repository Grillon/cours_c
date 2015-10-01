#include <stdio.h>


int main(int argc, char **argv)
{
	int p, q;
	
	if( argc < 3 ) 
		{
			printf("\n Usage : %s nombre_1 nombre_2\n", argv[0]);
			return 1;
		}

	printf("\n argv[1] = %s, argv[2] = %s", argv[1], argv[2]);

	p = atoi(argv[1]);
	q = atoi(argv[2]);
	
	printf("\n p = %d, q = %d", p, q);
	printf("\n p + q = %d", p+q);
	
	
	printf("\n\n");
	return 0;
	
}

