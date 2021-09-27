
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "Personnes.h"

void supprimer(Liste *liste)
{
	int test=0;
	Element *element=malloc(sizeof(Element));
    element=liste->premier;
	int idesup;
	printf("ide a supprimer :\n");
	scanf("%u",&idesup);
    if(liste->premier!=NULL && liste->premier->personne.identifiant!=idesup)
    {
        while(element->suivant!=NULL && element->suivant->personne.identifiant!=idesup)
        {
            element=element->suivant;
        }
        element->suivant=element->suivant->suivant;
        printf("la personne est bien supprimer\n");
    }
    else if(liste->premier!=NULL && liste->premier->personne.identifiant==idesup)
        liste->premier=liste->premier->suivant;
    else
        printf("L'identifiant n'existe pas");

    printf("pour supprimer une autre personne veuillez appuis sur (1) :\n");
    scanf("%d",&test);
  	if (test==1)
   	{
  		supprimer(liste);
   	}
} 

