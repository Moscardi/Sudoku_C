#include "Location.h"

Location* createLocation(){
	return NULL;
}

Location* addLocation(Location* list, int x, int y){
  Location* novo = (Location*)malloc(sizeof(Location));
  novo->posX = x;
  novo->posY = y;
  novo->next = list;
  return novo;
}

void LO_free(Location* local){
  free(local);
  local = NULL;
}
int locationExists(Location* list, int x, int y){
    Location* aux = list;
	while(aux != NULL){
		if(aux->posX == x && aux->posY == y){
			return 1;
		}
		aux = aux->next;
	}
	return 0;
}
int locationEmpty(Location* list){
    return (list == NULL);
}
