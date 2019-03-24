/********************************************************************
*                                                                   *
*       CHAPITRE 9 : 3. FILES                                       *
*                                                                   *
*********************************************************************/
/*
    Pour tester les programmes :
    - faire un projet C console (de préférence vide sous visual studio)
    - copier toute la page dans le fichier C du nouveau projet (écraser tout ce qu'il contient)
    - retirer les commentaires qui encadre le programme que vous voulez tester
    - compiler et lancer le programme
      Remarque : si le programme se lance et quitte immédiatement ajouter
      system("PAUSE"); avant le return 0; de fin de main()
    - remettre les commentaires pour tester un autre programme
*/
/************************************************************
*                                                           *
*       2.2 Implémentation d'une file en dynamique          *
*                                                           *
*************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Structure de données
typedef struct elem{
   int val;
   char s[80];
   struct elem*suiv;
}t_elem;

char* S[]={"A","B","C","D","E","F","G","H","I","J","K","L","M",
           "N","O","P","Q","R","S","T","U","V","W","X","Y","Z"};

typedef struct file{
   t_elem*prem;  // sortie
   t_elem*dern;  // entrée
}t_file;

// File vide, file pleine
int file_vide(t_file*f)
{
   return f->dern==NULL;
}

// Initialisation
t_elem*init_elem(int val, char s[])
{
t_elem*e;
   e=(t_elem*)malloc(sizeof(t_elem));
   e->val=val;
   strcpy(e->s,s);
   e->suiv=NULL;
   return e;
}

t_file*init_file()
{
t_file*f;
   f=(t_file*)malloc(sizeof(t_file));
   f->prem=f->dern=NULL;
   return f;
}

// Enfiler
void enfiler(t_file*f,t_elem*e)
{
   // ajouter en queue (en dern)
   if (file_vide(f))// si file vide
      f->dern=f->prem=e;
   else{ // sinon ajouter à la fin
      f->dern->suiv=e;
      f->dern=e;
   }
}

// Lire tête, lire queue
t_elem* lire_tete(t_file*f)
{
t_elem*e=NULL;
   if (!file_vide(f))
      e=f->prem;
   return e;
}

t_elem* lire_queue(t_file*f)
{
t_elem*e=NULL;
   if (!file_vide(f))
      e=f->dern;
   return e;
}

//Défiler
t_elem*defiler(t_file*f)
{
t_elem*e=NULL;
   if(!file_vide(f)){       // si non vide retirer en tête (en prem)
      if (f->prem==f->dern){// si un seul élément
         e=f->prem;
         f->prem=f->dern=NULL;
      }
      else{                 // si plusieurs
        e=f->prem;
        f->prem=f->prem->suiv;
      }
   }
   return e;
}

// Vider, détruire
void vider_file(t_file*f)
{
t_elem*sup;
   while(!file_vide(f)){
      sup=defiler(f);
      free(sup);
   }
}

void detruire_file(t_file**f)
{
   vider_file(*f);
   free(*f);
   *f=NULL;
}

// Affichage
void affiche_elem(t_elem*e)
{
   if (e!=NULL)
      printf("%d%s",e->val,e->s);
   else
      printf("pas d'element");
   putchar('\n');
}

void affiche_file(t_file*f)
{
t_elem*e;
    e=f->prem;
    if(file_vide(f))
      printf("file vide");
    while(e!=NULL){
      printf("%d%s--",e->val,e->s);
      e=e->suiv;
    }
    putchar('\n');
}

// Test dans le main()
int menu()
{
int res=-1;
   printf(  "1  : enfiler\n"
            "2  : defiler\n"
            "3  : vider file\n"
         );
   scanf("%d",&res);
   rewind(stdin);
   return res;
}

int main()
{
int fin=0,id=0;
t_elem*e;
t_file*f;

   f=init_file();
   while(!fin){

      switch(menu()){

         case 1 :
            e=init_elem(rand()%26,S[(id++)%26]);
            enfiler(f,e);
            break;

         case 2 :
            e=defiler(f);
            affiche_elem(e);
            break;

         case 3 :
            vider_file(f);
            break;

         default : fin=1;
      }
      affiche_file(f);
   }
   detruire_file(&f);
   return 0;
}

