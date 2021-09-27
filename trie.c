
#include "trie.h"
#include "structures.h"
#include "Personnes.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void trie_ide(Liste *liste)
{
    Element *ptr=malloc(sizeof(Element));
    int i ,j=1;
    
    ptr=liste->premier;
    while(ptr != NULL && j==1)
    {
        j=0;
        while( ptr->suivant!=NULL)
        {
            if(ptr->personne.identifiant <  ptr->suivant->personne.identifiant)
            {
                cha(ptr->personne.pr_nom,ptr->suivant->personne.pr_nom);
                cha(ptr->personne.pr_prenom,ptr->suivant->personne.pr_prenom);
                cha(ptr->personne.CIN,ptr->suivant->personne.CIN);
                in(&ptr->personne.identifiant,&ptr->suivant->personne.identifiant);
                in(&ptr->personne.nbr_d_enfant,&ptr->suivant->personne.nbr_d_enfant);
                in(&ptr->personne.sexe,&ptr->suivant->personne.sexe);
                in(&ptr->personne.date_de_naissance[1],&ptr->suivant->personne.date_de_naissance[1]);
                in(&ptr->personne.date_de_naissance[2],&ptr->suivant->personne.date_de_naissance[2]);
                in(&ptr->personne.date_de_naissance[0],&ptr->suivant->personne.date_de_naissance[0]);
                for(i=0;i<10;i++)
                {
                    in(&ptr->personne.enfant_ide[i],&ptr->suivant->personne.enfant_ide[i]);
                }
                j=1;
            }
            ptr = ptr->suivant;
        }
        ptr = liste->premier;
    }
}

void trie_nom(Liste *liste)
{
    
    Element *ptr=malloc(sizeof(Element));
    int i,j=1;
    ptr=liste->premier;
    
    while(ptr != NULL&&j==1)
    {
        j=0;
        
        while(ptr->suivant!=NULL)
        {
            if(strcmp(ptr->personne.pr_nom,ptr->suivant->personne.pr_nom)>0)
            {
                cha(ptr->personne.pr_nom,ptr->suivant->personne.pr_nom);
                cha(ptr->personne.pr_prenom,ptr->suivant->personne.pr_prenom);
                cha(ptr->personne.CIN,ptr->suivant->personne.CIN);
                in(&ptr->personne.identifiant,&ptr->suivant->personne.identifiant);
                in(&ptr->personne.nbr_d_enfant,&ptr->suivant->personne.nbr_d_enfant);
                in(&ptr->personne.sexe,&ptr->suivant->personne.sexe);
                in(&ptr->personne.date_de_naissance[1],&ptr->suivant->personne.date_de_naissance[1]);
                in(&ptr->personne.date_de_naissance[2],&ptr->suivant->personne.date_de_naissance[2]);
                in(&ptr->personne.date_de_naissance[0],&ptr->suivant->personne.date_de_naissance[0]);
                for(i=0;i<10;i++)
                {
                    in(&ptr->personne.enfant_ide[i],&ptr->suivant->personne.enfant_ide[i]);
                }
                j=1;
                
            }
            ptr = ptr->suivant;
        }
        ptr = liste->premier;
    }
    
    
}
void cha(char a[],char b[])
{
    char c[15]="\0";
    strcpy(c,a);
    strcpy(a,b);
    strcpy(b,c);
}
void in(int *a, int *b)
{
    int c=0;
    c=*a;
    *a=*b;
    *b=c;
    
}

