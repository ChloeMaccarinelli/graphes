#include <stdlib.h>
#include <stdio.h>

/********
STRUCTURE & PROCEDURE pour créer une ListeSommet
*******/

typedef struct ListeSommet ListeSommet;
typedef struct Arete Arete;
typedef struct Adjacents Adjacents;
typedef struct Sommet Sommet;

struct Sommet{
    int num; // Un entier pour identifier un sommet
    int marque; // une marque, utile pour certains algorithmes
    Adjacents *adj; // une liste chaines des arêtes adjacentes
} ;


struct ListeSommet {
    Sommet *debut; // Pointeur sur le sommet
    ListeSommet *suivant; // Pointeur vers le doublet de type ListeSommet
};


struct Arete {
     Sommet *som1; // une des extrémités de l'arêteZ
     Sommet *som2; // l'autre extrémité de l'arête
     int valeur; // Pour les arêtes étiquetées
     int marque; // une marque, utile pour certains algorithmes
     };


struct Adjacents {
     Arete *arete;
     Adjacents *suivant;
     };



void ajouterAreteValuee(Sommet *s1, Sommet *s2, int v) {
    Arete *a = (Arete *)malloc(sizeof(Arete));
    Adjacents *adj1 = (Adjacents *)malloc(sizeof(Adjacents));
    Adjacents *adj2 = (Adjacents *)malloc(sizeof(Adjacents));
    if (s1==NULL || s2==NULL) return;
    a->som1 = s1;
    a->som2 = s2;
    a->marque = 0;
    a->valeur = v;
    adj1->arete = a;
    adj2->arete = a;
    adj1->suivant = s1->adj;
    adj2->suivant = s2->adj;
    s1->adj = adj1;
    s2->adj = adj2;
}


void ajouterArcValuee(Sommet *s1, Sommet *s2, int v) {
    Arete *a = (Arete *)malloc(sizeof(Arete));
    Adjacents *adj1 = (Adjacents *)malloc(sizeof(Adjacents));
    if (s1==NULL || s2==NULL) return;
    a->som1 = s1;
    a->som2 = s2;
    a->marque = 0;
    a->valeur = v;
    adj1->arete = a;
    adj1->suivant = s1->adj;
    s1->adj = adj1;
}


void ajouterArete(Sommet *s1, Sommet *s2) {
    ajouterAreteValuee(s1, s2, 0);
}


Sommet * chercherSommet(ListeSommet *gr, int j){
// A faire
return NULL;
}


void ajouterAreteValueeInt(ListeSommet *gr, int i, int j, int v) {
    ajouterAreteValuee(chercherSommet(gr, i), chercherSommet(gr, j), v);
}


void initMarqueSommet(ListeSommet *gr, int i) { // initialise toute les arrêtes à i  // a faire
    for (; gr!=NULL; gr = gr->suivant) gr->debut->marque=i;

}


void initMarqueArete(ListeSommet *gr, int i) { // initialise toute les arrêtes à i // a faire
    while (gr != NULL) {
            Adjacents *ladj = gr->debut->adj;
            while (ladj != NULL) {
                    ladj->arete->valeur=i;
                    ladj = ladj->suivant; }
            gr = gr->suivant;
    }

}


Sommet * creerSommet(int n){
    Sommet *s = (Sommet *)malloc(sizeof(struct Sommet));
    s->num = n;
    s->marque = 0;
    s->adj = NULL;
    return s;
}

Sommet * initSommet(Sommet *s,int n){
    s->num = n;
    s->marque = 0;
    s->adj = NULL;
    return s;
}



ListeSommet * ajouterSommet(ListeSommet *g, Sommet *s) {
    ListeSommet *g1 = malloc(sizeof(ListeSommet));
   // affichierListeSommet(g1);
    g1->debut = s;
    g1->suivant = g;
    afficherSommet(g1->debut);
    //affichierListeSommet(g1);
    return g1;
}

ListeSommet * ajouterSommetInt(ListeSommet *g, int n) {
    return ajouterSommet(g, creerSommet(n));
}

