#include "graphe.h"
#include <stdio.h>
#include <stdlib.h>

/**on construit la structure du graphe**/

void construiregraphe(matrice *mat)
{
    int  i, j;

    printf("nombre de sommets?\n");
    scanf("%d", &mat->taille);

    mat->matriceAdj=(int**)malloc(mat->taille *sizeof(int));

    for (i=0;i<mat->taille; i++)
    {
        mat->matriceAdj[i]=(int*)malloc(mat->taille *sizeof(int));

        for (j=0;j<mat->taille;j++)
        {
          mat->matriceAdj[i][j]=0;

        }
    }
}


/**on initialise les sommets**/

void initmat(matrice*mat)
{
        int i,j,indicesommet;
        for(i=0;i<mat->taille;i++)
        {
            for (j=0;j<mat->taille;j++)
            {
                printf("sommet entre %d et %d? (1 oui, 0 non)",i,j);
                scanf( "%d", &indicesommet);
                mat->matriceAdj[i][j]=indicesommet;
                printf("\n");
            }
        }
}


/**on affiche le graphe**/

void affichegraphe(matrice * mat)
{
    int  i, j;

    for (i=0;i<mat->taille;i++)
    {
        // mat->matriceAdj[i]= (int*)malloc(mat->taille *sizeof(int));

        for (j=0;j<mat->taille;j++)
        {
          printf("%d ",mat->matriceAdj[i][j]);

        }
            printf("\n");
     }

    printf("\n");
}

/** initialisation de la variable nombre de sommets */

int nbSommet;

/** produit matricielle */

int   ** produitmatricielle(int mat1[nbSommet][nbSommet], int mat2[nbSommet][nbSommet])
{
    int matresult[nbSommet][nbSommet];
    int i,j,k;
        for(i=0;i<nbSommet;i++)
        {
            for (j=0;j<nbSommet;j++)
            {
                matresult[i][j]=0;

                for (k=0;k<nbSommet;k++)
                {
                    matresult[i][j]=mat1[i][k]*mat1[k][j];

                }
            }
        }
    return matresult;

}

/** supprimer un arc **/


void supprimer_arc(int x,int y,matrice * mat)
{

        mat->matriceAdj[x][y]=0;


}



void copie_matrice(matrice * m1, matrice * m2)
{
    int i, j;
    m1->taille=m2->taille;
        for(i=0;i<m2->taille;i++)
        {
            for (j=0;j<m2->taille;j++)
            {

                m1->matriceAdj[i][j]=m2->matriceAdj[i][j];

            }
        }
}

/** afficher arc **/

void afficher_arc(int x, int y, matrice * mat)
{

        for(x=0;x<mat->taille;x++)
        {
            for (y=0;y<mat->taille;y++)
            {

                if(mat->matriceAdj[x][y]==1 && mat->matriceAdj[y][x]==1)
                {
                    printf("il existe un arc qui relit le sommet %d et %d \n",x,y);
                }

            }
        }
}



/** existence d'un chemin **/

void existe_chemin(int x, int y, matrice * mat)
{


     for(x=0;x<mat->taille;x++)
        {
            for (y=0;y<mat->taille;y++)
            {

                 if(mat->matriceAdj[x][y]==1 && mat->matriceAdj[y][x]==1)
            {

            printf("il exite un chemin qui relit les deux sommets %d et %d\n",x,y);

            }
            else
            {
                existe_chemin(x+1,y,mat);
                existe_chemin(x,y+1,mat);
            }


            }
        }

}



/** nombre de chemins **/

void nb_chemin(int k, matrice * mat)
{
        k=0;
        int x,y;

     for(x=0;x<mat->taille;x++)
        {
            for (y=0;y<mat->taille;y++)
            {

                 if(mat->matriceAdj[x][y]==1 && mat->matriceAdj[y][x]==1)
            {

            printf("il exite un chemin qui relit les deux sommets %d et %d\n",x,y);
            k=k+1;

            }
            else
            {
                existe_chemin(x+1,y,mat);
                existe_chemin(x,y+1,mat);
                k=k+1;
            }


            }
        }

        printf(" \n il existe %d chemins\n",k);
}








