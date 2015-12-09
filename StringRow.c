#include "StringRow.h"

StringRow* createStringRow(void){
  return NULL;
}

void addStringRow(StringRow* row,String* texto){
  if(texto != NULL){
    StringRow* novo = (StringRow*)malloc(sizeof(StringRow));
    novo->string = texto;
    novo->proximo = NULL;
    if(row == NULL){
      row = texto;
      return;
    }
    StringRow* aux = row;
    while (aux->proximo != NULL) {
      aux = aux->proximo;
    }
    aux->proximo = novo;
  }
}

int stringRowExist(StringRow* row, String* texto){
  StringRow* aux = row;
  while (aux != NULL && compareStringWithString(aux->string, texto) != 1) {
    aux = aux->proximo;
  }
  if(aux == NULL){
    return 0;
  }
  return 1;
}

void freeStringRow(StringRow* row){
    StringRow* aux;
    while (row != NULL) {
      aux = row;
      row = row->proximo;
      freeString(aux->string);
      free(aux);
    }
}

String* removeStringOfRow(StringRow* row){
  String* retorno = row->string;
  StringRow* aux = row;
  row = row->proximo;
  free(aux);
  return retorno;
}

int stringRowIsEmpty(StringRow* row){
  return (row == NULL);
}
