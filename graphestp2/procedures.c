#include "main.h"
#include "procedures.h"
#include "structures.h"
#include <stdio.h>
#include <stdlib.h>


/** procedure pour la pile **/

void init_pile(Pile * tas){
  tas->debut = NULL;
  tas->taille = 0;
}

/* empiler ajouter un élément dans la pile */

int empiler (Pile * tas, char *donnee){
  Element *nouveau_element;
  if ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL)
    return -1;
  if ((nouveau_element->donnee = (char *) malloc (50 * sizeof (char)))
      == NULL)
    return -1;
  strcpy (nouveau_element->donnee, donnee);
  nouveau_element->suivant = tas->debut;
  tas->debut = nouveau_element;
  tas->taille++;
}

/* dépiler enlever un élément de la pile */

int depiler (Pile * tas){
  Element *supp_element;
  if (tas->taille == 0)
    return -1;
  supp_element = tas->debut;
  tas->debut = tas->debut->suivant;
  free (supp_element->donnee);
  free (supp_element);
  tas->taille--;
  return 0;
}

/** procedure pour la file **/

void init_file (File * suite){
  suite->debut = NULL;
  suite->fin = NULL;
  suite->taille = 0;
}

int enfiler (File * suite, Element * courant, char *donnee){
  Element *nouveau_element;
  if ((nouveau_element = (Element *) malloc (sizeof (Element))) == NULL)
    return -1;
  if ((nouveau_element->donnee = (char *) malloc (50 * sizeof (char)))
      == NULL)
    return -1;
  strcpy (nouveau_element->donnee, donnee);

  if(courant == NULL){
    if(suite->taille == 0)
      suite->fin = nouveau_element;
    nouveau_element->suivant = suite->debut;
    suite->debut = nouveau_element;
  }else {
    if(courant->suivant == NULL)
      suite->fin = nouveau_element;
    nouveau_element->suivant = courant->suivant;
    courant->suivant = nouveau_element;
  }
  suite->taille++;
  return 0;
}

int defiler (File * suite){
  Element *supp_element;
  if (suite->taille == 0)
    return -1;
  supp_element = suite->debut;
  suite->debut = suite->debut->suivant;
  free (supp_element->donnee);
  free (supp_element);
  suite->taille--;
  return 0;
}
