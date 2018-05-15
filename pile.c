/*----------------------------------------------------------------------*/
/*pile.c									                            */
/*      Fichier qui contient l'impl�mentation des fonctions de pile.h	*/
/*----------------------------------------------------------------------*/
#include "pile.h"

/*-------------------------------------------------------------------------*/
/*initialiserPile		Cr�� une pile vide									*/
/*Entr�e : 				taille : taille maximale de la pile					*/
/*Sortie : 				po :  t�te de la pile vide							*/
/*-------------------------------------------------------------------------*/
pile_t* initialiserPile(int taille)
{
	pile_t* po = (pile_t*) malloc(sizeof(pile_t));  //On alloue de la m�moire pour une pile
	if(po)  //Si l'allocation a march�
	{
		po->taille=taille;  //On initialise les valeurs dans la structure
		po->sommet=-1;  //La valeur -1 indique que la pile est vide
		po->base=(type_t*) malloc(taille*sizeof(int));    //On alloue de la m�moire pour les valeurs
		if(!po->base)   //Si l'allocation n'a pas fonctionn�, on lib�re la pile
		{
			free(po);
			po=NULL;
		}
	}
	return po;  //On retourne l'adresse de la pile
}

/*-------------------------------------------------------------------------*/
/*libererPile		Lib�re une pile 										*/
/*Entr�e : 				p: t�te la pile 								    */
/*-------------------------------------------------------------------------*/
void libererPile(pile_t* p)
{
	free(p->base);  //On lib�re la m�moire des valeurs
	free(p);        //On lib�re la pile
	p=NULL;
}

/*-------------------------------------------------------------------------*/
/*estVidePile		d�termine si la pile est vide							*/
/*Entr�e : 				p : t�te de la pile									*/
/*Sortie : 				1 si la pile est vide, 0 sinon						*/
/*-------------------------------------------------------------------------*/
int estVidePile(pile_t* p)
{
	return (p->sommet)==-1;
}

/*-------------------------------------------------------------------------*/
/*empiler		empile l'�l�ment souhait� dans notre pile					*/
/*Entr�e : 				p : t�te de la pile									*/
/*						v : adresse de l'�l�ment � ajouter				    */
/*Sortie : 				code : variable de v�rification pour savoir 		*/
/*									si l'empilement a fonctionn�			*/
/*-------------------------------------------------------------------------*/
int empiler(pile_t* p, type_t v)
{
	int code = 0;
	if(p->sommet<(p->taille)-1) //On teste s'il y a encore de la place dans la pile
	{
		p->sommet++;    //On ajoute un �l�ment
		*((p->base)+(p->sommet)*sizeof(type_t)) = v; //On ins�re la valeur au sommet de la pile
		//Ou p->base[p->sommet]=v;
		code=1; //On indique que l'empilement a fonctionn�
	}
	return code;
}

/*-------------------------------------------------------------------------*/
/*depiler		depile une valeur de la pile								*/
/*Entr�e : 				p : t�te de la pile									*/
/*							code : variable de v�rification pour savoir 	*/
/*									si l'empilement a fonctionn�			*/
/*Sortie : 				adrV : adresse de notre �l�ment d�pil�				*/
/*-------------------------------------------------------------------------*/
type_t depiler(pile_t* p, int* code)
{
	type_t adrV=NULL;
	*code = 0;
	if(!estVidePile(p)) //On teste s'il reste des �l�ments dans la pile � d�piler
	{
		adrV=*((p->base)+(p->sommet)*sizeof(type_t));    //On r�cup�re l'adresse de l'�l�ment au sommet
		//Ou adrV = p->base[p->rang];
		p->sommet--;    //On enl�ve un �l�ment
		*code=1;    //On indique que le d�pilement a fonctionn�
	}
	return adrV;    //On retourne l'adresse de l'�l�ment
}


/*-------------------------------------------------------------------------*/
/*affichePile		Affiche le contenu d'une pile de type int du sommet     */
/*                                vers la base de la pile                    */
/*Entr�e : 				p : t�te de la pile									*/
/*-------------------------------------------------------------------------*/
/*
void affichePile(pile_t* p){
    int t=p->sommet;    //On r�cup�re le nombre d'�l�ments dans la pile
    printf("Contenu de la pile : \n");
    if(!estVidePile(p)) //On indique si la pile est vide ou non
    {
        while(t>=0) //On parcourt tous les �l�ments
        {
            printf("%d\n", *(p->base+t*sizeof(type_t)));
            t--;
        }
    }
    else
    {
        printf("Pile vide\n");
    }
}
*/
