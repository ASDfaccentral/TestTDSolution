/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/******************************************************************************

                            Traitement avec listes chainée

*******************************************************************************/
/****************************************************************************
1- Donnez les 3 structures de données.

*******************************************************************************/

typedef struct elt1
{
  char nom[10];
  char prenom[10];
  char Tel[10];
  int num;
  int wilaya;
  struct elt1 *svt;
} old_dir;

typedef struct elt3
{
  char nom[10];
  char prenom[10];
  char Tel[10];
  int num;
  struct elt3 *svt;
} contact;

typedef struct elt2
{
  int wilaya;
  contact *liste;
  struct elt2 *svt;
} new_dir;
/****************************************************************************
2- Ecrire une fonction récursive qui permet de créer la liste des wilayas (voir figure).
*******************************************************************************/


new_dir * create_dir (int i)
{
  new_dir *p;
  if (i == 49)
    return (NULL);
  else
    {
      p = (new_dir *) malloc (sizeof (new_dir));
      p->wilaya = i;
      p->liste = NULL;
      i++;
      p->svt = create_dir (i);
      return p;
    }

}
/****************************************************************************
3- Ecrire une fonction récursive qui permet d’ajouter un élément de l’ancien annuaire
vers le nouvel annuaire.
*******************************************************************************/


contact * Insert_contacte(contact * liste, old_dir * L)

{ contact * p;
    if (liste == NULL) { p= (contact *) malloc (sizeof(contact));
                            strcpy(p->nom , L->nom);
                            strcpy (p->prenom , L->prenom);
                            strcpy (p->Tel, L->Tel);
                            p->num = L->num; 
                            p->svt = NULL;
                            return (p);
                            }
                        else{
                              if  (liste->num > L->num) {   p= (contact *) malloc (sizeof(contact));
                                                            strcpy(p->nom , L->nom);
                                                            strcpy (p->prenom , L->prenom);
                                                            strcpy (p->Tel, L->Tel);
                                                            p->num = L->num; 
                                                            p->svt = liste;  
                                                            return (liste);
                                                                }
                                                            
                                                   else  { liste->svt = Insert_contacte(liste->svt, L);
                                                           return (liste);
                                                         }
                                               
                               }    
    
}



void Insert (new_dir *N_L, old_dir * L)
{
    if (N_L->wilaya == L->wilaya) N_L->liste=Insert_contacte(N_L->liste,L);
      else Insert (N_L->svt, L);
}

/****************************************************************************
4- Ecrire une fonction récursive qui permet de transférer tous les contacts de l’ancien
annuaire vers le nouvel annuaire.
*******************************************************************************/


void create ( new_dir *N_L, old_dir * L)
{
  if (L != NULL) {Insert (N_L, L);
                    create (N_L,L->svt);}
  
}

/****************************************************************************
   Fonction qui créer une liste ancienne d'une façon aléatoire
*******************************************************************************/
old_dir * create_old_dir ()
{
    old_dir * L, *p; 
    int i,j;
    L=NULL;
    for (i=1; i<49; i++)
    {
        for (j=5;j>0;j--)
         {
             p=(old_dir *)malloc (sizeof (old_dir)); 
             p->num=j;
             p->wilaya =i;
             strcpy(p->nom, "Omar");
             strcpy (p->prenom, "Khaled");
             strcpy (p->Tel, "05555");
             p->svt=L;
             L=p;
         }
    }
    return (L);
}


/******************************************************************************

                            Traitement avec Arbres

*******************************************************************************/

/****************************************************************************
1- Donnez les nouvelles structures de données
*******************************************************************************/

typedef struct elt4
{
  char nom[10];
  char prenom[10];
  char Tel[10];
  int num;
  struct elt4 *FG;
  struct elt4 *FD;
} contact_ABR;

typedef struct elt5
{
  int wilaya;
  contact_ABR *liste;
  struct elt5 *svt;
} new_dir_ABR;

