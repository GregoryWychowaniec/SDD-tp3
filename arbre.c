#include "arbre.h"

arbre_t* creationArbre(char* nomFichier)
{
	char tmp;
	arbre_t* cour = NULL;
	FILE* fichier = fopen(nomFichier, "r");
	pile_t* pile = initialiserPile(TAILLE);
	int type = 2;
	int code;
	if(fichier)
	{
		fscanf(fichier, "%c", &tmp);
		while(!feof(fichier))
		{
			fscanf(fichier, "%c", &tmp);
			printf("%c\n", tmp);
			if(cour!=NULL)
				printf("%c\n", cour->val);
			
			switch (tmp)
			{
			case '(':
		  		type=0;
		  		code = empiler(pile, cour);
		 	break;
			case ')':
		  		type=1;
		  		cour=depiler(pile, &code);
		  		if(estVidePile(pile))
		  		{
		  			fscanf(fichier, "%c", &tmp);
		  			fscanf(fichier, "%c", &tmp);
		  			fscanf(fichier, "%c", &tmp);
		  		}
		  	break;
			case ',':
		  		type=1;
		  	break;
			default:
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
		  	break;
			}
		}
	}
	fclose(fichier);
	return cour;
}
