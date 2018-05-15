#include "arbre.h"

int main(){
	arbre_t* arbre = NULL;
	creationArbre(&arbre, "arbre.txt");
	printf("%c\n", arbre->val);
	return 0;
}
