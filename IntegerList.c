#include "IntegerList.h"

IntegerList* createIntegerList(void){
	return NULL;
}

IntegerList* addNumberInIntegerList(IntegerList* list, int number){
	IntegerList* novo = (IntegerList*)malloc(sizeof(IntegerList));
	novo->valor = number;
	novo->proximo = list;
	return novo;
}

int numberExistInIntegerList(IntegerList* list, int number){
	IntegerList* aux = list;
	while(aux != NULL){
		if(aux->valor == number){
			return 1;
		}
		aux = aux->proximo;
	}
	return 0;
}

void freeIntegerList(IntegerList* list){
	IntegerList* aux;
	while(list != NULL){
		aux = list->proximo;
		free(list);
		list = aux;
	}
	list == NULL;
}

IntegerList* removeNumberOfIntegerList(IntegerList* list, int number){
	IntegerList* aux = NULL;
	IntegerList* v = list;	
	while((v != NULL) && (v->valor != number)){
			aux = v;
			v = v->proximo;
		}
		if(v == NULL){return list;}
		if(aux == NULL){list = v->proximo;}
		else{aux->proximo = v->proximo;}
		free(v);
		return list;
}

int IntegerListIsEmpty(IntegerList* list){
	return (list == NULL);
}
