typedef struct _matrice matrice;
struct _matrice
{
    int    taille;
    int    ** matriceAdj;

};

void construiregraphe(matrice *mat);
void initmat(matrice*mat);
void affichegraphe(matrice * mat);
void supprimer_arc(int x,int y,matrice * mat);
void afficher_arc(int x, int y, matrice * mat);
void existe_chemin(int x, int y, matrice * mat);