/****************************************************************************
2- Ecrire une fonction récursive qui permet d’ajouter un élément de l’ancien annuaire
vers le nouvel annuaire (l’annuaire de base et non pas de la solution proposer dans la
partie I). 
*******************************************************************************/



contact_ABR * Insert_contacte_ABR(contact_ABR * liste, old_dir * L)

{ contact_ABR * p;
    if (liste == NULL) { p= (contact_ABR *) malloc (sizeof(contact_ABR));
                            strcpy(p->nom , L->nom);
                            strcpy (p->prenom , L->prenom);
                            strcpy (p->Tel, L->Tel);
                            p->num = L->num; 
                            p->FG = NULL;
                            p->FD = NULL;
                            return (p);
                            }
                        else{ if  (liste->num > L->num) liste->FG = Insert_contacte_ABR(liste->FG, L);
                                                   else  liste->FD = Insert_contacte_ABR(liste->FD,L);
                               return (liste);
                            }
                            
}


void Insert_ABR (new_dir_ABR *N_L, old_dir * L)
{
    if (N_L->wilaya == L->wilaya) N_L->liste=Insert_contacte_ABR(N_L->liste,L);
      else Insert_ABR (N_L->svt, L);
}
/****************************************************************************
Cette fonction est en plus juste pour faire les testes sur la plateforme 
 *******************************************************************************/

void create_ABR ( new_dir_ABR *N_L, old_dir * L)
{
  if (L != NULL) {Insert_ABR (N_L, L);
                    create_ABR (N_L,L->svt);}
  
}


new_dir_ABR * create_dir_ABR (int i)
{
  new_dir_ABR *p;
  if (i == 49)
    return (NULL);
  else
    {
      p = (new_dir_ABR *) malloc (sizeof (new_dir_ABR));
      p->wilaya = i;
      p->liste = NULL;
      i++;
      p->svt = create_dir_ABR (i);
      return p;
    }

}


/****************************************************************************
3- Ecrire une fonction récursive qui permet d’afficher le nouvel annuaire. 
*******************************************************************************/

void affichage (contact_ABR *liste)
{
    if (liste !=NULL) {  affichage(liste->FG);
                         printf ("//%d ",  liste->num);
                         puts(liste->nom);
                         puts(liste->prenom);
                         puts(liste->Tel);
                         affichage(liste->FD);
                         }
}
/******************************************************************************

                            Main

*******************************************************************************/

int
main ()
{
  new_dir *p, *L;
  old_dir *pol, *OL;
  new_dir_ABR *NL,*Np;
  
contact *q;
// créer la liste de base in a random way
OL= create_old_dir();
// creer la nouvelle liste de la partie I vide
L = create_dir (1);
// creer la liste de la partie II vide
  NL= create_dir_ABR(1);
  // inserer tous les élément de l’ancien annuaire vers le nouveau partie II
create_ABR (NL,OL);
// affichage 
  Np = NL;
  while (Np !=NULL)
  {
      printf ("%d ", Np->wilaya);
      affichage(Np->liste);
      Np=Np->svt;
  }
  
 
  
  //puts("fini");
 /* 
 //Affichage ancien annuaire 
  pol= OL;
  while (pol != NULL)
    {
      printf ("//%d , %d ", pol->wilaya, pol->num);
      puts(pol->nom);
      puts(pol->prenom);
      puts(pol->Tel);
      pol = pol->svt;
    }*/
/*  
// inserer tous les élément de l’ancien annuaire vers le nouveau partie I
    create(L,OL);
    
//L = create_dir (1);
// afficher nouveau annuaire partie I 
  p = L;
  while (p != NULL)
    {
      printf ("%d ", p->wilaya);
      q=p->liste;
      while (q!=NULL)
      {
            printf ("//%d ",q->num);
            puts(q->nom);
            puts(q->prenom);
            puts(q->Tel);
            q=q->svt;
      }
      p = p->svt;
    }
  */
  //printf ("Hello World");*/

  return 0;
}
