#include <stdio.h>

int main(void)
{
	float f=3.14;
	int i=5;

	printf("float = %ld octets \n", sizeof(f));
	printf("int = %ld octets \n", sizeof(i));
	printf("double = %ld octets \n", sizeof(double));
}
