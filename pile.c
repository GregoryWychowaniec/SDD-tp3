/*----------------------------------------------------------------------*/
/*pile.c									                            */
/*      Fichier qui contient l'implémentation des fonctions de pile.h	*/
/*----------------------------------------------------------------------*/
#include "pile.h"

/*-------------------------------------------------------------------------*/
/*initialiserPile		Créé une pile vide									*/
/*Entrée : 				taille : taille maximale de la pile					*/
/*Sortie : 				po :  tête de la pile vide							*/
/*-------------------------------------------------------------------------*/
pile_t* initialiserPile(int taille)
{
	pile_t* po = (pile_t*) malloc(sizeof(pile_t));  //On alloue de la mémoire pour une pile
	if(po)  //Si l'allocation a marché
	{
		po->taille=taille;  //On initialise les valeurs dans la structure
		po->sommet=-1;  //La valeur -1 indique que la pile est vide
		po->base=(type_t*) malloc(taille*sizeof(type_t)*sizeof(type_t));    //On alloue de la mémoire pour les valeurs
		if(!po->base)   //Si l'allocation n'a pas fonctionné, on libère la pile
		{
			free(po);
			po=NULL;
		}
	}
	return po;  //On retourne l'adresse de la pile
}

/*-------------------------------------------------------------------------*/
/*libererPile		Libère une pile 										*/
/*Entrée : 				p: tête la pile 								    */
/*-------------------------------------------------------------------------*/
void libererPile(pile_t* p)
{
	free(p->base);  //On libère la mémoire des valeurs
	free(p);        //On libère la pile
	p=NULL;
}

/*-------------------------------------------------------------------------*/
/*estVidePile		détermine si la pile est vide							*/
/*Entrée : 				p : tête de la pile									*/
/*Sortie : 				1 si la pile est vide, 0 sinon						*/
/*-------------------------------------------------------------------------*/
int estVidePile(pile_t* p)
{
	return (p->sommet)==-1;
}

/*-------------------------------------------------------------------------*/
/*empiler		empile l'élément souhaité dans notre pile					*/
/*Entrée : 				p : tête de la pile									*/
/*						v : adresse de l'élément à ajouter				    */
/*Sortie : 				code : variable de vérification pour savoir 		*/
/*									si l'empilement a fonctionné			*/
/*-------------------------------------------------------------------------*/
int empiler(pile_t* p, type_t* v)
{
	int code = 0;
	if(p->sommet<(p->taille)-1) //On teste s'il y a encore de la place dans la pile
	{
		p->sommet++;    //On ajoute un élément
		*((p->base)+(p->sommet)*sizeof(type_t))=*v; //On insère la valeur au sommet de la pile
		code=1; //On indique que l'empilement a fonctionné
	}
	return code;
}

/*-------------------------------------------------------------------------*/
/*depiler		depile une valeur de la pile								*/
/*Entrée : 				p : tête de la pile									*/
/*							code : variable de vérification pour savoir 	*/
/*									si l'empilement a fonctionné			*/
/*Sortie : 				adrV : adresse de notre élément dépilé				*/
/*-------------------------------------------------------------------------*/
type_t* depiler(pile_t* p, int* code)
{
	type_t* adrV=NULL;
	*code = 0;
	if(!estVidePile(p)) //On teste s'il reste des éléments dans la pile à dépiler
	{
		adrV=((p->base)+(p->sommet)*sizeof(type_t));    //On récupère l'adresse de l'élément au sommet
		p->sommet--;    //On enlève un élément
		*code=1;    //On indique que le dépilement a fonctionné
	}
	return adrV;    //On retourne l'adresse de l'élément
}


/*-------------------------------------------------------------------------*/
/*affichePile		Affiche le contenu d'une pile de type int du sommet     */
/*                                vers la base de la pile                    */
/*Entrée : 				p : tête de la pile									*/
/*-------------------------------------------------------------------------*/
/*
void affichePile(pile_t* p){
    int t=p->sommet;    //On récupère le nombre d'éléments dans la pile
    printf("Contenu de la pile : \n");
    if(!estVidePile(p)) //On indique si la pile est vide ou non
    {
        while(t>=0) //On parcourt tous les éléments
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