void affichierListeSommet(ListeSommet *file) {
 //à faire
 printf("File : ");
 while(file != NULL) {
        //int test = file->debut->num;
        //printf("# %d", test);
        afficherSommet(file->debut);
        file = file->suivant;
 }
        printf("\n");

}

ListeSommet * GrapheNonOriente(ListeSommet *g) {

if(g == NULL ){

   Sommet *s1 = creerSommet(1);
   g = ajouterSommet(g,s1);
   //g->debut = s1;
   //afficherSommet(s1);
   Sommet *s2 = creerSommet(2);
   g = ajouterSommet(g,s2);

   Sommet *s3 = creerSommet(3);
   g = ajouterSommet(g,s3);

   Sommet *s4 = creerSommet(4);
   g = ajouterSommet(g,s4);

   Sommet *s5 = creerSommet(5);
   g = ajouterSommet(g,s5);

   Sommet *s6 = creerSommet(6);
   g = ajouterSommet(g,s6);

   Sommet *s7 = creerSommet(7);
   g = ajouterSommet(g,s7);

   Sommet *s8 = creerSommet(8);
   g = ajouterSommet(g,s8);

   //affichierListeSommet(g);
     ajouterAreteValuee(s1, s3, 12);
     ajouterAreteValuee(s1, s2, 16);

     ajouterAreteValuee(s2, s5, 8);
     ajouterAreteValuee(s2, s4, 8);


     ajouterAreteValuee(s3, s4, 12);

     ajouterAreteValuee(s4, s5, 10);

     ajouterAreteValuee(s5, s7, 7);
     ajouterAreteValuee(s5, s6, 4);


     ajouterAreteValuee(s6, s7, 2);
     ajouterAreteValuee(s7, s8, 8);

}

return g;
}

void GrapheOriente(ListeSommet *g) {

   Sommet *s1 = creerSommet(1);
   g = ajouterSommet(g,s1);


   Sommet *s2 = creerSommet(2);
   g = ajouterSommet(g,s2);

   Sommet *s3 = creerSommet(3);
   g = ajouterSommet(g,s3);

   Sommet *s4 = creerSommet(4);
   g = ajouterSommet(g,s4);

   Sommet *s5 = creerSommet(5);
   g = ajouterSommet(g,s5);

   Sommet *s6 = creerSommet(6);
   g = ajouterSommet(g,s6);

   Sommet *s7 = creerSommet(7);
   g = ajouterSommet(g,s7);

   Sommet *s8 = creerSommet(8);
   g = ajouterSommet(g,s8);

   //g->debut = s4;

     ajouterArcValuee(s1, s2, 1);

     ajouterArcValuee(s2, s5, 1);
     ajouterArcValuee(s2, s3, 1);

     ajouterArcValuee(s3, s7, 1);
     ajouterArcValuee(s3, s4, 1);

     ajouterArcValuee(s4, s8, 1);
     ajouterArcValuee(s4, s3, 1);

     ajouterArcValuee(s5, s6, 1);
     ajouterArcValuee(s5, s1, 1);

     ajouterArcValuee(s6, s7, 1);

     ajouterArcValuee(s7, s6, 1);

     ajouterArcValuee(s8, s7, 1);
     ajouterArcValuee(s8, s4, 1);
}


ListeSommet * nouveauListeSommet() { return NULL; }

void afficherSommet(Sommet *s){
printf("%d ", s->num);
}



ListeSommet * ConstruireGraphe(ListeSommet *g) {
     int i;
     for (i=1; i<=8; i++) {
            g = ajouterSommetInt(g,i);
     }

     ajouterAreteValueeInt(g, 1, 3, 12);
     ajouterAreteValueeInt(g, 1, 2, 16);


     ajouterAreteValueeInt(g, 2, 4, 8);
     ajouterAreteValueeInt(g, 2, 5, 8);


     ajouterAreteValueeInt(g, 3, 4, 12);
     ajouterAreteValueeInt(g, 4, 5, 10);
     ajouterAreteValueeInt(g, 5, 6, 4);
     ajouterAreteValueeInt(g, 5, 7, 7);
     ajouterAreteValueeInt(g, 6, 7, 2);
     ajouterAreteValueeInt(g, 7, 8, 8);
     return g;
}



