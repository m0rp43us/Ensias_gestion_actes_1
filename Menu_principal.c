
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include "structures.h"
#include "Personnes.h"
#include "Enfant.h"

void menu(Liste *liste)
{
    int i;
    do
    {
        printf("\n*******************************************************************");
        printf("\n*                                                                 *");
        printf("\n*                veuillez choisir entre :                         *");
        printf("\n*   1 : Gestion des Personnes                                     *");
        printf("\n*   2 : Gestion des enfants d'une personne                        *");
        printf("\n*   0 : sortir                                                    *");
        printf("\n*******************************************************************\n");
		printf("votre choix :");
        scanf("%d",&i);
        switch(i)
        {
            case 0 :
            {
                break;
            }
            case 2 :
            {
                menu_enfants(liste);
                break;
            }
            case 1 :
            {
                menu_personne(liste);
                break;
            }
        }
    } while (i!=0);
}

