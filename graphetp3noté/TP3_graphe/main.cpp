#include <stdlib.h>
#include <stdio.h>

#include "main.h"


/********
STRUCTURE & PROCEDURE pour créer une
Sommet
*******/

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


/// rend le sommet dont le numéro est j dans la liste de sommets

Sommet * chercherSommet(ListeSommet *gr, int j){
   while(gr != NULL) { // parcourir la liste
        if (j == gr->debut->num) {
                return gr->debut;
        }
          gr = gr->suivant;
 }
     return NULL;
}


void ajouterAreteValueeInt(ListeSommet *gr, int i, int j, int v) {
    ajouterAreteValuee(chercherSommet(gr, i), chercherSommet(gr, j), v);
}


void initMarqueSommet(ListeSommet *gr, int i) { // initialise toute les arrêtes à i
    for (; gr!=NULL; gr = gr->suivant) gr->debut->marque=i;

}


void initMarqueArete(ListeSommet *gr, int i) { // initialise toute les arrêtes à i
    while (gr != NULL) {
            Adjacents *ladj = gr->debut->adj;
            while (ladj != NULL) {
                    ladj->arete->valeur=i;
                    ladj = ladj->suivant; }
            gr = gr->suivant;
    }

}



Sommet * creerSommet(int n){ //Creer  un sommet dont le numéro est n
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

ListeSommet * ajouterSommet(ListeSommet *g, Sommet *s) { // Ajoute le sommet S en paramètre à la liste des sommets G
    ListeSommet *g1 = (ListeSommet *)malloc(sizeof(ListeSommet));
    g1->debut = s;
    g1->suivant = g;
    return g1;
}

ListeSommet * ajouterSommetInt(ListeSommet *g, int n) { // Créer un sommet dont le numéro est n et ajoute ce sommet à la liste des sommets G

    return ajouterSommet(g, creerSommet(n));
}



/// affiche la liste des sommets présents dans G

void affichierListeSommet(ListeSommet *file) {
 //à faire
 printf("liste sommet : ");
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



void affichierFile(Maillon *file) {
 //à faire
 printf("File : ");
 while (file != NULL) {

   //     printf("# %d", (file->val).num);
        file = file->suiv;
 }
        printf("\n");

}

/// ajoute le sommet s a la file

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


/// rend le sommet à la file

Maillon * defiler(Maillon *file) {// à faire
    Maillon *p = (Maillon *)malloc(sizeof(Maillon));
    p = file;
    file = file->suiv;
    free(p);
    return file;
}

///rend le dernier élément de la file

Sommet *lastFile(Maillon *file)
{
    return (*file).val;
}

/*
Maillon * depiler(Maillon *pile) {// à faire
    Maillon *p = (Maillon *)malloc(sizeof(Maillon));
    p = pile;
    pile = pile->suiv;
    free(p);
    return pile;
}*/

/// ajoute le sommet à la pile

Maillon *empiler(Maillon *pile, Sommet *s) {
    // à faire

    Maillon *p = (Maillon *)malloc(sizeof(Maillon));
  p->val = s;
  p->suiv = pile;
 // if (pile == NULL) *pile = *p;
 pile=p;


}

/// rend le premier sommet de la pile

Sommet * depiler(Maillon *pile) {
     // à faire

      if (pile != NULL)
   {

    Maillon *p=pile;
    pile=pile->suiv;
    return p->val;
   }
     return NULL;


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

/// affiche le parcours en largeur à partir de s

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


/// affiche l'ordre post visit du parcours en profondeur a partir de s

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

/// parcours en profondeur le graphe

void parcoursProfondeurIteratif(Sommet *s) { //  visit
    Maillon *pile = NULL;
    if (s == NULL) return;
    pile = empiler(pile, s);

    while (pile !=NULL)
        {
         s = pile->val;
         /// ici problème avec la pile
         //pile = depiler(pile);
         s->marque = 1;
          printf(" %d ", s->num);
          Adjacents *ladj = s->adj;
          while (ladj != NULL) {;
                Sommet *t;
                if(ladj->arete->som1->num==s->num){
                    t = ladj->arete->som2;

                }else{
                   t=ladj->arete->som1;
                }

                if (t->marque != 1) pile =empiler(pile, t);
                t->marque = 1;
                ladj = ladj->suivant;
                }

        }
}


/********
STRUCTURE & PROCEDURE de connexité
*******/

/// rend 1 si G non orienté est connexe 0 sinon

int est_Connexe(ListeSommet *g)
{
    Adjacents *p;
    Sommet *q;
    ListeSommet *r=g;
    Maillon *pile = NULL;
    pile = empiler(pile, (*g).debut);
    (*(*g).debut).marque= 1;

    while(pile != NULL)
    {
        q=depiler(pile);
        p = (*q).adj;
        while(p != NULL)
        {
            if((*(*(*p).arete).som1).num == (*q).num)
            {
                if((*(*(*p).arete).som2).marque != 1)
                {
                    pile = empiler(pile,(*(*p).arete).som2);
                    (*(*(*p).arete).som2).marque = 1;

                }

            }else
            {
                if((*(*(*p).arete).som1).marque != 1)
                {
                    pile = empiler(pile,(*(*p).arete).som1);
                    (*(*(*p).arete).som1).marque = 1;

                }
            }
            p = (*p).suivant;
        }
    }
    while(r != NULL)
    {
        if((*(*r).debut).marque==0)
        {
            return(0);
        }
        r=(*r).suivant;
    }

    return(1);
}

/// rend 1 si G orienté est fortement connexe 0 sinon

int est_fortementConnexe(ListeSommet *g)
{
    CFC *h;
    h = Composante_fortementConnexe(g);
    afficher_CFC(h);
    if((*h).suivant == NULL)
    {
        return(1);
    }
    return(0);
}






/********
STRUCTURE & PROCEDURE BONUS
*******/

void dijkstra(ListeSommet *g, int n){
// à faire point bonus pour CC
}




/// rend les composantes fortement connexes du graphe orienté

CFC *Composante_fortementConnexe(ListeSommet *g)
{
    CFC *h;
    //CFC *h= malloc(sizeof(CFC));
    (*h).suivant=NULL;
    (*h).tailleTab=0;
    CFC * m=h;
    LSC * n;

    int i=0;
    Adjacents *p;
    Sommet *q = chercherSommet(g, 1);
    Sommet *r=NULL;
    ListeSommet *s;
    Maillon *pile = NULL;
    Maillon *pile2 = NULL;

    pile2 = parcoursRecursifCFC(q, pile2);

    initMarqueArete(g, 0);
    initMarqueSommet(g, 0);

    ListeSommet *g2;
    g2=grapheInverse(g);

    initMarqueArete(g2, 0);
    initMarqueSommet(g2, 0);
    q=depiler(pile2);
    s=g2;
    (*q).marque=1;
    while(s != NULL)
    {
        if((*(*s).debut).num == (*q).num)
        {
            r=(*s).debut;
        }
        s=(*s).suivant;
    }

    pile = empiler(pile,r);
    (*r).marque=1;

    while(pile != NULL)
    {
        if(i==0)
        {

            //(*m).tabCC= malloc(sizeof(LSC*));
            n=(*m).tabCC;
            (*n).suivant=NULL;
        }else
        {
           // (*n).suivant=malloc(sizeof(Sommet*));
            n=(*n).suivant;
            (*n).suivant=NULL;
        }

        i++;
        r=depiler(pile);
        (*n).tabSommet=r;

        p = (*r).adj;

        while(p != NULL)
        {
            if((*(*(*p).arete).som1).num == (*r).num)
            {
                if((*(*(*p).arete).som2).marque != 1)
                {
                    pile = empiler(pile,(*(*p).arete).som2);
                    (*(*(*p).arete).som2).marque = 1;

                }

            }else
            {
                if((*(*(*p).arete).som1).marque != 1)
                {
                    pile = empiler(pile,(*(*p).arete).som1);
                    (*(*(*p).arete).som1).marque = 1;
                }
            }
            p = (*p).suivant;
        }
        if(pile == NULL && pile2 != NULL)
        {
            r = NULL;
            (*m).tailleTab=i;
            i=0;
            q=depiler(pile2);
            s=g2;
            (*q).marque=1;
            while(s != NULL)
            {
                if((*(*s).debut).num == (*q).num)
                {
                    r=(*s).debut;
                }
                s=(*s).suivant;
            }

            while(((*r).marque!= 0) && (pile2 != NULL))
            {
                q=depiler(pile2);
                s=g2;
                (*q).marque=1;
                while(s != NULL)
                {
                    if((*(*s).debut).num == (*q).num)
                    {
                        r=(*s).debut;
                    }
                    s=(*s).suivant;
                }
            }
            if((*r).marque == 0)
            {
                pile = empiler(pile,r);
                (*r).marque=1;
                //(*m).suivant=malloc(sizeof(CFC));
                m=(*m).suivant;
                (*m).suivant=NULL;
            }

        }
    }
    return(h);
}

ListeSommet* grapheInverse(ListeSommet *g) ///rajoutée
{
    ListeSommet *g2 = nouveauListeSommet();
    ListeSommet *q=g;
    ListeSommet *r;
    Sommet *aux1;
    Sommet *aux2;
    Adjacents *p;

    while(q != NULL)
    {
        g2 = ajouterSommet(g2,creerSommet((*(*q).debut).num));

        q =(*q).suivant;
    }


    q=g;
    while(q != NULL)
    {
        p=(*(*q).debut).adj;
        while(p != NULL)
        {
            if((*(*p).arete).marque == 0)
            {
                r=g2;
                while(r != NULL)
                {
                    if((*(*(*p).arete).som1).num == (*(*r).debut).num)
                    {
                        aux1=(*r).debut;
                    }

                    if((*(*(*p).arete).som2).num == (*(*r).debut).num)
                    {
                        aux2=(*r).debut;
                    }
                    r=(*r).suivant;
                }
                ajouterArcValuee(aux2,aux1,(*(*p).arete).valeur);
                (*(*p).arete).marque = 1;
            }
            p=(*p).suivant;
        }
        q=(*q).suivant;
    }

    return (g2);
}

void afficher_CFC(CFC* g) ///rajoutée
{
    CFC *p=g;
    LSC  *q;
    printf("Composantes fortement connexes :\n\n");
    while(p != NULL)
    {
        printf("Taille: %d  Composante: ",(*p).tailleTab);
        q=(*p).tabCC;
        while(q != NULL)
        {
            printf("%d ", (*(*q).tabSommet).num);
            q=(*q).suivant;
        }
        printf("\n");
        p=(*p).suivant;
    }
    printf("\n");
}

Maillon *parcoursRecursifCFC(Sommet *s, Maillon *pile) ///rajoutée
{
    Adjacents *p = (*s).adj;

    if((*s).marque == 0)
    {
        (*s).marque = 1;

        while(p != NULL)
        {
            if((*(*(*p).arete).som1).num == (*s).num)
            {
                pile=parcoursRecursifCFC((*(*p).arete).som2,pile);
            }else
            {
                pile=parcoursRecursifCFC((*(*p).arete).som1,pile);
            }

            p = (*p).suivant;

        }
        pile =empiler(pile, s);
    }
    return(pile);
}






int main(){
 Maillon *file = NULL;

ListeSommet *g = nouveauListeSommet();
//g =  (ListeSommet *)malloc(sizeof(ListeSommet));
//Sommet *s;
g= GrapheNonOriente(g);



//printf("resultats graphe non oriente g\n\n");
GrapheNonOriente(g);
printf("Liste des sommets du graphe:\n\n");
affichierListeSommet(g);
printf("\n\n");


printf("parcours en profondeur g (recursif) : ");
parcoursProfondeurRecursif(chercherSommet(g,1));
printf("\n\n");

/*
printf("\n\n");
printf("parcours en profondeur g (iteratif) : ");
parcoursProfondeurIteratif(chercherSommet(g,1));
printf("\n\n");
*/



printf("parcours en largeur g : \n\n");
parcoursLargeur(chercherSommet(g,1));

printf("\n\n");
parcoursLargeur(g->debut);
if(est_Connexe(g)){
    printf("g est un graphe connexe");
}else{
    printf("g n'est pas un graphe connexe");
}
printf("\n\n");
printf("resultats graphe oriente g2");

ListeSommet *g2 = nouveauListeSommet();
//g = (ListeSommet *)malloc(sizeof(ListeSommet));


printf("\n\n");
GrapheOriente(g2);
affichierListeSommet(g2);

printf("\n\n");
printf("parcours en profondeur g2 (recursif) : \n\n");
parcoursProfondeurRecursif(chercherSommet(g,1));

printf("\n\n");
printf("parcours en profondeur g2 (iteratif) : ");
parcoursProfondeurIteratif(chercherSommet(g,1));


printf("\n\n");
printf("parcours en largeur g2 : \n\n");
parcoursLargeur(chercherSommet(g,1));
printf("\n\n");


printf("\n\n");
if (est_fortementConnexe(g2)){
    printf("g2 est un graphe fortement connexe");
}else{
    printf("g2 n'est pas un graphe fortement connexe");
}
}





