#include "Location.h"

Location* createLocation(int x, int y){
  Location* novo = (Location*)malloc(sizeof(Location));
  novo->posX = x;
  novo->posY = y;
  return novo;
}

void LO_free(Location* local){
  free(local);
  local = NULL;
}
