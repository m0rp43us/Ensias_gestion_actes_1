#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"
#include "Personnes.h"

void age(Personne p)
{
    time_t secondes;
    struct tm instant;
    time(&secondes);
    instant=*localtime(&secondes);
    printf("%d/%d/%d\n", instant.tm_mday, instant.tm_mon+1,instant.tm_year+1900);
    int age,jour,mois,annee;
    jour=p.date_de_naissance[0];
    mois=p.date_de_naissance[1];
    annee=p.date_de_naissance[2];
    age=instant.tm_year+1900;
    printf("votre age est :\n");
    if (mois>instant.tm_mon+1)
    {
    	age=age-annee-1;
    	printf("%d\n",age);
    }
    else if (mois<instant.tm_mon+1)
    {
    	age=age-annee;
    	printf("%d\n",age);
    }
    else
    {
    	if (jour<instant.tm_mday)
    	{
    		age=age-annee;
    		printf("%d\n",age);
    	}
    	else if (jour>instant.tm_mday)
    	{
    		age=age-annee-1;
    		printf("%d\n",age);
    	}
    	else
    	{
      		age=age-annee;
    		printf("%d\n",age);
    		printf("joyeux anniversaire\n");
    	}
    }
}
