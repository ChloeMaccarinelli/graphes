#include <stdio.h>
#include <stdlib.h>
#include "graphe.h"



int main()
{
int  nbSommet;
    matrice *mat = (matrice *)malloc(sizeof(matrice));

    construiregraphe(mat);
    affichegraphe(mat);
    initmat(mat);
    affichegraphe(mat);
    produitmatricielle(mat,mat);
        printf("la matrice carree de la matrice est:\n\n");
        affichegraphe(mat);
        int x,y;
        int k=0;
        /*printf("quel arc voulez vous supprimer? \n x:",x);
        scanf("%d",&x);
        printf("\n y:",y);
        scanf("%d",&y);
        supprimer_arc(x,y,mat);
        affichegraphe(mat);
        afficher_arc(x,y,mat);*/
        existe_chemin(x,y,mat);
        nb_chemin(k,mat);
        free(mat);

}
