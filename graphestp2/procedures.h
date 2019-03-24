typedef struct ElementListe {
    char *donnee;
    struct ElementListe *suivant;
}Element;

/** structure pour la pile **/


typedef struct Listepile{
  Element *debut;
  int taille;
} Pile;

/** structure pour la file **/

typedef struct Listefile{
  Element *debut;
  Element *fin;
  int taille;
} File;