/********
STRUCTURE & PROCEDURE pour pile et file
*******/


typedef struct Maillon Maillon;

struct Maillon {
    Sommet *val;
    Maillon *suiv;
};


void affichierFile(Maillon *file) {
 //à faire
 printf("File : ");
 while (file != NULL) {

   //     printf("# %d", (file->val).num);
        file = file->suiv;
 }
        printf("\n");

}


Maillon * enfiler(Maillon *file, Sommet *s) {
  // à faire
  Maillon *p = (Maillon *)malloc(sizeof(Maillon));
  p->val = s;
  p->suiv = NULL;
  if (file == NULL) file = p;
  else {
        Maillon *t = file;
        while (t->suiv != NULL) t = t->suiv;
        t->suiv = p;
       }
    return file;
}



Maillon * defiler(Maillon *file) {// à faire
    Maillon *p = (Maillon *)malloc(sizeof(Maillon));
    p = file;
    file = file->suiv;
    free(p);
    return file;
}

Sommet * lastFile(Maillon *file) {// à faire
    return (*file).val;
}

void empiler(Maillon *file, Sommet *s) {
    // à faire
    Maillon *p = (Maillon *)malloc(sizeof(Maillon));
    p->val = s;
    p->suiv = file;
    file = p;
}

Sommet * depiler(Maillon *file) {
    Maillon *p = (Maillon *)malloc(sizeof(Maillon));
    p = file;
    file = file->suiv;
    free(p);
    return file;
}

void supprimerFile(Maillon *file, Sommet *s) {
     Maillon *prec = NULL, *crt = file;
      for ( ; crt != NULL && crt->val != s ; prec=crt, crt=crt->suiv);
      if (prec == NULL) *file = *crt->suiv;
      else prec->suiv=crt->suiv;
      free(crt);
}

/********
STRUCTURE & PROCEDURE de parcours
*******/

void parcoursLargeur(Sommet *s){
    Maillon *file = NULL;
    if (s == NULL) return;
    file = enfiler(file, s);
    //file = lastFile(file, s);
    while (file !=NULL)
        { //affichierFile(file);
         s = file->val;
         file = defiler(file);
         s->marque = 1;
          printf(" %d ", s->num);
          Adjacents *ladj = s->adj;
          while (ladj != NULL) {
                Sommet *t;
                //Sommet *t= (ladj->arete->som1->num==s->num) ? ladj->arete->som2 : ladj->arete->som1;
                if (ladj->arete->som1->num==s->num) {
                      t= ladj->arete->som2;
                }else{
                    t= ladj->arete->som1;
                }
                if (t->marque != 1) file =enfiler(file, t);
                t->marque = 1;
                ladj = ladj->suivant;
                }
        }
}



void parcoursProfondeurRecursif(Sommet *s) { // post visit
    Adjacents *ladj = s->adj;
    if (s->marque == 1) return;
    printf("%d ", s->num);
    s->marque = 1;
    while (ladj != NULL) {
            Sommet *t= (ladj->arete->som1->num==s->num) ? ladj->arete->som2 : ladj->arete->som1;
            parcoursProfondeurRecursif(t);
            ladj = ladj->suivant;
        }
}


/********
STRUCTURE & PROCEDURE de connexité
*******/

typedef struct Composante_Fortement_Connexe CFC;
typedef struct Liste_Sommet_Connexe LSC;

struct Composante_Fortement_Connexe {
  int tailleTab;
  LSC * tabCC;
};

struct Liste_Sommet_Connexe {
  Sommet * tabSommet;
};

int est_Connexe(ListeSommet g){
// à faire
}

int est_fortementConnexe(ListeSommet g){
// à faire
}




/********
STRUCTURE & PROCEDURE BONUS
*******/

void dijkstra(ListeSommet *g, int n){
// à faire point bonus pour CC
}

CFC Composante_fortementConnexe(ListeSommet g){
// à faire
//return;
}

int main(){

Maillon *file = NULL;
ListeSommet *g = nouveauListeSommet();
g= GrapheNonOriente(g);

}


