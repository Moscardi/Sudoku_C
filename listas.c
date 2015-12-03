#include "listas.h"

ListaInteiro* LI_createList(void){
	return NULL;
}
void LI_addNumber(ListaInteiro* list, int number){
	ListaInteiro* novo = (ListaInteiro*)malloc(sizeof(ListaInteiro));
	novo->valor = number;
	novo->proximo = list;
	return novo;
}
int LI_NumberExist(ListaInteiro* list, int number){
	ListaInteiro* aux = list;	
	while(aux != NULL){
		if(aux->valor == number){
			LI_free(aux);
			return 1;
		}
		aux = aux->next;
	}
	LI_free(aux);
	return 0;
}
void LI_free(ListaInteiro* list){
	while(list != NULL){
		ListaInteiro* aux = list->next;
		free(list);
		list = aux;
	}
}
int LI_removeNumber(ListaInteiro* list, int number){
	if(list != NULL){	
		ListaInteiro* aux = list->next;
		free(list);
		list = aux;
		LI_free(aux);
		return 1;
	}
	return 0;
}
int LI_isEmpity(ListaInteiro* list){
	return (list == NULL);
}
