#include "arbre.h"

int main(){
	arbre_t* arbre = creationArbre("arbre.txt");
	printf("%c\n", arbre->val);
	return 0;
}
