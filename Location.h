#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct location
{
	int posX;
	int posY;
}Location;

Location* createLocation(int x, int y);

void editXLocation(Location* local,int x);

void editYLocation(Location* local,int y);

void freeLocation(Location* local);
