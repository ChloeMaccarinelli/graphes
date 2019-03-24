typedef struct ListeAdj ListeAdj;
typedef struct Sommet *Psommet;
typedef struct Arete *Parete;
typedef struct Graphe *Pgraphe;
typedef struct Graphe Graphe;
typedef struct Adjacents Adjacents;
typedef struct Adjacents *Padjacents;

struct Sommet
{
    int num; //entier pour identifier un sommet
    int marque; //utile pour certains algos
    Padjacents adj; //une liste chaines des arretes adjacentes
};

/** la liste des sommets du graphe**/

struct Graphe
{
    Psommet debut;//pointeur sur le sommet d'un graphe
    Pgraphe suivant; //pointeur vers le doublet de type graphe
};

/** les arretes du graphe **/

struct Arete
{
    Psommet som1;//une des extrémités de l'arrete
    Psommet som2;//l'autre extrémité de l'arrête
    int valeur;//pour les arretes etiquetées
    int marque;// utile pour certains algos
};

/** liste des arretes adjacentes **/

struct Adjacents
{
    Parete arete;
    Padjacents suivant;
};













