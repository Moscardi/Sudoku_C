#include "IntegerList.h"
#include "Location.h"

typedef struct game
{
	int posVazias;
	int** puzzle;
	IntegerList** numLivresLinha;
	IntegerList** numLIvresColuna;
	IntegerList** numLivresBloco;
}Puzzle;

Puzzle* createNewPuzzle(void);

int addNumberInPuzzle(Puzze* jogo, Location* local, int number);

int removeNumberOfPuzzle(Puzze* jogo, Location* local);

void freePuzzle(Puzze* jogo);
