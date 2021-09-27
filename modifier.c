#include "structures.h"
#include "Personnes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void modifier(Liste *liste)
{
	int ide,test,i,nv_nbr;
	char nv_info[CMAX];
	printf("entrer l'identifient de la personne a modifier :\n");
	scanf("%d",&ide);
    Element *element=malloc(sizeof(Element));
    element=liste->premier;
	while( element!=NULL && element->personne.identifiant!=ide )
	{
		element=element->suivant;
	}
	if (element==NULL || ide!=element->personne.identifiant)
	{
		printf("l'element a modifier n'existe pas\n");
	}
	else
	{
		printf("l'element a modifier existe pour afficher ses info taper (1) :\n");
        scanf("%d",&test);
		if (test==1)
		{
			printf("le nom est : %s\n",element->personne.pr_nom);
			printf("le prenom est : %s\n",element->personne.pr_prenom);
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
			if (element->personne.sexe==0)
			{
				printf("Homme\n");
			}
			else{printf("Femme\n");}
			printf("le CIN est : %s\n",element->personne.CIN);
			printf("l'identifiant est : %d\n",element->personne.identifiant);
			printf("le nombre d'enfants est : %d\n",element->personne.nbr_d_enfant);
			if(element->personne.nbr_d_enfant!=0)
			{
				printf("les identifiant des enfant sont :\n");
			}
			for (i = 0; i < element->personne.nbr_d_enfant; ++i)
			{
				printf("   l'ide de l'enfant %d est : %d \n",(i+1),element->personne.enfant_ide[i]);
			}
		}
		test=0;
		printf("vous voulez modifier :\n(1)nom\n(2)le prenom\n(3)date de naissance\n(4)le sexe\n(5)CIN\n(6)le nombre d'enfant\n");
        scanf("%d",&test);
		switch(test)
		{
			case 1:
			{
				printf("entrer le nouveau nom :\n");
				scanf("%s",nv_info);
				strcpy(element->personne.pr_nom,nv_info);
				break;
			}
			case 2:
			{
				printf("entrer le nouveau prenom :\n");
				scanf("%s",nv_info);
				strcpy(element->personne.pr_prenom,nv_info);
				break;
			}
			case 3:
			{
				printf("entrer la nouvelle date de naissance\n");
				for (i = 0; i < 3; ++i)
				{
					switch(i+1)
					{
						case 1:
						{
							printf("    le jour :\n");
							break;
						}
						case 2:
						{
							printf("    le mois :\n");
							break;
						}
						case 3:
						{
							printf("    l'année :\n");
							break;
						}
					}
					scanf("%d",&element->personne.date_de_naissance[i]);
				}
				break;
			}
			case 4:
			{
				unsigned int nv_sexe;
				printf("entrer le nouveau sexe :\n");
				scanf("%u",&nv_sexe);
				element->personne.sexe=nv_sexe;
				break;
			}
			case 5:
			{
				printf("entrer le nouveau CIN :\n");
				scanf("%s",nv_info);
				strcpy(element->personne.CIN,nv_info);
				break;
			}
			case 6:
			{
				printf("entrer le nouveau nombre d'enfant :\n");
				scanf("%d",&nv_nbr);
				element->personne.nbr_d_enfant=nv_nbr;
			    element->personne.enfant_ide[0]=element->personne.identifiant+1;
   				for (i = 1; i <element->personne.nbr_d_enfant; i++)
    			{
        			element->personne.enfant_ide[i]=element->personne.enfant_ide[i-1]+1;
    			}
				break;
			}
		}
	}
	test=0;
	printf("pour modifier autre personne veuillez appuis sur (1):\n");
    scanf("%d",&test);
	if (test==1)
	{
		modifier(liste);
	}
	
}
