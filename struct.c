#include <stdio.h>
#include <string.h>

typedef struct {
	char nom[16];
	char prenom[16];
} Personne;

int main(void) {

	struct 
	{
		char nom[16];
		char prenom[16];
	} boucher, boulanger;

	Personne Ecr1, Ecr2;
	
	strcpy(boucher.nom, "Dupont");
	strcpy(boulanger.nom, "Durant");
	printf("boucher = %s, boulanger = %s\n", boucher.nom, boulanger.nom);
	
	
	strcpy(Ecr1.nom, "Hugo");
	strcpy(Ecr1.prenom, "Victor");
	printf("ecrivain 1 : %s %s\n", Ecr1.prenom, Ecr1.nom);

	strcpy(Ecr2.nom, "Jules");
	strcpy(Ecr2.prenom, "Vernes");
	printf("ecrivain 2 : %s %s\n", Ecr2.prenom, Ecr2.nom);
}
