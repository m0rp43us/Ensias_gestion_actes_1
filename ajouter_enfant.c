
#include <stdio.h>
#include <stdlib.h>
#include "Enfant.h"
#include "structures.h"
void modifier_enfants(Personne *personne)
{
	int nv_nbr;
	printf("entrer l'identifiant de l'enfant que tu veux ajouter :\n");
	scanf("%d",&nv_nbr);
    personne->enfant_ide[personne->nbr_d_enfant]=nv_nbr;
    personne->nbr_d_enfant+=1;
    
}
