#include "structures.h"
#include "Personnes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Element* chercher_ide(Liste *liste)
{
	Element *element=malloc(sizeof(Element));
	int ide,test,i;
	printf("entrer l'identifiant de la personne rechercher :\n");
	scanf("%d",&ide);
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
		printf("l'element rechercher existe pour afficher ses info taper (1) :\n");
        scanf("%d",&test);
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
				printf("les identifiant des enfant sont :\n");
			}
			for (i = 0; i < element->personne.nbr_d_enfant; ++i)
			{
				printf("   l'ide de l'enfant %d est : %d \n",(i+1),element->personne.enfant_ide[i]);
			}
		}
	}
	return element;
}

Element* chercher_CIN(Liste *liste)
{
	int test,i;
    char C[CMAX];
	printf("entrer le CIN de la personne rechercher :\n");
	scanf("%s",C);
    Element *element=malloc(sizeof(Element));
    element=liste->premier;;
	while(element!=NULL && (strcmp(C,element->personne.CIN))!=0)
	{
		element=element->suivant;
	}
	if (element==NULL || (strcmp(C,element->personne.CIN))!=0)
	{
        return NULL;
	}
	else
	{
		printf("l'element rechercher existe pour afficher ses info taper (1) :\n");
        scanf("%d",&test);
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
			printf("l'identifiant de la personne est : %d\n",element->personne.identifiant);
			printf("l'identifiant est : %d\n",element->personne.identifiant);
			printf("le nombre d'enfants est : %d\n",element->personne.nbr_d_enfant);
			if (element->personne.nbr_d_enfant!=0)
			{
				printf("les identifiant des enfant sont :\n");
			}
			for (i = 0; i < element->personne.nbr_d_enfant; ++i)
			{
				printf("   l'ide de l'enfant %d est : %d \n",(i+1),element->personne.enfant_ide[i]);
			}
		}
	}
	return element;
}

Element* chercher_nom(Liste *liste)
{
	Element *element=malloc(sizeof(Element));
	int test,i;
	char re_nom[CMAX];
	printf("entrer le nom de la personne rechercher :\n");
	scanf("%s",re_nom);
	element=liste->premier;
	do
	{
		while((element!=NULL) && strcmp(re_nom,element->personne.pr_nom)!=0)
		{
			element=element->suivant;
		}
		if (element==NULL || strcmp(re_nom,element->personne.pr_nom)!=0)
		{
            return NULL;
		}
		else
		{
			printf("la personne avec le nom rechercher est trouver ses info sont les suivants:\n");
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
			printf("l'identifiant de la personne est : %d\n",element->personne.identifiant);
			printf("l'identifiant est : %d\n",element->personne.identifiant);
			printf("le nombre d'enfants est : %d\n",element->personne.nbr_d_enfant);
			if (element->personne.nbr_d_enfant!=0)
			{
				printf("les identifiant des enfant sont :\n");
			}
			for (i = 0; i < element->personne.nbr_d_enfant; ++i)
			{
				printf("   l'ide de l'enfant %d est : %d \n",(i+1),element->personne.enfant_ide[i]);
			}
        }
		printf("si la personne ne correspond pas a ce que vous voulez veuillez appuiez sur (1) :\n");
		scanf("%d",&test);
	} while (test==1);
	return element;
}

Element* chercher_prenom(Liste *liste)
{
	Element *element=malloc(sizeof(Element));
	int test,i;
	char re_prenom[CMAX];
	printf("entrer le prenom de la personne rechercher :\n");
    fflush(stdin);
    scanf("%s",re_prenom);
    element=liste->premier;
	do
	{
		while(element!=NULL && strcmp(re_prenom,element->personne.pr_prenom)!=0)
		{
			element=element->suivant;
		}
		if (element==NULL || strcmp(re_prenom,element->personne.pr_prenom)!=0)
		{
			return NULL;
		}
		else
		{
			printf("la personne avec le prenom rechercher est trouver ses info sont les suivants:\n");
			printf("le nom est : %s\n",element->personne.pr_nom);
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
			printf("l'identifiant de la personne est : %d\n",element->personne.identifiant);
			printf("l'identifiant est : %d\n",element->personne.identifiant);
			printf("le nombre d'enfants est : %d\n",element->personne.nbr_d_enfant);
			if (element->personne.nbr_d_enfant!=0)
			{
				printf("les identifiant des enfant sont :\n");
			}
			for (i = 0; i < element->personne.nbr_d_enfant; ++i)
			{
				printf("   l'ide de l'enfant %d est : %d \n",(i+1),element->personne.enfant_ide[i]);
			}
            
        }
		printf("si la personne ne correspond pas a ce que vous voulez veuillez appuiez sur (1) :\n");
		scanf("%d",&test);
	}while (test==1);
	return element;
}
