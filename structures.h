
#define CMAX 15
#define nbrMAX 10

/*typedef enum Sexe
{
    homme=1,femme=2
}Sexe;*/

typedef struct Personne
{
    char pr_nom[CMAX];
    char pr_prenom[CMAX];
    int sexe;
    int date_de_naissance[3];
    char CIN[CMAX];
    int identifiant;
    int nbr_d_enfant;
    int enfant_ide[nbrMAX];

}Personne;

typedef struct Element Element;
struct Element
{
    Personne personne;
    Element *suivant;
};

typedef struct Liste
{
    Element *premier;
}Liste;
/*
 typede struct Fin Fin
 {
	Personne *dernier;
 };
 */
/*typedef struct Arbre_famille
{
    int arb_ide_prs;
    struct Arbre_famille *droit;
    struct Arbre_famille *gauche;
}Arbre_famille;*/

void menu(Liste *liste);

void remplir_p(Personne *personne);

Element* chercher_enfants(Liste *liste,int ide);

void afficher_enfants(int ide,Liste *liste);

void modifier_enfants(Personne *personne);

void menu_enfants(Liste *liste);
void ajouter(Liste *liste);
int verification_ide(Liste *liste,int ide,int sexe);

Element* chercher_ide(Liste *liste);
Element* chercher_CIN(Liste *liste);
Element* chercher_nom(Liste *liste);
Element* chercher_prenom(Liste *liste);

void consulter(Liste *liste);
void age(Personne p);

Liste* lire();
void Ecrire(Liste *liste);

Element* chercher_mere(Liste *liste,int ide);
Element* chercher_pere(Liste *liste,int ide);

void supprimer(Liste *liste);

void modifier(Liste *liste);

void remplir_acte(Element *element,Liste *liste);

void trie_ide(Liste *liste);
void trie_nom(Liste *liste);

void menu_personne(Liste *liste);
void enregistrer(Liste *liste);

void cha(char a[],char b[]);
void in(int *a, int *b);



