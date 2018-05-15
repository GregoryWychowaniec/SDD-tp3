#include "arbre.h"
#include "pile.h"

int creerCellule(arbre_t** ptr, type_arbre val)
{
	int code = 0;
	*ptr = (arbre_t*) malloc(sizeof(arbre_t));
	if (*ptr) {
		(*ptr)->val = val;
		(*ptr)->lv = NULL;
		(*ptr)->lh = NULL;
		code = 1;
	}
	return code;
}

void creationArbre(arbre_t** arbre, char* nomFichier)
{
	type_arbre tmp;
	arbre_t** prec = arbre;
	arbre_t* cour = NULL;
	FILE* fichier = fopen(nomFichier, "r");
	pile_t* pile = initialiserPile(TAILLE);
	//int type = 2;
	int code;
	if(fichier)
	{
		fscanf(fichier, "%c", &tmp);	//Enlève la première parenthèse
		while(!feof(fichier))
		{
			fscanf(fichier, "%c", &tmp);
			printf("%c\n", tmp);
			if(cour!=NULL)
				printf("%c\n", cour->val);
			switch (tmp)
			{
			case '(':
		  		//type=0;
		  		code = empiler(pile, &cour->lh);
					prec = &cour->lv;
		 	break;
			case ')':
		  		//type=1;
		  		prec = depiler(pile, &code);
		  		if(estVidePile(pile))	//Quand on arrive à la fin de la ligne
		  		{
		  			fscanf(fichier, "%c", &tmp);
		  			fscanf(fichier, "%c", &tmp);
		  			fscanf(fichier, "%c", &tmp);
		  		}
		  	break;
			case ',':
		  		//type=1;
					prec = &cour->lh;
		  	break;
			default:
				creerCellule(&cour, tmp);
				*prec = cour;
				/*
		  		if(type==0)
		  		{
		  			//lv
		  			cour->lv = (type_t*) malloc(sizeof(arbre_t));
		  			cour=cour->lv;
		  			cour->val=tmp;
		  		}
		  		else if(type==1)
		  		{
		  			//lh
		  			cour->lh = (type_t*) malloc(sizeof(arbre_t));
		  			cour=cour->lh;
		  			cour->val=tmp;
		  		}
		  		else
		  		{
		  			//premier caractère
		  			cour = (type_t*) malloc(sizeof(arbre_t));
		  			cour->val=tmp;
		  		}
					*/
		  	break;
			}
		}
	}
	fclose(fichier);
}
