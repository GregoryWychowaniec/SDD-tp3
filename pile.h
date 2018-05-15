/*----------------------------------------------------------------------*/
/*pile.h									                            */
/*      Fichier qui contient la déclaration des fonctions pour la pile	*/
/*          et la déclaration du type de données et de la structure     */
/*----------------------------------------------------------------------*/
#ifndef __PILE_H__
#define __PILE_H__

#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

typedef arbre_t** type_t; //On utilise un type int mais il peut être changé à tout moment (à condition de changer les fonctions d'affichage...)

typedef struct pile{    //Structure de la pile
	type_t* base;   //Adresse de la base
	int     sommet; //Nombre d'éléments dans la pile
	int     taille; //Taille de la pile
} pile_t;

pile_t* initialiserPile(int taille);
void libererPile(pile_t* p0);
int estVidePile(pile_t* p);
int empiler(pile_t* p, type_t v);
type_t depiler(pile_t* p, int* code);
void affichePile(pile_t* p);

#endif
