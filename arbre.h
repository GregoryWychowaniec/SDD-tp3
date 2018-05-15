#ifndef __ARBRE_H__
#define __ARBRE_H__

#include <stdio.h>
#include <stdlib.h>

#define TAILLE 50

typedef char type_arbre;

typedef struct arbre{
	type_arbre val;
	struct arbre* lv;
	struct arbre* lh;
}arbre_t;

int creerCellule(arbre_t** ptr, type_arbre val);
void creationArbre(arbre_t** arbre, char* nomFichier);

#endif
