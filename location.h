

typedef struct location
{
	int posX;
	int posY;
}Location;

int LO_getLocationX(Location* local);

int LO_getLocationY(Location* local);

Location* LO_createLocation(int x, int y);

void LO_addPoxX(Location* local, int x);

void LO_addPoxY(Location* local, int y);

void LO_free(Location* local);