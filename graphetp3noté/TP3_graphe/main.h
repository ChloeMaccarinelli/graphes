

/********
STRUCTURE pour cr�er une ListeSommet
*******/

typedef struct ListeSommet ListeSommet;
typedef struct Arete Arete;
typedef struct Adjacents Adjacents;
typedef struct Sommet Sommet;

struct Sommet{
    int num; // Un entier pour identifier un sommet
    int marque; // une marque, utile pour certains algorithmes
    Adjacents *adj; // une liste chaines des ar�tes adjacentes
} ;


struct ListeSommet {
    Sommet *debut; // Pointeur sur le sommet
    ListeSommet *suivant; // Pointeur vers le doublet de type ListeSommet
};


struct Arete {
     Sommet *som1; // une des extr�mit�s de l'ar�teZ
     Sommet *som2; // l'autre extr�mit� de l'ar�te
     int valeur; // Pour les ar�tes �tiquet�es
     int marque; // une marque, utile pour certains algorithmes
     };


struct Adjacents {
     Arete *arete;
     Adjacents *suivant;
     };

void ajouterAreteValuee(Sommet *s1, Sommet *s2, int v);
void ajouterArcValuee(Sommet *s1, Sommet *s2, int v);
void ajouterArete(Sommet *s1, Sommet *s2);
Sommet * chercherSommet(ListeSommet *gr, int j);
void ajouterAreteValueeInt(ListeSommet *gr, int i, int j, int v);
void initMarqueSommet(ListeSommet *gr, int i);
void initMarqueArete(ListeSommet *gr, int i);
Sommet * creerSommet(int n);
Sommet * initSommet(Sommet *s,int n);
void afficherSommet(Sommet *s);
void affichierListeSommet(ListeSommet *file);
ListeSommet * ajouterSommet(ListeSommet *g, Sommet *s);
ListeSommet * ajouterSommetInt(ListeSommet *g, int n);
ListeSommet * GrapheNonOriente(ListeSommet *g);
void GrapheOriente(ListeSommet *g);
ListeSommet * nouveauListeSommet();
ListeSommet * ConstruireGraphe(ListeSommet *g);


/********
STRUCTURE pour pile et file
*******/


typedef struct Maillon Maillon;

struct Maillon {
    Sommet *val;
    Maillon *suiv;
};

void affichierFile(Maillon *file);
Maillon * enfiler(Maillon *file, Sommet *s);
Maillon * defiler(Maillon *file);
Sommet * lastFile(Maillon *file);
Maillon *empiler(Maillon *file, Sommet *s);
Sommet * depiler(Maillon *pile);
void supprimerFile(Maillon *file, Sommet *s);




/********
STRUCTURE & PROCEDURE de connexit�
*******/

typedef struct Composante_Fortement_Connexe CFC;
typedef struct Liste_Sommet_Connexe LSC;

struct Composante_Fortement_Connexe {
  int tailleTab;
  LSC * tabCC;
  CFC *suivant;//rajout�
};

struct Liste_Sommet_Connexe {
  Sommet * tabSommet;
  LSC *suivant;//rajout�
};


int est_Connexe(ListeSommet g);
int est_fortementConnexe(ListeSommet g);
CFC *Composante_fortementConnexe(ListeSommet *g);
void afficher_CFC(CFC* g);
ListeSommet* grapheInverse(ListeSommet *g);
Maillon *parcoursRecursifCFC(Sommet *s, Maillon *pile);






/********
STRUCTURE & PROCEDURE de parcours
*******/
void parcoursLargeur(Sommet *s);
void parcoursProfondeurRecursif(Sommet *s);
void parcoursProfondeurIteratif(Sommet *s);









