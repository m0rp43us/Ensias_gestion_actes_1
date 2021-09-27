

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "structures.h"
#include "Enfant.h"
#include "Personnes.h"


void menu_enfants(Liste *liste)
{
	int i,ide;
    liste=lire();
  	Element *element=malloc(sizeof(Element));
  	do
  	{
      	printf("\n*******************************************************************");
        printf("\n*                                                                 *");
        printf("\n*             voulez-vous :                                       *");
        printf("\n*   1 : Afficher les informations sur les enfants d’une personne  *");
        printf("\n*   2 : Ajouter les enfants d’une personne                        *");
        printf("\n*   0 : sortir                                                    *");
        printf("\n*******************************************************************");
        printf("\nvotre choix :");
        scanf("%d",&i);
        switch(i)
        {
        	case 0:
        	{
        		enregistrer(liste);
        		break;
        	}
        	case 1:
        	{
                printf("dans l'id du parent :");
                scanf("%d",&ide);
        		afficher_enfants(ide,liste);
        		break;
        	}
        	case 2:
        	{
        		element=chercher_ide(liste);
                if (element==NULL)
                {
                    printf("la personne n'existe pas\n");
                }
                else
        		{modifier_enfants(&(element->personne));}
        		break;
        	}
        }
  	} while (i!=0);
}
