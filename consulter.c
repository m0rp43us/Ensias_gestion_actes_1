#include "structures.h"
#include "Personnes.h"
#include <stdio.h>
#include <stdlib.h>
#include<sys/stat.h>

void consulter(Liste *liste)
{
    int i;
    Personne personne;
    Element *element=malloc(sizeof(*element));
    element=liste->premier;
    while(element!=NULL)
    {
        personne=element->personne;
        printf("le nom est : %s\n",personne.pr_nom);
        printf("le prenom est : %s\n",personne.pr_prenom);
        printf("la date de naissance :\n");
		for (i = 0; i < 3; ++i)
		{
			switch(i+1)
			{
				case 1:
				{
					printf("    le jour : %d\n",element->personne.date_de_naissance[i]);
					break;
				}
				case 2:
				{
					printf("    le mois : %d\n",element->personne.date_de_naissance[i]);
					break;
				}
				case 3:
				{
					printf("    l'année : %d\n",element->personne.date_de_naissance[i]);
					break;
				}
			}
		}
        printf("le sexe est :");
        if (personne.sexe==0)
        {
        	printf("Homme\n");
        }
        else
        {
        	printf("Femme\n");
        }
        printf("le CIN est : %s\n",personne.CIN);
        printf("l'identifiant est : %d\n",personne.identifiant);
        printf("le nombre d'enfants est : %d\n",personne.nbr_d_enfant);
        for (i = 0; i < personne.nbr_d_enfant; i++)
        {
            printf("   l'ide de l'enfant %d est : %d \n",i+1,personne.enfant_ide[i]);
        }
        printf("\n");
        
        element=element->suivant;
    } 
}
