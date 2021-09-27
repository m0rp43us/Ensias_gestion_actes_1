
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "Enfant.h"
Element* chercher_enfants(Liste *liste,int ide);
void afficher_enfants(int ide,Liste *liste)
{
    int j;
    if (chercher_enfants(liste,ide)==NULL)
    {
        printf("la personne n'existe pas\n");
        exit(0);
    }
    else
    {   Personne p=chercher_enfants(liste,ide)->personne;
        for(j=0;j<p.nbr_d_enfant;j++)
        {
            printf("\n\nL'enfant :\n");
            chercher_enfants(liste,p.enfant_ide[j]);
        }
    }
}

Element* chercher_enfants(Liste *liste,int ide)
{
    Element *element=malloc(sizeof(Element));
    int test,i=0;
    element=liste->premier;
    while(element!=NULL&&(ide!=element->personne.identifiant) )
    {
        element=element->suivant;
    }
    if (element==NULL || ide!=element->personne.identifiant)
    {
        return NULL;
    }
    else
    {
        test=1;
        if (test==1)
        {
            printf("le nom est : %s\n",element->personne.pr_nom);
            printf("le prenom est : %s\n",element->personne.pr_prenom);
            printf("la date de naissance : \n");
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
            printf("le sexe est : \n");
            if (element->personne.sexe==0)
            {
                printf("Homme\n");
            }
            else
            {
                printf("Femme\n");
            }
            printf("le CIN est : %s\n",element->personne.CIN);
            printf("l'identifiant est : %d\n",element->personne.identifiant);
            printf("le nombre d'enfants est : %d\n",element->personne.nbr_d_enfant);
            if (element->personne.nbr_d_enfant!=0)
            {
                printf("les identifiant des enfants sont :\n");
            }
            for (i = 0; i < element->personne.nbr_d_enfant; ++i)
            {
                printf("   l'ide de l'enfant %d est : %d \n",(i+1),element->personne.enfant_ide[i]);
            }
        }
    }
    return element;
}
