# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include "structures.h"
#include "Personnes.h"
void enregistrer(Liste *liste);
void menu_personne(Liste *liste)
{
  int l,i;
  Personne *p=malloc(sizeof(Personne));
  Element *element=malloc(sizeof(Element));
  liste=lire();
  do{

    printf("\n***********************************************************************");
    printf("\n*TAPEZ :                                                              *");
    printf("\n*    1 : pour ajouter une nouvelle personne.                          *");
    printf("\n*    2 : pour modifier une personne.                                  *");
    printf("\n*    3 : pour supprimer une personne.                                 *");
    printf("\n*    4 : Afficher les personnes.                                      *");
    printf("\n*    5 : Retourner le nom de mère ou père d’une personne              *");
    printf("\n*    6 : Chercher une personne.                                       *");
    printf("\n*    7 : Retourner l’age d’une personne.                              *");
    printf("\n*    8 : Trier la liste des personnes (selon le nom et l’identifiant).*");
    printf("\n*    9 : Imprimer données (Actes).                                    *");
    printf("\n*   10 : pour enregistrer les modifications.                          *");
    printf("\n*    0 : pour sortir.                                                 *");
    printf("\n***********************************************************************");
    printf("\n\n\nVotre choix :");
    scanf("%d",&l);
    system("clear");
    switch(l){
      case 0 : {break;}
      case 1:{//ajouter des personnes
        system("clear");
      	ajouter(liste);
        enregistrer(liste);
        }break;
      case 2:{//modifier un personne
        system("clear");
      	modifier(liste);
        enregistrer(liste);
        }break;
      case 3:{ //supprimer un personne
        system("clear");
        printf("\n*****************************************************");
        printf("\n*                                                   *");
        printf("\n*                    ATTENTION                      *");
        printf("\n*              Voulez-vous vraiment                 *");
        printf("\n*                effectuer cette                    *");
        printf("\n*                   operation?                      *");
        printf("\n*   1 : Confirmer                                   *");
        printf("\n*   0 : Annuler                                     *");
        printf("\n*****************************************************");
        printf("\n");
        scanf("%d",&i);
        system("clear");
        if(i==1){
                supprimer(liste);
          }
        enregistrer(liste);
        }break;
      case 4 :{//afficher des personnes
      	system("clear");
        consulter(liste);
        };break;
      case 5:{//chercher des parents
      	system("clear");
      	int f;
      	printf("\n*****************************************************");
        printf("\n*                                                   *");
        printf("\n*             voulez-vous cherche :                 *");
        printf("\n*   1 : le pere                                     *");
        printf("\n*   2 : la mere                                     *");
        printf("\n*****************************************************\n");
      	scanf("%d",&f);
      	switch(f)
        {
          	case 1:
            {
                printf("saisie l'identifiant de l'enfant : ");
                scanf("%d",&f);
                element=chercher_pere(liste, f);
            	break;
          	}
          	case 2:
          	{
                printf("saisie l'identifiant de l'enfant : ");
                scanf("%d",&f);
            	element=chercher_mere(liste, f);
                break;
            }
        }
          p=&element->personne;
          if(p!=NULL)
          {
              printf("le nom est : %s\n",p->pr_nom);
              printf("le prenom est : %s\n",p->pr_prenom);
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
              printf("le sexe est : %u\n",p->sexe);
              printf("le CIN est : %s\n",p->CIN);
              printf("l'identifiant est : %d\n",p->identifiant);
              printf("le nombre d'enfants est : %d\n",p->nbr_d_enfant);
              for (i = 0; i < p->nbr_d_enfant; i++)
              {
                  printf("   l'ide de l'enfant %d est : %d \n",i+1,p->enfant_ide[i]);
              }
 
          }
          else
              printf("Pas de parents");
          break;}
      case 6://Chercher une personne.
        {
          system("clear");
          printf("\n*****************************************************");
          printf("\n*                                                   *");
          printf("\n*             voulez-vous recherche par:            *");
          printf("\n*   1 : identifiant                                 *");
          printf("\n*   2 : nom                                         *");
          printf("\n*   3 : prenom                                      *");
          printf("\n*   4 : CIN                                         *");
          printf("\n*   0 : Annuler                                     *");
          printf("\n*****************************************************\n");
          scanf("%d",&i);
          switch(i)
          {
            case 1:
            {
              chercher_ide(liste);
              break;
            }
            case 4:
            {
              chercher_CIN(liste);
              break;
            }
            case 2:{
              chercher_nom(liste);
              break;
            }
            case 3:{
          		chercher_prenom(liste);
          		break;
          	}
          	case 0:{break;}
          }
        break;
        }
      case 7://Retourner l’age d’une personne
      {
      	system("clear");
        element=chercher_ide(liste);
        if (element==NULL)
        {
        	printf("la personne n'existe pas\n");
        }
        else
        {age(element->personne);}
        break;
      }
      case 8://Trier la liste des personnes
      {
      	system("clear");
      	int o;
        printf("\n*****************************************************");
        printf("\n*                                                   *");
        printf("\n*      voulez-vous Trier la liste selon:            *");
        printf("\n*   1 : identifiant                                 *");
        printf("\n*   2 : nom                                         *");
        printf("\n*   0 : Annuler                                     *");
        printf("\n*****************************************************");
        printf("\n votre choix : ");
        scanf("%d",&o);
        switch(o)
        {
        	case 0:break;
        	case 1:{
        		trie_ide(liste);
                consulter(liste);
                liste=lire();
        		break;
        	}
        	case 2:{
        		trie_nom(liste);
                consulter(liste);
                liste=lire();
        		break;
        	}
        }
        	break;
        }
      case 9://Imprimer données
        {
        	system("clear");
        	element=chercher_ide(liste);
        	remplir_acte(element,liste);
        	break;
        }
    }

  }while(l!=0);
}

void enregistrer(Liste *liste)
{
    int i;
    printf("\n*********************************************************************");
    printf("\n*                                                                   *");
    printf("\n*  Voulez vous enregistrer les modifications saisie (1):            *");
    printf("\n*   1 : Oui                                                         *");
    printf("\n*   2 : non                                                         *");
    printf("\n*                                                                   *");
    printf("\n*********************************************************************");
    printf("\n votre choix : ");
    scanf("%d",&i);
    if(i==1) Ecrire(liste);
    else liste=lire();

}
