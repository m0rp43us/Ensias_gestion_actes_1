#include <stdio.h>
#include "structures.h"
#include "Personnes.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
int numero_acte();
void remplir_acte(Element *element,Liste *liste)
{
    char nv_info[CMAX*CMAX];
    int numero=numero_acte();
    unsigned long longueur;
    Element *element_mere=NULL;
    Element *element_pere=NULL;
    if(element!=NULL)
    {
        element_mere=chercher_mere(liste, element->personne.identifiant);
        element_pere=chercher_pere(liste, element->personne.identifiant);
    
    FILE* fichier = NULL;
    fichier = fopen("test.html", "w+");
    if (element_pere==NULL)
    {
        element_pere=malloc(sizeof(Element));
        element_pere->personne.pr_nom[0]='\0';
        element_pere->personne.pr_prenom[0]='\0';
    }
    if (element_mere==NULL)
    {
        element_mere=malloc(sizeof(Element));
        element_mere->personne.pr_nom[0]='\0';
        element_mere->personne.pr_prenom[0]='\0';
    }
    char sexe[6];
    if (element->personne.sexe==0)
    {
    	sexe[0]='H';
    	sexe[1]='o';
    	sexe[2]='m';
    	sexe[3]='m';
    	sexe[4]='e';
    	sexe[5]='\0';
    }
    else
    {
    	sexe[0]='F';
    	sexe[1]='e';
    	sexe[2]='m';
    	sexe[3]='m';
    	sexe[4]='e';
    	sexe[5]='\0';
    }
    fputs("<!DOCTYPE html>\n<html>\n<head>\n<meta charset=""utf-8"" />\n<title>Acte de Naissance</title>\n<style>\ntable{border-collapse:\n collapse;\nmargin : 10px auto auto auto; }\ntd, th /* Mettre une bordure sur les td ET les th */{border: 3px solid black;}\nbody { text-align: center;\n padding: 0;\n margin: 0; }\n</style>\n<BODY><table>\n",fichier);
    printf("enter votre Etat :\n");
    scanf("%s",nv_info);
    fprintf(fichier, "<caption>1-ÉTAT : %s      ",nv_info);
    printf("c'est le service d'etat civil de quelle ville ?\n");
    scanf("%s",nv_info);
    fprintf(fichier, "2-SERVICE DE L’ÉTAT CIVIL DE : %s </caption>\n",nv_info);
    fputs("<thead> <!-- En-tête du tableau --> \n <tr>\n",fichier);
    fprintf(fichier, "<th colspan=""4"">3 ETRAIT DE L’ACTE DE NAISSANCE N° : %d </th>\n",numero);
    fputs("</tr>\n</thead>\n<tfoot> <!-- Pied de tableau -->\n<tr>\n<th>11</th>",fichier);
    //pour la date acctuelle
    time_t secondes;
    struct tm instant;
    time(&secondes);
    instant=*localtime(&secondes);
    //
    fprintf(fichier, "<th colspan=""3"">DATE DE DÉLIVRANCE,SIGNATURE, SCEAU:%d/%d/%d </th>\n", instant.tm_mday, instant.tm_mon+1,instant.tm_year+1900);
    fputs("</tr>\n</tfoot>\n<tbody> <!-- Corps du tableau -->\n<tr>\n<td>4</td>\n",fichier);
    printf("si vous voulez entrer autres enonciations de l'acte veuillez l'entrer :\n");
    scanf("%s",nv_info);
    fprintf(fichier, "<td colspan=""3"">DATE ET LIEU DE NAISSANCE: %d/%d/%d</td> \n </tr> \n <tr> \n     <td>5</td> \n     <td colspan=""3"">NOM: %s</td> \n </tr> \n <tr> \n     <td>6</td> \n     <td colspan=""3"">PRENOM: %s</td> \n </tr> \n <tr> \n     <td>7</td> \n     <td>SEXE: %s</td> \n     <td>8-PERE</td> \n     <td>9-MERE</td> \n </tr> \n <tr> \n     <td>5</td> \n     <td>NOM</td> \n     <td>%s</td> \n     <td>%s</td> \n </tr> \n <tr> \n     <td>6</td> \n     <td>PRENOM</td> \n     <td>%s</td> \n     <td>%s</td> \n </tr> \n <tr> \n 	<td>10</td> \n 	<td colspan=""3"">AUTRES ÉNONCIATIONS DE L’ACTE:%s</td>\n",element->personne.date_de_naissance[0],element->personne.date_de_naissance[1],element->personne.date_de_naissance[2],element->personne.pr_nom,element->personne.pr_prenom,sexe,element_pere->personne.pr_nom,element_mere->personne.pr_nom,element_pere->personne.pr_prenom,element_mere->personne.pr_prenom,nv_info);
    fputs("</tr>\n</tbody>\n</table>\n</html>",fichier);
    printf("entrer le nom sous le quel l'acte sera enregistrer :\n");
    scanf("%s",nv_info);
    longueur=strlen(nv_info);
    nv_info[longueur]='.';
    nv_info[longueur+1]='h';
    nv_info[longueur+2]='t';
    nv_info[longueur+3]='m';
    nv_info[longueur+4]='l';
    nv_info[longueur+5]='\0';
    
    rename("test.html",nv_info);
    fclose(fichier);
    }
    else
        printf("\nCe identifant ne correspond a aucune personne\n");
}
int numero_acte()
{
    int numero;
    FILE* fichier=fopen("Numero", "r");
    if(fichier==NULL)numero=1;
    else {
    fscanf(fichier,"%d",&numero);
        numero+=1;
    }
    fichier=fopen("Numero", "w+");
    fprintf(fichier,"%d",numero);
    fclose(fichier);
    return numero;
}
