#include <stdio.h>
#include <string.h>
	
int main(void)
{
	char nom[16];
	int i;
	
	strcpy(nom,"Ducourthial");
	

	for(i=0;i<16;i++)
		{
			printf("nom[%d]=%c \t %d \n",i,nom[i],nom[i]);
		}

	printf("nom=%s\n", nom);
	
}
