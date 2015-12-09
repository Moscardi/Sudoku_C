#include "IntegerList.h"
#include "Location.h"

typedef struct game
{
	int posVazias;
	int** puzzle;
	IntegerList** numLivresLinha;
	IntegerList** numLivresColuna;
	IntegerList** numLivresBloco;
}Puzzle;

Puzzle* createNewPuzzle(void);

int addNumberInPuzzle(Puzzle* jogo, Location* local, int number);

int removeNumberOfPuzzle(Puzzle* jogo, Location* local, int number);

void freePuzzle(Puzzle* jogo);
