#include "structures.h"
#include "Personnes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Element* chercher_mere(Liste *liste,int ide)
{
	Element *element=malloc(sizeof(Element));
	int i=0;

	element=liste->premier;
    
        
	while(element!=NULL)
	{
        if(element->personne.sexe==1)
        {
            if(ide==element->personne.enfant_ide[i]) return element;
            else if (i==element->personne.nbr_d_enfant-1)
            {
                i=-1;
                element=element->suivant;
            }
            
            i++;
        }
        else element=element->suivant;

	}
	return NULL;
}
Element* chercher_pere(Liste *liste,int ide)
{
    Element *element=malloc(sizeof(Element));
    int i=0;
    
    element=liste->premier;
    
    
    while(element!=NULL)
    {
        if(element->personne.sexe==0)
        {
            if(ide==element->personne.enfant_ide[i]) return element;
            else if (i==element->personne.nbr_d_enfant-1)
            {
                i=-1;
                element=element->suivant;
            }
            
            i++;
        }
        else element=element->suivant;
        
    }
    return NULL;

}