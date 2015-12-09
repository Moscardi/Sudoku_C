#include "Location.h"

Location* createLocation(int x, int y){
    Location* novo = (Location*)malloc(sizeof(Location));
    novo->posX = x;
    novo->posY = y;
    return novo;
}

void editXLocation(Location* local,int x){
    local->posX = x;
}

void editYLocation(Location* local,int y){
    local->posY = y;
}

void freeLocation(Location* local){
    free(local);
}
