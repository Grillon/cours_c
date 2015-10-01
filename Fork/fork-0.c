#include <stdio.h>

int main(int argc, char **argv)
{
	switch (argc)
		{
		case 1:
			printf("pas d'argument\n");
			break;
		case 2:
			printf("1 argument\n");
			break;
		case 3:
		case 4:
			printf("2 ou 3 arguments\n");
			break;
		default:
			printf("plus de 3 arguments\n");
		}
}
