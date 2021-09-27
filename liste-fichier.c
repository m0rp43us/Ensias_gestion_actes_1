#include "structures.h"
#include "Personnes.h"
#include <stdio.h>
#include <stdlib.h>
void trie_ide(Liste *liste);
Liste* lire()
{
    Liste *liste=malloc(sizeof(*liste));
    liste->premier=NULL;
    FILE * fichier;
    Element *element=malloc(sizeof(*element));
    fichier=fopen("registre","r");
    if(fichier!=NULL){
    while(fread(&element->personne,sizeof(Personne),1,fichier)!= 0)
    {
        element->suivant=liste->premier;
        liste->premier=element;
        element=malloc(sizeof(*element));
    }
    fclose(fichier);
    }
    trie_ide(liste);
    return liste;
}
void Ecrire(Liste *liste)
{
    FILE * fichier=NULL;
    fichier=fopen("registre","w+");
    Element *element=malloc(sizeof(Element));
    element=liste->premier;
    while(element!= NULL)
    {
        fwrite(&element->personne,sizeof(Personne),1,fichier);
        element=element->suivant;
    }
    fclose(fichier);
}
