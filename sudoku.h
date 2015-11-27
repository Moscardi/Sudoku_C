#include "listas.h"
#include "location.h"

typedef struct puzzle
{
	int posVazias;
	int** puzzle;
	ListaInteiro* numLivresLinha;
	ListaInteiro* numLIvresColuna;
	ListaInteiro* numLivresBloco;
}Puzze;


int GM_addNumerber();
