
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include "Personnes.h"



void ajouter(Liste *liste)
{
    int test=0,i;
    do
    {
        int ide;
        Personne nv_personne;
        Element *nv_element=malloc(sizeof(*nv_element));
        printf("entrer le nom :\n");
        scanf("%s",nv_personne.pr_nom);
        printf("entrer le prenom :\n");
        scanf("%s",nv_personne.pr_prenom);
        printf("choisis ton sexe (0)Homme (1)Femme :\n");
        scanf("%u",&nv_personne.sexe);
        if (liste->premier==NULL) ide=1;
        else
            ide=liste->premier->personne.identifiant+1;
        nv_personne.identifiant=ide;
        printf("la date de naissance :\n");
        for (i = 0; i < 3; ++i)
        {
            switch(i)
            {
                case 0:
                {
                    printf("entrer le jour :\n");
                    break;
                }
                case 1:
                {
                    printf("entrer le mois :\n");
                    break;
                }
                case 2:
                {
                    printf("enter l'année :\n");
                    break;
                }
            }
            scanf("%d",&nv_personne.date_de_naissance[i]);
        }
        printf("entrer votre CIN :\n");
        scanf("%s",nv_personne.CIN);
        nv_personne.identifiant=ide;
        printf("entrer le nombre d'enfant :\n");
        scanf("%u",&nv_personne.nbr_d_enfant);
        if (nv_personne.nbr_d_enfant!=0)
        {
            printf("entrer l'ide des enfant :\n");
        }
        for (i = 0;i < nv_personne.nbr_d_enfant; i++)
        {
            scanf("%d",&ide);
            if (verification_ide(liste,ide,nv_personne.sexe)==1)
            {
                nv_personne.enfant_ide[i]=ide;
        
            }
            else
                i--;
        }
        nv_element->personne=nv_personne;
        nv_element->suivant=liste->premier;
        liste->premier=nv_element;
        
        printf("si vous voulez ajouter autre Personne appui sur (1) :\n");
        scanf("%d",&test);
    } while (test==1);
}


int verification_ide(Liste *liste,int ide,int sexe)
{
    int i;
    Element *element=malloc(sizeof(Element));
    element=liste->premier;
    while((element!=NULL))
    {
        if(element->personne.sexe==sexe)
        {
            for(i=0;i<element->personne.nbr_d_enfant;i++)
            {
                if(ide==element->personne.enfant_ide[i])
                    return 0;
                    
            }
        }

        element=element->suivant;
    }

    return 1;
}
