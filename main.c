# include <stdio.h>
# include <stdlib.h>
# include <string.h>
#include <termios.h>
# include "structures.h"
#include "Personnes.h"
#include "Enfant.h"

static struct termios old, new;

/* Initialize new terminal i/o settings */
void initTermios(int echo) 
{
  tcgetattr(0, &old); /* grab old terminal i/o settings */
  new = old; /* make new settings same as old settings */
  new.c_lflag &= ~ICANON; /* disable buffered i/o */
  new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
  tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

/* Restore old terminal i/o settings */
void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}

/* Read 1 character - echo defines echo mode */
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}

/* Read 1 character without echo */
char get(void)
{
  return getch_(0);
}
 

 
char tab_login[50] = {0};
char tab_mdp[50] = {0};


int main()
{

int p=1;
while(p==1){
        printf("\n");
    char c = 0; int i = 0;
    /*Recuperation du Login*/
    printf("Login :");
    scanf("%s", tab_login);

    while(getchar() != '\n');

    /*Recuperation du mot de passe*/
    printf("Mot de passe :");
    while ( (c = get()) != '\n')
    {
           tab_mdp [i] = c ;
           i = i + 1;
           printf("*");
    }
    //printf("\n");

    char user[50]="user";
    char password[50]="123456";

    if(strcmp(user,tab_login)==0)
    {
      if(strcmp(password,tab_mdp)==0)
      {
	system("clear");
        printf("\n*******************************************************************");
        printf("\n*                                                                 *");
        printf("\n*                         BIENVENU                                *");
        printf("\n*                                                                 *");
        printf("\n*****************************************************************\n");
        Liste *liste=malloc(sizeof(Liste));
        lire(liste);
        
		menu(liste);
		return 0;
		  }
      else {system("clear");printf("mot de passe incorrect");}
    }
    else
        if(strcmp(password,tab_mdp)==0){system("clear");printf("nom user inconnu");}
    else {system("clear");printf("informations incorrectes");}

}
	return 0;
}
