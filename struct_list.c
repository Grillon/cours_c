#include <stdio.h>
#include <string.h>


struct etudiant 
{
	char nom[16];
	char prenom[16];
	struct etudiant *suiv;
};

	
int print_list(struct etudiant *p_etu) 
{
	int i=0;
	
	while (p_etu != NULL)
		{
			printf("Etudiant %s %s\n", p_etu->prenom, (*p_etu).nom);
			p_etu = p_etu->suiv;
			i=i+1;
		}

	return i;
}

			
int main(void) {
	int n;
	struct etudiant e1, e2, e3;
	
	/* Initialisation des structures etudiant */
	strcpy(e1.nom, "Dupont");
	strcpy(e1.prenom, "Jerome");

	strcpy(e2.nom, "Tartampion");
	strcpy(e2.prenom, "Marie");

	strcpy(e3.nom, "Durant");
	strcpy(e3.prenom, "Alphonse");


	/* Chainage pour obtenir la liste e1 -> e2 -> e3 -> NULL. */
	e1.suiv = &e2;
	e2.suiv = &e3;
	e3.suiv = NULL;
	
	/* Affichage de la liste des etudiants. */
	n=print_list(&e1);
	printf("%d etudiants\n\n", n);

	/* Modification d'un element */
	strcpy(e1.prenom, "Jeremy");

	/* Reordonnancement de la liste */
	e1.suiv = &e3;
	e3.suiv = &e2;
	e2.suiv = NULL;
	
	n=print_list(&e1);
	printf("%d etudiants\n", n);
}
