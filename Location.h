

typedef struct location
{
	int posX;
	int posY;
}Location;

Location* createLocation(int x, int y);

void LO_free(Location* local);
