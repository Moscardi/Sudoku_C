#include<stdio.h>
#include<stdlib.h>
#include<time.h>
typedef struct location
{
	int posX;
	int posY;
	struct location* next;
}Location;

Location* createLocation();

Location* addLocation(Location* list, int x, int y);

int locationExists(Location* list, int x, int y);

int locationEmpty(Location* list);

void LO_free(Location* local);
