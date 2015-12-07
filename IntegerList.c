#include "IntegerList.h"

IntegerList* createIntegerList(void){
	return NULL;
}

void addNumberInIntegerList(IntegerList* list, int number){
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
		aux = aux->next;
	}
	return 0;
}

void freeIntegerList(IntegerList* list){
	IntegerList* aux;
	while(list != NULL){
		aux = list->next;
		free(list);
		list = aux;
	}
	list == NULL;
}

int removeNumberOfIntegerList(IntegerList* list, int number){
	if(list != NULL){
		IntegerList* aux;
		if(list->valor == number){
			aux = list;
			list = list->proximo;
			free(aux);
			return 1;
		}
		IntegerList* anterior = list;
		aux = list->proximo;
		while (aux != NULL && aux->valor != number) {
			if(aux->valor == number){
				anterior->proximo = aux->proximo;
				free(aux);
				return 1;
			}
			anterior = aux;
			aux = aux->proximo;
		}
		return 0;
	}
	return 0;
}

int IntegerListIsEmpity(IntegerList* list){
	return (list == NULL);
}
